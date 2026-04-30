/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *LoginUserLabel;
    QLineEdit *LoginUserlineEdit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *registerpushButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LoginPasswordLable;
    QLineEdit *LoginPasswordlineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Login_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *CloseButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(297, 696);
        gridLayout_2 = new QGridLayout(LoginDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        LoginUserLabel = new QLabel(LoginDialog);
        LoginUserLabel->setObjectName("LoginUserLabel");

        horizontalLayout->addWidget(LoginUserLabel);

        LoginUserlineEdit = new QLineEdit(LoginDialog);
        LoginUserlineEdit->setObjectName("LoginUserlineEdit");
        LoginUserlineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(LoginUserlineEdit);


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        registerpushButton = new QPushButton(LoginDialog);
        registerpushButton->setObjectName("registerpushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(registerpushButton->sizePolicy().hasHeightForWidth());
        registerpushButton->setSizePolicy(sizePolicy);
        registerpushButton->setMinimumSize(QSize(100, 20));

        horizontalLayout_6->addWidget(registerpushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_6, 10, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        LoginPasswordLable = new QLabel(LoginDialog);
        LoginPasswordLable->setObjectName("LoginPasswordLable");

        horizontalLayout_3->addWidget(LoginPasswordLable);

        LoginPasswordlineEdit = new QLineEdit(LoginDialog);
        LoginPasswordlineEdit->setObjectName("LoginPasswordlineEdit");
        LoginPasswordlineEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LoginPasswordlineEdit->sizePolicy().hasHeightForWidth());
        LoginPasswordlineEdit->setSizePolicy(sizePolicy1);
        LoginPasswordlineEdit->setMaximumSize(QSize(16777215, 16777215));
        LoginPasswordlineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(LoginPasswordlineEdit);


        gridLayout_2->addLayout(horizontalLayout_3, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 109, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 8, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        Login_pushButton = new QPushButton(LoginDialog);
        Login_pushButton->setObjectName("Login_pushButton");
        Login_pushButton->setMinimumSize(QSize(100, 20));

        horizontalLayout_5->addWidget(Login_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_5, 9, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(LoginDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:0x;\n"
"	background-repeat:no-repeat;\n"
"	border:none;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:hevar{\n"
"	background-color:rgb(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color:rgba(95,95,95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton);


        gridLayout_2->addLayout(horizontalLayout_4, 7, 0, 1, 1);

        widget = new QWidget(LoginDialog);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        CloseButton = new QPushButton(widget);
        CloseButton->setObjectName("CloseButton");
        CloseButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        CloseButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:0x;\n"
"	background-repeat:no-repeat;\n"
"	border:none;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:hevar{\n"
"	background-color:rgb(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color:rgba(95,95,95,100);\n"
"	border-color:rgba(255,255,255,30);\n"
"	border-style:inset;\n"
"	color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/button/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        CloseButton->setIcon(icon);
        CloseButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(CloseButton, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 108, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 11, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 1, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        LoginUserLabel->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        registerpushButton->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        LoginPasswordLable->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        Login_pushButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        CloseButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
