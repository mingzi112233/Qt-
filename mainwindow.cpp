#include "mainwindow.h"
#include "ui_mainwindow.h"

#define cout qDebug();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    login = new Login(this);

    ui->setupUi(this);
    ui->centralwidget->installEventFilter(this); // 给整个中心部件安装过滤器，它会监控其下所有子控件（按钮等）的事件
    ui->FindMusiclistWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    qApp->installEventFilter(this);

    //ai推荐窗口设置
    isAiChatVisible = false;
    aiWindow = new AI(this);
    aiWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    aiWindow->hide();
    networkManager = new QNetworkAccessManager(this);

    //end


    //收藏音乐窗口设置
    collectWindow = new Collect_Music(this);
    aiWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    aiWindow->hide();

    connect(this, &MainWindow::SetCollectText, collectWindow, &Collect_Music::handlecollectTextlabel);

    //end

    player = new QMediaPlayer(this);
    mouseClike = 0;
    PlayMode=1;
    rowMax=0;
    HistoryRowMax=0;
    isHistoryPlay=false;

    ui->ModeButton->setIcon(QIcon(":/png/button/order.png"));  //初始化播放模式图标

    connect(&m_cTimer, &QTimer::timeout, this, &MainWindow::slotTimerTimeOut);
    connect(this, &MainWindow::firstClicke, this, &MainWindow::clicke);
    connect(aiWindow, &AI::requestMusicSearch, this, &MainWindow::Main_Historical_playlist);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleDeepSeekReply);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::handleMediaStatusChanged);

    connect(ui->FindMusiclistWidget, &QListWidget::customContextMenuRequested, this, &MainWindow::showSearchContextMenu);
    connect(login, &Login::loginSuccess, this, &MainWindow::handleLoginSuccess);

    connect(this, &MainWindow::updateList, collectWindow, &Collect_Music::updateList);
    connect(collectWindow, &Collect_Music::PlayCollectMusic, this, &MainWindow::downloadPlayer);
    connect(collectWindow, &Collect_Music::ReadHistoryList, this, &MainWindow::ReadHistoryList);


    this->setWindowFlag(Qt::FramelessWindowHint);
    //ui->FindMusiclistWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    musicPlay = false;

    if(QSqlDatabase::contains("sql_default_connection"))
    {
        db = QSqlDatabase::database("sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("1433223");
        db.setDatabaseName("info");

        if(!db.open()) //数据库打开失败
        {
            QMessageBox::warning(this,"警告",QString("Open Data Error:%1").arg(db.lastError().text()));
        }

        musicoutput = new QAudioOutput(this);
        player->setAudioOutput(musicoutput);
        musicoutput->setVolume(1.0);

        connect(player, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
            ui->ProgresshorizontalSlider->setMaximum(duration);
        });

        // 播放时进度条跟着走
        connect(player, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
            // 防止拖动进度条时发生冲突
            if (!ui->ProgresshorizontalSlider->isSliderDown()) {
                ui->ProgresshorizontalSlider->setValue(position);
            }
        });

        connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::updateDuration);
        connect(ui->FindMusiclistWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::GetCurrentRow);

        QAction *actionbackgrouptoDefault = new QAction(QIcon(":/png/backgroud/backgroud1.webp"),"Default");
        connect(actionbackgrouptoDefault, &QAction::triggered, this, &MainWindow::backgrouptoDefault);

        menuchangeSkin = new QMenu(this);
        menuchangeSkin->addAction(actionbackgrouptoDefault);

        backgrouptoDefault();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) // 过滤事件
{
    // 检查是否是鼠标按下事件
    if (!IsLogin && event->type() == QEvent::MouseButtonPress) {

        QPushButton *btn = qobject_cast<QPushButton*>(watched);
        if(btn)
        {
            if(btn == ui->Login_Button || btn == ui->close_pushButton)
            {
                return QMainWindow::eventFilter(watched, event);
            }
            if (ui->centralwidget->isAncestorOf(btn))
            {

                // 使用静态方法弹出，并立即返回 true
                QMessageBox::information(this, "提示", "请先登录！");

                // 返回 true 表示你已经处理了这个事件，
                // 停止事件继续传递，这样就不会弹出第二次了。
                return true;
            }
        }
    }

    // 其他情况交给系统默认处理
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::on_Login_Button_clicked() //登录按钮
{
    bool isDone = false;

    while (!isDone)
    {
        // exec() 以模态显示，禁用主界面控件，无法点击
        int res = login->exec();

        if (res == QDialog::Accepted)
        {
            // 登录成功
            QMessageBox::information(this, "提示", "登录成功！");

            emit updateList();
            ui->HistoryMusiclistWidget->clear();
            ReadHistoryList();  //查询历史数据表中的插入歌曲数据

            this->IsLogin = true; // 假设你有这个变量记录登录状态
            isDone = true;
        }
        else if (res == 10)
        {
            // 点击注册按钮
            Register regDlg(this); // 同样设置 MainWindow 为父窗口
            int regRes = regDlg.exec(); // 模态显示注册界面，MainWindow依然不可点击

            if (regRes == QDialog::Accepted)
            {
                // 注册成功，回到循环开头再次显示登录界面
                continue;
            }
            else
            {
                // 注册取消，回到循环开头再次显示登录界面
                continue;
            }
        }
        else if (res == 20)
        {
            ResetPwd resetWindow(this);
            resetWindow.exec();
        }
        else
        {
            // 关闭了对话框
            isDone = true;
        }
    }
}

void MainWindow::on_close_pushButton_clicked() //右上角关闭窗口
{
    this->close();
}

void MainWindow::ReadHistoryList() //读取历史播放记录列表
{
    ui->HistoryMusiclistWidget->clear();
    QSqlQuery query;

    query.prepare("SELECT * FROM historylist WHERE username = ? ORDER BY id DESC");
    query.addBindValue(NowUser);
    if(!query.exec())
    {
        QMessageBox::warning(this,"警告",QString("Select historylist Error:%1").arg(db.lastError().text()));
    }

    HistoryRowMax=0;
    while(query.next())
    {
        QString songname, singername, hash;
        QSqlRecord rec = query.record();
        int ablumkey = rec.indexOf("songname");
        int hashkey = rec.indexOf("singername");

        songname = query.value(ablumkey).toString();
        singername = query.value(hashkey).toString();
        hash = query.value("hash").toString();

        QListWidgetItem *item = new QListWidgetItem(songname + " - " + singername);

        item->setData(Qt::UserRole, hash);

        ui->HistoryMusiclistWidget->addItem(item);
        HistoryRowMax++;
    }
}

void MainWindow::showSearchContextMenu(const QPoint &pos) //右击搜索列表歌曲
{
    QListWidgetItem *item = ui->FindMusiclistWidget->itemAt(pos);

    // 如果点击的是空白处，则不弹出菜单
    if (!item)
        return;

    // 创建菜单对象
    QMenu menu(this);

    row = ui->FindMusiclistWidget->currentRow()+1;

    // 添加菜单项
    QAction *favAction = new QAction(QIcon(":/png/button/love.png"), "收藏该歌曲", this);
    menu.addAction(favAction);

    // 阻塞代码，直到用户点击了某个选项或关闭了菜单
    QAction *selectedAction = menu.exec(ui->FindMusiclistWidget->mapToGlobal(pos));

    // 处理用户的点击选择
    if (selectedAction == favAction) {
        // 执行收藏逻辑
        handleFavoriteLogic(item);
    }
}

void MainWindow::handleFavoriteLogic(QListWidgetItem *item) //右击搜索歌曲列表菜单
{
    QSqlQuery query;
    query.prepare("SELECT songname, singername, hash FROM searchlist WHERE id = ?");
    query.addBindValue(row);

    if (!query.exec() || !query.next())
    {
        qDebug() << "获取搜索列表数据失败";
        return;
    }

    QString songname = query.value("songname").toString();
    QString singername = query.value("singername").toString();
    QString hash = query.value("hash").toString();

    //插入到收藏列表数据库中
    query.prepare("SELECT * FROM collectlist WHERE user = ? AND songname = ? AND singername = ?"); //判断是否存在
    query.addBindValue(NowUser);
    query.addBindValue(songname);
    query.addBindValue(singername);
    query.exec();

    if(!query.next()) // 如果不存在则插入
    {
        query.prepare("INSERT INTO collectlist (username, songname, singername, hash) VALUES (?, ?, ?, ?)");
        query.addBindValue(NowUser);
        query.addBindValue(songname);
        query.addBindValue(singername);
        query.addBindValue(hash);

        if(!query.exec())
        {
            qDebug() << "插入历史记录失败：" << query.lastError().text();
        }
        else
        {
            emit updateList(); //成功收藏音乐，刷新收藏界面
        }
    }
    else
        QMessageBox::information(this, "", QString("已收藏过该音乐"));
}

void MainWindow::handleLoginSuccess(QString username) //接受用户名
{
    NowUser = username;
    User=NowUser;
    emit SetCollectText(NowUser);
}

void MainWindow::on_StopButton_clicked() //暂停/播放按钮
{
    if(musicPlay == false)
    {
        musicPlay = true;
        player->play();
        ui->StopButton->setIcon(QIcon(":/png/button/play.png"));
        ui->StopButton->setIconSize(QSize(ui->StopButton->width(),ui->StopButton->height()));
    }
    else
    {
        musicPlay = false;
        player->pause();
        ui->StopButton->setIcon(QIcon(":/png/button/stop.png"));
        ui->StopButton->setIconSize(QSize(ui->StopButton->width(),ui->StopButton->height()));
    }
}

void MainWindow::on_ModeButton_clicked() //切换模式
{
    /*
        模式1是顺序播放
        模式2是单曲循环
    */
    if(PlayMode == 1)  //切换循环播放
    {
        PlayMode = 2;
        ui->ModeButton->setIcon(QIcon(":/png/button/cycle.png"));
    }
    else if(PlayMode == 2)  //切换顺序播放
    {
        PlayMode = 1;
        ui->ModeButton->setIcon(QIcon(":/png/button/order.png"));
    }
}

void MainWindow::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)  //音乐播放结束
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        if(PlayMode == 1) //顺序播放
        {
            on_NextButton_clicked();
        }
        if(PlayMode == 2) //循环播放
        {
            player->stop();
            player->play();
        }
    }
}

void MainWindow::on_prevButton_clicked() //上一首
{
    if(isHistoryPlay==true || isCollectPlay==true)
    {
        QMessageBox::warning(this,"sorry","历史记录列表不支持该模式");
        ui->StopButton->setIcon(QIcon(":/png/button/stop.png"));
        player->stop();
        musicPlay = false;
        return;
    }
    row--;
    if(row == 0)
        row = rowMax;
    qDebug()<<"\nrow:"<<row;
    playFindMusic();
}

void MainWindow::on_NextButton_clicked() //下一首
{
    if(isHistoryPlay==true || isCollectPlay==true)
    {
        QMessageBox::warning(this,"sorry","该列表不支持该模式");
        ui->StopButton->setIcon(QIcon(":/png/button/stop.png"));
        player->stop();
        musicPlay = false;
        return;
    }
    row++;
    row%=rowMax;
    qDebug()<<"\nrow:"<<row;
    playFindMusic();
}

void MainWindow::on_volumehorizontalSlider_valueChanged(int value) //调节音量
{
    musicoutput->setVolume(1.0*value/ui->volumehorizontalSlider->maximum());
    qDebug()<<musicoutput->volume();
    ui->label_6->setText(QString("%1").arg(musicoutput->volume()*100));
}


void MainWindow::on_ProgresshorizontalSlider_valueChanged(int value) //改变进度条
{
    if (ui->ProgresshorizontalSlider->isSliderDown()) {
        player->setPosition(value);
    }
}

void MainWindow::updateDuration(qint64 value) //更新播放的进度和显示的时间
{
    if (!ui->ProgresshorizontalSlider->isSliderDown()) {
        ui->ProgresshorizontalSlider->blockSignals(true);
        ui->ProgresshorizontalSlider->setValue(value);
        ui->ProgresshorizontalSlider->blockSignals(false);
    }

    int totalSeconds = value / 1000;
    int seconds = totalSeconds % 60;
    int minutes = (totalSeconds / 60) % 60;

    QString timeString = QString("%1:%2")
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    ui->TotalTimeLabel->setText(timeString);
}

void MainWindow::GetCurrentRow()  //双击搜索列表获取row
{
    row = ui->FindMusiclistWidget->currentRow();
    row++;
    isHistoryPlay=false;
    isCollectPlay=false;
    playFindMusic();
}

void MainWindow::playFindMusic() //根据row进行播放搜索
{
    QSqlQuery query;
    QString sql;
    qDebug()<<row;
    sql = QString("select * from searchlist where id = %1").arg(row);
    query.exec(sql);
    QString songname, singername, hash;
    while(query.next())
    {
        songname = query.value("songname").toString();
        singername = query.value("singername").toString();
        hash = query.value("hash").toString();
        qDebug() << "从数据库读取的参数:";
        qDebug() << "  歌曲名称:" << songname;
        qDebug() << "  歌手:" << singername;
        qDebug() << "  hash:" << hash << "(长度:" << hash.length() << ")";
    }
    teCurrentTitle=songname+"-"+singername;

    //插入到历史列表数据库中
    query.prepare("INSERT INTO historylist (username, songname, singername, hash) VALUES (?, ?, ?, ?)");
    qDebug()<<NowUser;
    query.addBindValue(NowUser);
    query.addBindValue(songname);
    query.addBindValue(singername);
    query.addBindValue(hash);

    if(!query.exec())
    {
        qDebug() << "插入历史记录失败：" << query.lastError().text();
    }
    else
    {
        ReadHistoryList(); // 刷新界面列表
    }
    //end

    downloadPlayer(hash);

}

void MainWindow::on_HistoryMusiclistWidget_itemDoubleClicked(QListWidgetItem *item)  //双击历史播放记录列表
{
    QString targetHash = item->data(Qt::UserRole).toString();

    QSqlQuery query;
    QString sql = QString("select * from historylist where hash = '%1'").arg(targetHash);

    isHistoryPlay=true;
    isCollectPlay=false;
    if(query.exec(sql) && query.next()) {
        QString songname = query.value("songname").toString();
        QString singername = query.value("singername").toString();
        QString hash = query.value("hash").toString();

        teCurrentTitle=songname+"-"+singername;

        downloadPlayer(hash);
    }
}

void MainWindow::downloadPlayer(QString hash) //解析出url并下载播放
{
    QNetworkAccessManager testManager;
    QUrl apiUrl(kugouDwonloadApi);
    QNetworkRequest testRequ(apiUrl);
    QNetworkReply* testReply = testManager.get(testRequ);

    QEventLoop testLoop;
    QObject::connect(testReply, &QNetworkReply::finished, &testLoop, &QEventLoop::quit);
    testLoop.exec();

    if(testReply->error() != QNetworkReply::NoError) {
        qDebug() << "API base URL is not accessible:" << testReply->errorString();
        testReply->deleteLater();
        return;
    }
    testReply->deleteLater();
    QString url = kugouDwonloadApi + QString("cmd=playInfo&hash=%1").arg(hash);

    httpAccess(url);

    QByteArray JsonData;
    QEventLoop loop;

    auto d = connect(this, &MainWindow::finish,
                     [&](const QByteArray data)
                     {
                         JsonData = data;
                         loop.exit(1);
                     });

    loop.exec();
    disconnect(d);


    //解析将要播放的音乐
    QString music = musicJsonAnalysis(JsonData);

    QString musicUrl = music; // 从JSON解析出来的url
    QString tempPath = QCoreApplication::applicationDirPath() + "/temp_music.mp3";

    // 删除旧的临时文件
    deleteLastDownloadedFile();

    // 执行下载
    if (downloadFile(musicUrl, tempPath)) {
        lastDownloadedFile = tempPath; // 记录路径以便下次删除
        startPlay(tempPath);           // 播放本地文件
    }
}

void MainWindow::netReply(QNetworkReply *reply) //读取网络数据
{
    //获取相应信息，状态码为200是正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"status_code:"<<status_code;

    reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    //没有错误就返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray data = reply->readAll();
        emit finish(data);
    }
    else //有错误
    {
        qDebug()<<reply->errorString();
    }
    reply->deleteLater();
}

void MainWindow::httpAccess(QString url) //访问http网页
{
    //实例化网络请求操作事项
    request = new QNetworkRequest;

    //将url网页地址存入request请求当中
    request->setUrl(url);
    request->setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36");
    request->setRawHeader("Referer", "https://www.kugou.com/");

    //实例化网络管理
    manager = new QNetworkAccessManager;

    //通过get方法，上传具体请求
    manager->get(*request);

    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::netReply);
}

void MainWindow::on_FindButton_clicked() //搜索音乐
{
    //将上一次搜索的记录清空
    ui->FindMusiclistWidget->clear();

    //清除数据库中已经存储的hash等数据
    QSqlQuery query;
    QString sql;
    sql = "TRUNCATE TABLE searchlist";
    if(!query.exec(sql))
    {
        QMessageBox::warning(this, "警告", QString("Delete searchlist Error : %1").arg(db.lastError().text()));
    }

    //根据用户输入的歌曲名称，发起请求操作
    QString url = kugouSearchApi + QString("format=json&keyword=%1&page=1&pagesize=20&showtype").arg(ui->FindmusicLineEdit->text());
    httpAccess(url);

    QByteArray JsonData;
    QEventLoop loop;

    auto c = connect(this, &MainWindow::finish,
                     [&](const QByteArray &data){
                         JsonData = data;
                         loop.exit(1);
                     });

    loop.exec();
    disconnect(c);

    //解析网页回复的数据，将搜索到的音乐hash和album_id与列表的索引值存放到数据库
    hashJsonAnalysis(JsonData);

}

void MainWindow::hashJsonAnalysis(QByteArray JsonData) //解析返回的Json数据
{
    QJsonDocument document = QJsonDocument::fromJson(JsonData);
    if(document.isObject())
    {
        QJsonObject data = document.object();

        if(data.contains("data"))
        {
            QJsonObject objectInfo = data.value("data").toObject();
            if(objectInfo.contains("info"))
            {
                QJsonArray objectHash = objectInfo.value("info").toArray();
                rowMax=objectHash.count(); //获取当前搜索最大记录
                for(int i=0;i<objectHash.count();i++)
                {
                    QString songname, singername, hash;
                    QJsonObject album = objectHash.at(i).toObject();

                    if(album.contains("songname"))
                    {
                        songname = album.value("songname").toString();
                    }
                    if(album.contains("singername"))
                    {
                        singername = album.value("singername").toString();
                    }
                    if(album.contains("hash"))
                    {
                        hash = album.value("hash").toString();
                    }

                    QSqlQuery query;
                    query.prepare("INSERT INTO searchlist (songname, singername, hash) "
                                  "VALUES (?, ?, ?)");

                    query.addBindValue(songname);   // 对应第二个 ? (songname)
                    query.addBindValue(singername); // 对应第三个 ? (singername)
                    query.addBindValue(hash);       // 对应第四个 ? (hash)

                    if(!query.exec())
                    {
                        QMessageBox::warning(this,"错误","insert searchlist Error1");
                        QSqlError error = query.lastError();
                        qDebug() << "错误类型:" << error.type();        // 返回 QSqlError::NoError
                        qDebug() << "是否有效:" << error.isValid();     // 返回 false
                        qDebug() << "错误文本:" << error.text();
                    }

                    //解析的音乐名称，存入控件FindMusiclistWidget
                    QString show = songname + "--" + singername;
                    ui->FindMusiclistWidget->addItem(show);
                }
            }
        }
    }


}



QString MainWindow::musicJsonAnalysis(QByteArray JsonData) //解析选择歌曲的JSON数据
{
    QJsonDocument document = QJsonDocument::fromJson(JsonData);
    if(document.isNull())
    {
        qDebug()<<"Json数据为空";
    }
    QJsonObject root = document.object();

    if(document.isObject())
    {
        QJsonObject data = document.object();
        qDebug()<<data<<"\n\n";
        if(data.contains("songName"))
        {
            qDebug() << "歌曲名称:" << data["songName"].toString();
        }
        if(data.contains("singerName"))
        {
            qDebug() << "歌手:" << data["singerName"].toString();
        }
        if(data.contains("timeLength"))
        {
            qDebug() << "时长:" << data["timeLength"].toInt() << "";


            // 设置当前音乐的播放总时间
            int MusicMinute=data["timeLength"].toInt()/60;
            int MusicSecond=data["timeLength"].toInt()%60;
            QString MusicTimeLength=QString("%1").arg(MusicMinute,2,10,QChar('0'))+":"+QString("%1").arg(MusicSecond,2,10,QChar('0'));
            ui->CurrentTimeLabel->setText(MusicTimeLength);
        }
        if(data.contains("fileSize"))
        {
            qDebug() << "文件大小:" << data["fileSize"].toInt() << "bytes";
        }
        if(data.contains("url")) {
            QString playUrl = data["url"].toString();
            qDebug() << "找到播放URL:" << playUrl;

            return playUrl;
        }
    }
    return "";
}



void MainWindow::lyricTextShow(QString role, QString content) //显示歌词
{
    ui->ShowMusiclistWidget->clear();
    ui->ShowMusiclistWidget->setWordWrap(true);

    // 将内容按换行符拆分成数组
    QStringList lines = content.split("\n", Qt::SkipEmptyParts);

    for (const QString &line : lines) {
        QListWidgetItem *item = new QListWidgetItem(line.trimmed());

        // 设置样式
        item->setForeground(Qt::darkGreen);
        item->setTextAlignment(Qt::AlignLeft);

        ui->ShowMusiclistWidget->addItem(item);
    }

    ui->ShowMusiclistWidget->scrollToTop();

}

void MainWindow::SendMusicTitle(QString title) //向Ai发送歌词
{
    QString prompt = QString("请给我《%1》这首歌的歌词，你不需要其余的回答，只需要给我歌词就行").arg(title);

    // 2.构造 JSON 请求体
    QJsonObject root;
    root.insert("model", "deepseek-chat");
    QJsonArray messages;
    QJsonObject msg;
    msg.insert("role", "user");
    msg.insert("content", prompt);
    messages.append(msg);
    root.insert("messages", messages);
    root.insert("stream", false); // 明确设置为非流式

    // 3.构造 Request
    QNetworkRequest request(QUrl("https://api.deepseek.com/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg("sk-4bd0ffe4338144789fe14a255039232f").toUtf8());

    // 4.发送 POST
    networkManager->post(request, QJsonDocument(root).toJson());
}

void MainWindow::handleDeepSeekReply(QNetworkReply *reply)  // 处理服务器回复
{
    qDebug() << "Status Code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Error:" << reply->errorString();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);

        if (doc.isNull()) {
            lyricTextShow("system", "解析失败：返回的不是有效的JSON。");
            return;
        }

        QJsonObject root = doc.object();

        // 精准匹配路径：choices -> [0] -> message -> content
        if (root.contains("choices") && root["choices"].isArray()) {
            QJsonArray choices = root["choices"].toArray();
            if (!choices.isEmpty()) {
                QJsonObject choiceObj = choices.at(0).toObject();
                QJsonObject messageObj = choiceObj["message"].toObject();
                QString aiResponse = messageObj["content"].toString();

                if (!aiResponse.isEmpty()) {
                    // 成功拿到 AI 的推荐文本
                    lyricTextShow("assistant", aiResponse);
                } else {
                    lyricTextShow("system", "AI 回复内容为空。");
                }
            }
        }
    } else {
        lyricTextShow("system", "API 请求失败：" + reply->errorString());
    }
    reply->deleteLater();
}

void MainWindow::moveEvent(QMoveEvent *event) //子窗口跟随主窗口移动
{
    QMainWindow::moveEvent(event);

    // AI窗口跟随（主窗口右侧）
    if (aiWindow && aiWindow->isVisible()) {
        int x = this->geometry().x() + this->width();
        int y = this->geometry().y();
        aiWindow->move(x, y);
    }

    // 收藏窗口跟随（主窗口左侧）
    if (collectWindow && collectWindow->isVisible()) {
        // 主窗口左边缘x坐标减去收藏窗口本身的宽度
        int x = this->geometry().x() - collectWindow->width();
        int y = this->geometry().y();
        collectWindow->move(x, y);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) //移动鼠标事件
{
    if(mousePress == true)
    {
        QPoint movepos = event->globalPos();
        move(movepos - movePoint);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) //按下鼠标事件
{
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    movePoint = event->globalPos()-pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) //释放鼠标事件
{
    emit firstClicke();
    Q_UNUSED(event);
    mousePress = false;
}

void MainWindow::slotTimerTimeOut() //判断是否在一定时间内鼠标是否双击
{
    m_cTimer.stop();
    if(mouseClike == 1)
    {
        mouseClike = 0;
    }
    else
    {
        //connect(ui->FindMusiclistWidget, &QListWidget::itemClicked, this, &MainWindow::playFindMusic);
        mouseClike = 0;
    }
}

void MainWindow::clicke() //鼠标单击
{
    mouseClike++;
    m_cTimer.start(200);
}


void MainWindow::on_help_pushButton_clicked() //关于
{
    QMessageBox::about(this,"about","音乐播放器");
}

void MainWindow::backgrouptoDefault()
{
    //获取widget的palette
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/png/backgroud/backgroud1.webp").scaled(this->size(),
                                                                                                Qt::IgnoreAspectRatio, //不限制图片的比例
                                                                                                Qt::SmoothTransformation))); //平滑的缩放

    this->setPalette(palette);
}

void MainWindow::on_sky_pushButton_clicked()
{
    menuchangeSkin->exec(QCursor::pos());
}

void MainWindow::startPlay(QString music)  //开始播放
{

    player->stop();

    // 设置本地文件路径
    player->setSource(QUrl::fromLocalFile(music));

    // 防止滑块默认值为0导致没声音
    int currentVol = ui->volumehorizontalSlider->value();
    if (currentVol <= 0) {
        currentVol = 50;
        ui->volumehorizontalSlider->setValue(50);
    }
    musicoutput->setVolume(currentVol / 100.0);

    // 开始播放
    player->play();

    if(CurrentTitle!=teCurrentTitle)
    {
        CurrentTitle = teCurrentTitle;
        ui->ShowMusiclistWidget->clear();
        QString h="正在加载《"+CurrentTitle+"》的歌词......";
        ui->ShowMusiclistWidget->addItem(h);
        SendMusicTitle(CurrentTitle);
    }

    //切换播放/暂停图标
    musicPlay = true;
    ui->StopButton->setIcon(QIcon(":/png/button/play.png"));
    ui->StopButton->setIconSize(QSize(ui->StopButton->width(),ui->StopButton->height()));
}

bool MainWindow::downloadFile(const QString &url, const QString &savePath)   //下载获取到的播放url
{
    QNetworkAccessManager manager;
    QNetworkRequest request((QUrl(url)));

    // 发送请求
    QNetworkReply *reply = manager.get(request);

    // 使用事件循环等待下载完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QFile file(savePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(reply->readAll());
            file.close();
            reply->deleteLater();
            return true;
        }
    }

    qDebug() << "下载失败:" << reply->errorString();
    QMessageBox::warning(this, "sorry", QString("当前歌曲需要vip"));
    reply->deleteLater();
    return false;
}

void MainWindow::deleteLastDownloadedFile() // 删除上一次下载的音乐文件
{
    //检查路径是否为空
    if (!lastDownloadedFile.isEmpty()) {

        // 停止播放器，否则文件被占用无法删除
        if (player) {
            player->stop();
            player->setSource(QUrl()); // 清空播放源释放文件句柄
        }

        QCoreApplication::processEvents();
        // 检查文件是否存在并删除
        if (QFile::exists(lastDownloadedFile)) {
            if (QFile::remove(lastDownloadedFile)) {
                qDebug() << "成功删除临时文件：" << lastDownloadedFile;
            } else {
                qDebug() << "删除失败，文件可能仍被占用";
            }
        }

        // 清空路径记录
        lastDownloadedFile.clear();
    }
}

void MainWindow::on_recommend_pushButton_clicked() //打开Ai推荐窗口
{
    if (aiWindow->isHidden())
    {
        // 获取主窗口的右上角坐标 (x + width)
        int x = this->geometry().x() + this->width();
        int y = this->geometry().y(); // y轴与主窗口顶部对齐

        // 移动AI窗口到计算好的位置
        aiWindow->move(x, y);

        // 显示AI窗口
        aiWindow->show();
    }
    else
    {
        // 如果已经显示，则再次点击隐藏
        aiWindow->hide();
    }
}

void MainWindow::on_collect_Button_clicked() //打开收藏窗口
{
    if (collectWindow->isHidden())
    {
        QPoint mainPos = this->frameGeometry().topLeft();

        // 设置收藏窗口的位置：主窗口左边缘再往左移动收藏窗口自身的宽度
        // 如果想紧贴在内部左侧，可以根据需要调整
        int x = mainPos.x() - collectWindow->width();
        int y = mainPos.y();

        collectWindow->move(x, y);
        collectWindow->show();
    }
    else
    {
        // 如果已经显示，则再次点击隐藏
        collectWindow->hide();
    }
}




void MainWindow::Main_Historical_playlist()
{
    QStringList historySongs;


    QSqlQuery query;
    query.prepare("SELECT * FROM historylist WHERE username = ? ORDER BY id DESC");
    query.addBindValue(NowUser);
    if(!query.exec())
    {
        QMessageBox::warning(this,"警告",QString("Select historylist Error:%1").arg(db.lastError().text()));
    }

    // sql = "select * from historylist";
    // if(!query.exec(sql))
    // {
    //     QMessageBox::warning(this,"警告",QString("Select historylist Error:%1").arg(db.lastError().text()));
    // }

    while(query.next())
    {
        QString songname;
        QSqlRecord rec = query.record();
        int ablumkey = rec.indexOf("songname");

        songname = query.value(ablumkey).toString();
        historySongs << songname;
    }
    if (!historySongs.isEmpty()) {
        aiWindow->setHistorySongs(historySongs);
        //qDebug()<<historySongs;
    }
}

void MainWindow::on_Clear_History_Button_clicked()  //清空历史记录
{
    QSqlQuery query;
    // 执行删除语句
    query.prepare("DELETE FROM historylist WHERE username = ?");
    query.addBindValue(NowUser);
    if(!query.exec())
    {
        QMessageBox::warning(this, "错误", "清除历史记录失败：" + query.lastError().text());
    }
    else
    {
        QMessageBox::information(this, "成功", "您的历史记录已清空");
        ui->HistoryMusiclistWidget->clear();
    }
}

