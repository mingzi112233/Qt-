#include "register.h"
#include "ui_Register.h"
#include <QRegularExpression>

#include "smtp/mimemessage.h"
#include "smtp/mimetext.h"
#include "smtp/smtpclient.h"
#include "smtp/emailaddress.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    m_codeTimer = new QTimer(this);
    connect(m_codeTimer, &QTimer::timeout, this, &Register::updateCodeButton);

    m_watcher = new QFutureWatcher<bool>(this);
    connect(m_watcher, &QFutureWatcher<bool>::finished, this, [this]() {
        this->handleSendResult(WhoSend);

    });
}

Register::~Register()
{
    delete ui;
}

void Register::on_register_varifypushButton_clicked() //获取验证码
{
    QString targetEmail = ui->register_emaillineEdit->text().trimmed();
    if (!targetEmail.contains("@qq.com"))
    {
        ui->register_errorlabel->setText("请输入有效QQ邮箱");
        return;
    }

    m_verficationCode = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    ui->register_varifypushButton->setEnabled(false);
    ui->register_errorlabel->setText("正在发送中...");

    RegisterCode = m_verficationCode;

    WhoSend = "register";
    sendCAPTCHA(targetEmail, RegisterCode, "您正在进行注册操作。您的验证码是：" + RegisterCode + "，有效期为5分钟。请勿泄露给他人。");
}

void Register::sendCAPTCHA(QString targetEmail, QString code, QString Emailtext)
{
    QFuture<bool> future = QtConcurrent::run([targetEmail, code, Emailtext]() -> bool {

        SmtpClient smtp("smtp.qq.com", 465, SmtpClient::SslConnection);

        MimeMessage message;

        EmailAddress sender("2219692157@qq.com", "播放器助手");
        message.setSender(sender);

        EmailAddress recipient(targetEmail);
        message.addRecipient(recipient);

        message.setSubject("注册验证码");

        // 邮件正文
        MimeText text;
        text.setText(Emailtext); //接收邮箱地址
        message.addPart(&text);

        //连接服务器
        smtp.connectToHost();
        if (!smtp.waitForReadyConnected()) return false;

        // 账号与密钥存放在login函数中
        smtp.login("2219692157@qq.com", "jjwgmmmagfryecbd");
        if (!smtp.waitForAuthenticated()) return false;

        // 发送并等待完成
        smtp.sendMail(message);
        if (!smtp.waitForMailSent()) return false;

        smtp.quit();
        return true;
    });

    m_watcher->setFuture(future);
}

void Register::handleSendResult(QString Whosend)
{
    if (m_watcher->result())
    {
        if(Whosend == "reset_pwd")
        {
            ResetEmailStatus = 1;
            emit Reset_pwdhandleSendResult();
        }
        else
        {
            ui->register_errorlabel->setText("验证码已发送");
            m_countdown = 60;
            m_codeTimer->start(1000);
        }
    }
    else
    {
        if(Whosend == "reset_pwd")
        {
            ResetEmailStatus = 0;
            emit Reset_pwdhandleSendResult();
        }
        else
        {
            ui->register_errorlabel->setText("发送失败，请检查授权码或网络");
            ui->register_varifypushButton->setEnabled(true);
        }
    }
}

void Register::updateCodeButton()
{
    m_countdown--;
    if (m_countdown > 0)
    {
        ui->register_varifypushButton->setText(QString("%1s").arg(m_countdown));
    }
    else
    {
        m_codeTimer->stop();
        ui->register_varifypushButton->setEnabled(true);
        ui->register_varifypushButton->setText("获取验证码");
    }
}

void Register::on_register_confirmpushButton_clicked()
{
    QString user = ui->register_userlineEdit->text().trimmed();
    QString email = ui->register_emaillineEdit->text();
    QString pwd = ui->register_pwdlineEdit->text();
    QString surePwd = ui->register_surepwdlineEdit->text();
    QString code = ui->register_varifylineEdit->text().trimmed();

    if (user.isEmpty() || pwd.isEmpty())
    {
        ui->register_errorlabel->setText("信息不能为空");
        return;
    }
    if (pwd != surePwd)
    {
        ui->register_errorlabel->setText("两次密码不一致");
        return;
    }
    if (code != m_verficationCode || m_verficationCode.isEmpty())
    {
        ui->register_errorlabel->setText("验证码错误或已失效");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT Username FROM user WHERE Username = ?");
    query.addBindValue(user);
    if (query.exec() && query.next())
    {
        ui->register_errorlabel->setText("用户名已存在");
        return;
    }

    query.prepare("INSERT INTO user (Username, Password, Email) VALUES (?, ?, ?)");
    query.addBindValue(user);
    query.addBindValue(pwd);
    query.addBindValue(email);

    if (query.exec())
    {
        QMessageBox::information(this, "成功", "注册成功，请登录");
        this->accept(); // 关闭注册窗口返回登录
    }
    else
    {
        ui->register_errorlabel->setText("注册失败，数据库错误");
    }
}

void Register::on_register_cancelpushButton_clicked() //取消按钮
{
    this->reject(); // 返回登录界面
}

void Register::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Register::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}
