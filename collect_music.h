#ifndef COLLECT_MUSIC_H
#define COLLECT_MUSIC_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenu>
#include "login.h"

extern QString CurrentTitle,teCurrentTitle,CurrentMusicName;
extern bool isCollectPlay;

namespace Ui {
class CollectDialog; // 对应 UI 文件中的类名
}

class Collect_Music : public QDialog
{
    Q_OBJECT

public:
    explicit Collect_Music(QWidget *parent = nullptr);
    ~Collect_Music();

signals:
    void PlayCollectMusic(QString hash);
    void ReadHistoryList();

public slots:
    void handlecollectTextlabel(QString name); //设置顶部标签
    void updateList(); //更新列表
    //void PlayCollectMusic(QString hash); //播放收藏音乐

private slots:

    void on_collectClose_pushButton_clicked(); //关闭按钮

    void showSearchContextMenu(const QPoint &pos); //右击收藏歌曲列表
    void handleFavoriteLogic(QListWidgetItem *item); //右击搜索歌曲列表菜单

    void on_collect_listWidget_itemDoubleClicked(QListWidgetItem *item);

protected:

private:
    Ui::CollectDialog *ui;
    QString m_currentUser;
    QPoint m_dragPosition;

    int row;
};

#endif // COLLECT_MUSIC_H
