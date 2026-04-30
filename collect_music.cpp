#include "collect_music.h"
#include "ui_Collect_Music.h" // 确保这里的头文件名与你的项目生成一致

QString CurrentTitle="";
QString teCurrentTitle="";
bool isCollectPlay=false;

Collect_Music::Collect_Music(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CollectDialog)
{
    ui->setupUi(this);

    // 1. 设置无边框窗口
    this->setWindowFlag(Qt::FramelessWindowHint);

    // 2. 列表样式设置
    ui->collect_listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->collect_listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->collect_listWidget->clear();

    ui->collect_listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->collect_listWidget, &QListWidget::customContextMenuRequested, this, &Collect_Music::showSearchContextMenu);
}

Collect_Music::~Collect_Music()
{
    delete ui;
}

void Collect_Music::updateList()
{
    ui->collect_listWidget->clear();
    QSqlQuery query;
    query.prepare("SELECT * FROM collectlist WHERE username = ? ORDER BY id DESC");
    query.addBindValue(User);

    if(query.exec())
    {
        while(query.next())
        {
            QString info = query.value("songname").toString() + " - " + query.value("singername").toString();
            ui->collect_listWidget->addItem(info);
        }
    }

    if (ui->collect_listWidget->count() == 0)
    {
        ui->collect_listWidget->addItem("收藏夹空空如也~");
    }
}

void Collect_Music::handlecollectTextlabel(QString name)
{
    ui->collectTextlabel->setText("欢迎来到"+name+"的收藏库");
}

void Collect_Music::on_collectClose_pushButton_clicked() // 关闭按钮
{
    this->hide();
}

void Collect_Music::showSearchContextMenu(const QPoint &pos)
{
    QListWidgetItem *item = ui->collect_listWidget->itemAt(pos);

    // 如果点击的是空白处，则不弹出菜单
    if (!item)
        return;

    // 创建菜单对象
    QMenu menu(this);

    row = ui->collect_listWidget->currentRow();

    // 添加菜单项
    QAction *favAction = new QAction(QIcon(":/png/button/close.png"), "取消收藏该歌曲", this);
    menu.addAction(favAction);

    // 阻塞代码,直到点击了某个选项或关闭了菜单
    QAction *selectedAction = menu.exec(ui->collect_listWidget->mapToGlobal(pos));

    // 5. 处理点击选择
    if (selectedAction == favAction) {
        // 执行取消收藏逻辑
        handleFavoriteLogic(item);
    }
}

void Collect_Music::handleFavoriteLogic(QListWidgetItem *item)
{
    QSqlQuery query;
    query.prepare("DELETE FROM collectlist WHERE id = (SELECT id FROM (SELECT id FROM collectlist WHERE username = ? ORDER BY id DESC LIMIT 1 OFFSET ?) AS temp)");

    query.addBindValue(User);
    query.addBindValue(row);

    if (query.exec())
    {
        updateList(); //更新收藏界面
    }
    else
    {
        qDebug() << "删除失败：" << query.lastError().text();
    }
}


void Collect_Music::on_collect_listWidget_itemDoubleClicked(QListWidgetItem *item) //双击收藏列表
{
    row = ui->collect_listWidget->currentRow();
    qDebug()<<"当前播放歌曲在"<<row;

    QSqlQuery query;
    query.prepare("SELECT hash, songname, singername FROM collectlist WHERE username = ? ORDER BY id DESC LIMIT 1 OFFSET ?");
    query.addBindValue(User);
    query.addBindValue(row);

    if (query.exec() && query.next())
    {
        QString hash = query.value("hash").toString();
        QString songname = query.value("songname").toString();
        QString singername = query.value("singername").toString();

        query.prepare("INSERT INTO historylist (username, songname, singername, hash) VALUES (?, ?, ?, ?)");
        query.addBindValue(User);
        query.addBindValue(songname);
        query.addBindValue(singername);
        query.addBindValue(hash);

        if(!query.exec())
        {
            qDebug() << "插入历史记录失败：" << query.lastError().text();
        }
        else
        {
            emit ReadHistoryList(); // 刷新历史界面列表
        }

        teCurrentTitle = songname+"-"+singername;
        isCollectPlay=true;
        emit PlayCollectMusic(hash);
    }
}

