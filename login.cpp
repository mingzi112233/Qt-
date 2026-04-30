#include "login.h"
#include "ui_Login.h"

QString User="123";
QString ResetEmailCode = "";
QString WhoSend = "";
int ResetEmailStatus = 0;

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint); // 无边框

}

Login::~Login()
{
    delete ui;
}

void Login::on_Login_pushButton_clicked()
{
    QString username = ui->LoginUserlineEdit->text().trimmed();
    QString password = ui->LoginPasswordlineEdit->text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "提示", "用户名或密码不能为空");
        return;
    }

    if (validateUser(username, password))
    {
        qDebug()<<username;
        emit loginSuccess(username);
        User=username;
        this->accept();
    }
    else
    {
        QMessageBox::warning(this, "错误", "用户名或密码错误");
    }
}

bool Login::validateUser(QString user, QString pwd)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE Username = ? AND Password = ?");
    query.addBindValue(user);
    query.addBindValue(pwd);
    return (query.exec() && query.next());
}

void Login::on_registerpushButton_clicked() //注册按钮
{
    this->done(10);
}

void Login::on_pushButton_clicked() //忘记密码
{
    this->done(20);
}

void Login::on_LoginClose_pushButton_clicked()
{
    this->reject();
}

void Login::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void Login::on_CloseButton_clicked() //关闭窗口
{
    this->close();
}
