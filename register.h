#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QRandomGenerator>
#include <QtConcurrent>
#include <QFutureWatcher>
#include <QMouseEvent>
#include <QtCore>

#include "login.h";

namespace Ui {
class RegisterDialog;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

public slots:
    void handleSendResult(QString Whosend);       // 异步结果
    void sendCAPTCHA(QString targetEmail, QString code, QString Emailtext); // 发送验证码

signals:
    void Reset_pwdhandleSendResult();

private slots:
    void on_register_varifypushButton_clicked();  // 获取验证码
    void on_register_confirmpushButton_clicked(); // 确认注册
    void on_register_cancelpushButton_clicked();  // 取消按钮 (对应 UI)
    void updateCodeButton();                      // 倒计时

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::RegisterDialog *ui;
    QString m_verficationCode;
    QTimer *m_codeTimer;
    int m_countdown = 60;
    QFutureWatcher<bool> *m_watcher;
    QPoint m_dragPosition;
    QString RegisterCode;
};

#endif // REGISTER_H
