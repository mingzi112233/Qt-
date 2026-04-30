#include "reset_pwd.h"
#include "ui_ResetPwd.h"
#include <QRegularExpression>

ResetPwd::ResetPwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResetPwdDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    reg = new Register(this);
    connect(this, &ResetPwd::SendCaptcha, reg, &Register::sendCAPTCHA);

    m_codeTimer = new QTimer(this);
    connect(m_codeTimer, &QTimer::timeout, this, &ResetPwd::updateCodeButton);

    m_watcher = new QFutureWatcher<bool>(this);
    connect(m_watcher, &QFutureWatcher<bool>::finished, this, &ResetPwd::handleSendResult);

}

ResetPwd::~ResetPwd()
{
    delete ui;
}

void ResetPwd::on_ResetPwd_confirmpushButton_clicked() //重置
{
    QString name = ui->ResetPwd_usernamelineEdit->text().trimmed();
    QString email = ui->ResetPwd_emaillineEdit->text().trimmed();
    QString code = ui->ResetPwd_varifylineEdit->text().trimmed();
    QString passwd = ui->ResetPwd_pwdlineEdit->text();
    QString confirmPasswd = ui->ResetPwd_surepwdlineEdit->text();

    if (name.isEmpty() || email.isEmpty() || code.isEmpty() || passwd.isEmpty())
    {
        ui->ResetPwd_errorlabel->setText("请填写完整信息");
        return;
    }
    if (passwd != confirmPasswd)
    {
        ui->ResetPwd_errorlabel->setText("两次密码不一致");
        return;
    }
    if (code != m_verficationCode || m_verficationCode.isEmpty())
    {
        ui->ResetPwd_errorlabel->setText("验证码错误");
        return;
    }

    QSqlQuery query;

    // 检查是否存在
    query.prepare("SELECT Username FROM user WHERE Username = ?");
    qDebug()<<name;
    query.addBindValue(name);

    if (!query.exec() || !query.next())
    {
        ui->ResetPwd_errorlabel->setText("该用户名不存在");
        return;
    }

    query.prepare("SELECT Username FROM user WHERE Email = ?");
    query.addBindValue(email);

    if (!query.exec() || !query.next())
    {
        ui->ResetPwd_errorlabel->setText("该邮箱未注册账号");
        return;
    }

    // 更新该用户的密码
    query.prepare("UPDATE user SET Password = ? WHERE Username = ?");
    query.addBindValue(passwd);
    query.addBindValue(name);

    if (query.exec())
    {
        QMessageBox::information(this, "成功", "密码已重置，请使用新密码登录");
        this->accept();
    }
    else
    {
        qDebug() << "更新失败:" << query.lastError().text();
        ui->ResetPwd_errorlabel->setText("数据库更新失败");
    }
}


void ResetPwd::on_ResetPwd_varifypushButton_clicked() //获取验证码
{
    QString targetEmail = ui->ResetPwd_emaillineEdit->text().trimmed();
    if (!targetEmail.contains("@qq.com"))
    {
        ui->ResetPwd_errorlabel->setText("请输入有效QQ邮箱");
        return;
    }

    m_verficationCode = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    ui->ResetPwd_varifypushButton->setEnabled(false);
    ui->ResetPwd_errorlabel->setText("正在发送中...");

    ResetEmailCode = m_verficationCode;

    WhoSend = "reset_pwd";
    emit SendCaptcha(targetEmail, ResetEmailCode, "您正在进行重置密码操作。您的验证码是：" + ResetEmailCode + "，有效期为5分钟。请勿泄露给他人。");

    QTimer::singleShot(2000, this, [this]() {
        // 3秒后会执行这里的代码
        handleSendResult();
    });
}

void ResetPwd::handleSendResult()
{
    if (ResetEmailStatus == 1)
    {
        ui->ResetPwd_errorlabel->setText("验证码已发送");
        m_countdown = 60;
        m_codeTimer->start(1000);
    }
    else
    {
        ui->ResetPwd_errorlabel->setText("发送失败，请检查授权码或网络");
        ui->ResetPwd_varifypushButton->setEnabled(true);
    }
}

void ResetPwd::updateCodeButton()
{
    m_countdown--;
    if (m_countdown > 0)
    {
        ui->ResetPwd_varifypushButton->setText(QString("%1s").arg(m_countdown));
    }
    else
    {
        m_codeTimer->stop();
        ui->ResetPwd_varifypushButton->setEnabled(true);
        ui->ResetPwd_varifypushButton->setText("获取验证码");
        ResetEmailStatus = 0;
    }
}

void ResetPwd::on_ResetPwd_cancelpushButton_clicked() //点击取消按钮
{
    this->reject();
}
