#ifndef AI_H
#define AI_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QListWidgetItem>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include <QMessageBox>

namespace Ui {
class Dialog;
}

class AI : public QDialog
{
    Q_OBJECT

signals:
    void requestMusicSearch();

public:
    explicit AI(QWidget *parent = nullptr);
    ~AI();

public:
    void setHistorySongs(const QStringList &songs); //接受主窗口获得的历史歌单

private slots:

    void on_Aiclose_pushButton_clicked();
    void handleDeepSeekReply(QNetworkReply *reply); // 处理服务器回复
    void on_Recommend_pushButton_clicked();


private:
    Ui::Dialog *ui;


private:

    QStringList m_historySongs;

    QNetworkAccessManager *networkManager;
    void appendMessage(QString role, QString content); // 辅助函数：将对话添加到 ListWidget


};

#endif // AI_H
