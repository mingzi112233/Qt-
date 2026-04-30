#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QMouseEvent>

extern QString User;
extern QString WhoSend;
extern QString ResetEmailCode;
extern int ResetEmailStatus;


namespace Ui {
class LoginDialog; // 与 Login.ui 中的 class Dialog 对应
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void loginSuccess(QString username); // 登录成功信号

private slots:
    void on_Login_pushButton_clicked();       // 登录按钮
    void on_registerpushButton_clicked();    // 切换到注册界面按钮
    void on_LoginClose_pushButton_clicked(); // 关闭按钮

    void on_CloseButton_clicked();


    void on_pushButton_clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::LoginDialog *ui;

    // Register *reg;
    // ResetPwd *resetpwd;

    QPoint m_dragPosition;
    bool validateUser(QString user, QString pwd); // 验证逻辑
};

#endif // LOGIN_H
