#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ai.h"
#include "collect_music.h"
#include "login.h"
#include "register.h"
#include "reset_pwd.h"
#include <QMainWindow>

#include <QNetworkRequest> //http的url请求
#include <QNetworkAccessManager> //url的上传
#include <QNetworkReply>  //网页回复数据触发信号的类
#include <QEventLoop> //QEventLoop类提供一种进入和离开事件循环的方法

#include <QJsonArray> //QJsonArray类用于封装json数组
#include <QJsonObject> //QJsonObject类用于封装json对象
#include <QJsonDocument>

#include <QMediaPlayer>
#include <QAudioOutput>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include <QTime>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QMenu>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QFileDialog>
#include <QStandardPaths>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <math.h>

static const QString kugouSearchApi = "http://mobilecdn.kugou.com/api/v3/search/song?";
static const QString kugouDwonloadApi = "http://m.kugou.com/app/i/getSongInfo.php?";

#define DEEPSEEK_API_URL "https://api.deepseek.com/chat/completions" // DeepSeek 对话接口地址
#define DEEPSEEK_API_KEY "sk-4bd0ffe4338144789fe14a255039232f" // deepseek密钥

 /*
 * 待完成
 * 因为直接播放会很卡，所以应该要下载下来
 */
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void paintEvent(QPaintEvent *event);
    void Main_Historical_playlist();

signals:
    void finish(QByteArray);
    void lyricShow(QString);
    void firstClicke();
    void SetCollectText(QString name);
    void updateList(); //收藏成功信号

private slots:
    void on_close_pushButton_clicked();
    void on_prevButton_clicked();
    void on_StopButton_clicked();
    void on_NextButton_clicked();
    void on_ModeButton_clicked();
    void on_volumehorizontalSlider_valueChanged(int value);
    void on_ProgresshorizontalSlider_valueChanged(int value);

    void updateDuration(qint64 value); //更新播放的进度和显示的时间
    void netReply(QNetworkReply *); //读取网络数据

    void lyricTextShow(QString role, QString content); //显示歌词
    void SendMusicTitle(QString,QString);  //向ai发送歌名
    void downloadPlayer(QString hash); //音乐歌词下载
    void handleDeepSeekReply(QNetworkReply *reply); // 处理服务器回复

    void on_FindButton_clicked(); //寻找歌曲
    void processAiRecommendations(QStringList names); //处理AI推荐的歌曲

    void on_help_pushButton_clicked(); //帮助
    void showSearchContextMenu(const QPoint &pos); //右击搜索歌曲列表
    void handleFavoriteLogic(QListWidgetItem *item); //右击搜索歌曲列表菜单选择收藏音乐
    void handleNextPlayLogic(QListWidgetItem *item); //右击搜索歌曲列表菜单选择添加到下一首播放
    void handleLoginSuccess(QString username); //接受用户名

    void backgrouptoDefault(); //更换默认皮肤
    void ReadHistoryList(); //读取历史播放记录列表

    void on_sky_pushButton_clicked(); //更换皮肤
    void startPlay(QString JsonData); //开始播放
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);  //播放完毕，进行下一首音乐判断
    void GetCurrentRow(); //双击播放搜索列表获取row
    void playFindMusic(); //根据row进行播放搜索

    bool downloadFile(const QString &url, const QString &savePath); //下载音乐
    void deleteLastDownloadedFile(); //删除上一次下载

    void on_recommend_pushButton_clicked();

    void on_Clear_History_Button_clicked();

    void on_HistoryMusiclistWidget_itemDoubleClicked(QListWidgetItem *item);  //双击历史播放记录列表


    void on_Login_Button_clicked(); //登录按钮

    void on_collect_Button_clicked();

    void on_NextMusicListButton_clicked();

protected:

    void httpAccess(QString); //访问http网页
    void hashJsonAnalysis(QByteArray); //使用Json解析音乐的hash与album_id值
    QString musicJsonAnalysis(QByteArray); //搜索的音乐数据信息使用JSON解析，解析出真正的音乐文件和歌词

    //歌词滚动，函数部分，start
    void startCharHighlight(int lineIndex);      // 启动逐字高亮
    void updateCharHighlight(int lineIndex, int charCount); // 更新逐字高亮
    void updateCharHighlightByPosition(qint64 position);    // 根据位置更新高亮
    void updateLyricPosition(qint64 position); //歌词滚动效果
    //歌词滚动部分end

    void slotTimerTimeOut();
    void clicke();

public:
    QString NowUser;

private:
    Ui::MainWindow *ui;

    bool IsLogin = false; //判断是否已登录

    QNetworkRequest *request;
    QNetworkAccessManager *manager;

    QMediaPlayer *player;
    QAudioOutput *musicoutput;

    QSqlDatabase db;

    int num,row,rowMax,HistoryRowMax;
    int PlayMode;
    bool isHistoryPlay;
    QString sql;
    QString NowMusicHash;

    QMenu *menuchangeSkin;

private:
    QPoint m_mousePoint;
    QPoint movePoint;
    bool mousePress;
    bool musicPlay;

    //歌词滚动，变量部分，start

    QStringList m_lyricLines;           // 存储歌词行
    int m_currentLine = -1;             // 当前歌词行索引
    int m_currentChar = 0;              // 当前高亮字符位置
    QTimer *m_highlightTimer = nullptr; // 逐字高亮定时器

    //歌词滚动部分end

    //下一首播放列表，start

    QFrame *nextPlayFrame = nullptr;
    QListWidget *nextPlayList = nullptr;

    //下一首播放列表，end

    int mouseClike;
    QTimer m_cTimer;

    QString lastDownloadedFile;
    QNetworkAccessManager *networkManager;

private:
    bool isAiChatVisible;
    AI *aiWindow;
    Collect_Music *collectWindow;
    Login *login;
    Register *reg;
    ResetPwd *resetpwd;

protected:

    bool eventFilter(QObject *watched, QEvent *event) override; // 过滤事件

    void moveEvent(QMoveEvent *event) override;  //子窗口跟随主窗口移动
    void mouseMoveEvent(QMouseEvent *event); //移动鼠标事件
    void mousePressEvent(QMouseEvent *event); //按下鼠标事件
    void mouseReleaseEvent(QMouseEvent *event); //释放鼠标事件
};
#endif // MAINWINDOW_H
