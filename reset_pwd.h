#ifndef RESETPWD_H
#define RESETPWD_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QRandomGenerator>
#include <QtConcurrent>
#include <QFutureWatcher>
#include <QtCore>

#include "register.h";
#include "login.h";

namespace Ui {
class ResetPwdDialog;
}

class ResetPwd : public QDialog
{
    Q_OBJECT

public:
    explicit ResetPwd(QWidget *parent = nullptr);
    ~ResetPwd();

signals:
    void SendCaptcha(QString targetEmail, QString code, QString Emailtext);

public slots:

    void handleSendResult(); // 新增：处理邮件发送结果的槽函数

private slots:
    void on_ResetPwd_confirmpushButton_clicked(); // 确定重置
    void on_ResetPwd_cancelpushButton_clicked(); // 取消
    void on_ResetPwd_varifypushButton_clicked(); // 获取验证码
    void updateCodeButton();                     // 倒计时显示

private:
    Ui::ResetPwdDialog *ui;
    QString m_verficationCode;
    QTimer *m_codeTimer;
    int m_countdown = 60;

    Register *reg;

    QFutureWatcher<bool> *m_watcher;
};

#endif // RESETPWD_H
