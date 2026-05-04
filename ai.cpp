#include "ai.h"
#include "ui_AI.h" // 包含生成的 UI 头文件

AI::AI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 令窗口取消系统自带的边框
    this->setWindowFlag(Qt::FramelessWindowHint);
    ui->AI_listWidget->addItem("你好！我是你的专属音乐AI助手。");

    ui->RecommendPlay_pushButton->setEnabled(false);

    networkManager = new QNetworkAccessManager(this);

    // 连接网络回复信号
    connect(networkManager, &QNetworkAccessManager::finished, this, &AI::handleDeepSeekReply);
    ui->AI_listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel); // 平滑滚动
    ui->AI_listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

AI::~AI()
{
    delete ui;
}

void AI::setHistorySongs(const QStringList &songs) //获取歌单
{
    m_historySongs = songs;
}

void AI::on_Recommend_pushButton_clicked() //点击推荐按钮
{

    emit requestMusicSearch();
    if (m_historySongs.isEmpty()) {
        appendMessage("system", "数据库中暂无播放历史。");
        return;
    }

    // 构造发给DeepSeek的内容
    QString songListStr = m_historySongs.join("、");
    QString prompt = QString("我最近听了以下歌曲：%1。请根据这些歌的风格，为我推荐5首类似的歌曲。").arg(songListStr);
    qDebug()<<songListStr;
    appendMessage("user", "（已发送播放记录进行推荐）");
    ui->Recommend_pushButton->setEnabled(false); // 发送中，禁用按钮
    ui->RecommendPlay_pushButton->setEnabled(false);

    // 构造JSON请求体
    QJsonObject root;
    root.insert("model", "deepseek-chat");
    QJsonArray messages;
    QJsonObject msg;
    msg.insert("role", "user");
    msg.insert("content", prompt);
    messages.append(msg);
    root.insert("messages", messages);
    root.insert("stream", false);

    // 构造 Request
    QNetworkRequest request(QUrl("https://api.deepseek.com/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg("sk-4bd0ffe4338144789fe14a255039232f").toUtf8());

    // 发送 POST
    networkManager->post(request, QJsonDocument(root).toJson());
}

void AI::handleDeepSeekReply(QNetworkReply *reply)  // 处理服务器回复
{
    ui->Recommend_pushButton->setEnabled(true);

    qDebug() << "Status Code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Error:" << reply->errorString();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);

        if (doc.isNull()) {
            appendMessage("system", "解析失败：返回的不是有效的JSON。");
            return;
        }

        QJsonObject root = doc.object();

        // 精准匹配路径：choices -> [0] -> message -> content
        if (root.contains("choices") && root["choices"].isArray())
        {
            QJsonArray choices = root["choices"].toArray();
            if (!choices.isEmpty())
            {
                QJsonObject choiceObj = choices.at(0).toObject();
                QJsonObject messageObj = choiceObj["message"].toObject();
                QString aiResponse = messageObj["content"].toString();

                if (!aiResponse.isEmpty())
                {
                    // 成功拿到 AI 的推荐文本
                    appendMessage("assistant", aiResponse);

                    // --- 获取歌曲名文本 ---
                    QStringList recommendedSongs;
                    // 正则表达式：匹配 行首 + 数字 + 点 + 空格 + 《歌名》
                    QRegularExpression re("(?m)^\\d+\\.\\s*\\*?\\*?《(.*?)》"); // 正则表达式匹配歌曲名
                    QRegularExpressionMatchIterator i = re.globalMatch(aiResponse);
                    while (i.hasNext())
                    {
                        QRegularExpressionMatch match = i.next();
                        recommendedSongs << match.captured(1);
                        if(recommendedSongs.size() >= 5) break; // 只取前5首
                    }

                    if(!recommendedSongs.isEmpty())
                    {
                        qDebug()<<recommendedSongs;

                        m_RecommendedSongs=recommendedSongs;

                        ui->RecommendPlay_pushButton->setEnabled(true);
                        //emit recommendSongsReady(recommendedSongs); // 发送给主窗口
                    }
                }
                else
                {
                    appendMessage("system", "AI 回复内容为空。");
                }
            }
        }
    } else {
        appendMessage("system", "API 请求失败：" + reply->errorString());
    }
    reply->deleteLater();
}

void AI::appendMessage(QString role, QString content)  // 将对话添加到 ListWidget
{
    QListWidgetItem *item = new QListWidgetItem();
    ui->AI_listWidget->setWordWrap(true); // 开启自动换行


    if (role == "user") {
        item->setTextAlignment(Qt::AlignRight);
        item->setForeground(Qt::blue);
        item->setText("我: " + content); // 进行区分
    } else if (role == "assistant") {
        item->setTextAlignment(Qt::AlignLeft);
        item->setForeground(Qt::darkGreen);
        item->setText("AI助手: " + content);
    } else {
        item->setForeground(Qt::red);
        item->setText("系统: " + content);
    }

    ui->AI_listWidget->doItemsLayout();
    ui->AI_listWidget->addItem(item); //将推荐的音乐显示出来

}

void AI::on_RecommendPlay_pushButton_clicked() // 点击播放
{
    if (m_RecommendedSongs.isEmpty()) return;

    // 弹出询问对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "播放确认", "是否将这5首推荐歌曲加入到下一首播放列表？",
                                  QMessageBox::Yes | QMessageBox::No);

    // 判断用户选择
    if (reply == QMessageBox::Yes)
    {
        // 用户选择是
        emit recommendSongsReady(m_RecommendedSongs);

        // 在AI对话框中显示“用户”身份的提示信息
        appendMessage("user", "已添加5首歌曲至下一首播放列表");

        // 清空暂存列表并重新禁用按钮
        m_RecommendedSongs.clear();
        ui->RecommendPlay_pushButton->setEnabled(false);

        qDebug() << "用户确认：已加入播放列表";
    }
    else
    {
        // 用户选择否
        qDebug() << "用户取消了添加推荐歌曲";
    }
}

void AI::on_Aiclose_pushButton_clicked()
{
    this->hide();
}

