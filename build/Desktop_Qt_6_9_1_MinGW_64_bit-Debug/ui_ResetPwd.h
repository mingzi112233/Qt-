/********************************************************************************
** Form generated from reading UI file 'ResetPwd.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPWD_H
#define UI_RESETPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResetPwdDialog
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_7;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_1;
    QLabel *ResetPwd_usernamelabel;
    QLineEdit *ResetPwd_usernamelineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ResetPwd_emaillabel;
    QLineEdit *ResetPwd_emaillineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ResetPwd_pwdlabel;
    QLineEdit *ResetPwd_pwdlineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ResetPwd_surepwdlabel;
    QLineEdit *ResetPwd_surepwdlineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *ResetPwd_varifylabel;
    QLineEdit *ResetPwd_varifylineEdit;
    QPushButton *ResetPwd_varifypushButton;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *ResetPwd_confirmpushButton;
    QPushButton *ResetPwd_cancelpushButton;
    QSpacerItem *verticalSpacer_9;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *ResetPwd_errorlabel;
    QWidget *page_8;

    void setupUi(QDialog *ResetPwdDialog)
    {
        if (ResetPwdDialog->objectName().isEmpty())
            ResetPwdDialog->setObjectName("ResetPwdDialog");
        ResetPwdDialog->resize(313, 648);
        gridLayout = new QGridLayout(ResetPwdDialog);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(ResetPwdDialog);
        stackedWidget->setObjectName("stackedWidget");
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        gridLayout_4 = new QGridLayout(page_7);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        label = new QLabel(page_7);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        ResetPwd_usernamelabel = new QLabel(page_7);
        ResetPwd_usernamelabel->setObjectName("ResetPwd_usernamelabel");

        horizontalLayout_1->addWidget(ResetPwd_usernamelabel);

        ResetPwd_usernamelineEdit = new QLineEdit(page_7);
        ResetPwd_usernamelineEdit->setObjectName("ResetPwd_usernamelineEdit");

        horizontalLayout_1->addWidget(ResetPwd_usernamelineEdit);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ResetPwd_emaillabel = new QLabel(page_7);
        ResetPwd_emaillabel->setObjectName("ResetPwd_emaillabel");

        horizontalLayout_2->addWidget(ResetPwd_emaillabel);

        ResetPwd_emaillineEdit = new QLineEdit(page_7);
        ResetPwd_emaillineEdit->setObjectName("ResetPwd_emaillineEdit");

        horizontalLayout_2->addWidget(ResetPwd_emaillineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ResetPwd_pwdlabel = new QLabel(page_7);
        ResetPwd_pwdlabel->setObjectName("ResetPwd_pwdlabel");

        horizontalLayout_3->addWidget(ResetPwd_pwdlabel);

        ResetPwd_pwdlineEdit = new QLineEdit(page_7);
        ResetPwd_pwdlineEdit->setObjectName("ResetPwd_pwdlineEdit");
        ResetPwd_pwdlineEdit->setMaximumSize(QSize(16777215, 16777215));
        ResetPwd_pwdlineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(ResetPwd_pwdlineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        ResetPwd_surepwdlabel = new QLabel(page_7);
        ResetPwd_surepwdlabel->setObjectName("ResetPwd_surepwdlabel");

        horizontalLayout_4->addWidget(ResetPwd_surepwdlabel);

        ResetPwd_surepwdlineEdit = new QLineEdit(page_7);
        ResetPwd_surepwdlineEdit->setObjectName("ResetPwd_surepwdlineEdit");
        ResetPwd_surepwdlineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_4->addWidget(ResetPwd_surepwdlineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        ResetPwd_varifylabel = new QLabel(page_7);
        ResetPwd_varifylabel->setObjectName("ResetPwd_varifylabel");

        horizontalLayout_5->addWidget(ResetPwd_varifylabel);

        ResetPwd_varifylineEdit = new QLineEdit(page_7);
        ResetPwd_varifylineEdit->setObjectName("ResetPwd_varifylineEdit");

        horizontalLayout_5->addWidget(ResetPwd_varifylineEdit);

        ResetPwd_varifypushButton = new QPushButton(page_7);
        ResetPwd_varifypushButton->setObjectName("ResetPwd_varifypushButton");
        ResetPwd_varifypushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_5->addWidget(ResetPwd_varifypushButton);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        ResetPwd_confirmpushButton = new QPushButton(page_7);
        ResetPwd_confirmpushButton->setObjectName("ResetPwd_confirmpushButton");

        horizontalLayout_6->addWidget(ResetPwd_confirmpushButton);

        ResetPwd_cancelpushButton = new QPushButton(page_7);
        ResetPwd_cancelpushButton->setObjectName("ResetPwd_cancelpushButton");

        horizontalLayout_6->addWidget(ResetPwd_cancelpushButton);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);

        widget = new QWidget(page_7);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        ResetPwd_errorlabel = new QLabel(widget);
        ResetPwd_errorlabel->setObjectName("ResetPwd_errorlabel");
        ResetPwd_errorlabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_2->addWidget(ResetPwd_errorlabel, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        stackedWidget->addWidget(page_8);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(ResetPwdDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ResetPwdDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetPwdDialog)
    {
        ResetPwdDialog->setWindowTitle(QCoreApplication::translate("ResetPwdDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ResetPwdDialog", "                  \346\202\250\346\255\243\345\234\250\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        ResetPwd_usernamelabel->setText(QCoreApplication::translate("ResetPwdDialog", "\347\224\250\346\210\267\345\220\215\357\274\232   ", nullptr));
        ResetPwd_emaillabel->setText(QCoreApplication::translate("ResetPwdDialog", "\351\202\256\347\256\261\357\274\232       ", nullptr));
        ResetPwd_pwdlabel->setText(QCoreApplication::translate("ResetPwdDialog", "\346\226\260\345\257\206\347\240\201\357\274\232    ", nullptr));
        ResetPwd_surepwdlabel->setText(QCoreApplication::translate("ResetPwdDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        ResetPwd_varifylabel->setText(QCoreApplication::translate("ResetPwdDialog", "\351\252\214\350\257\201\347\240\201\357\274\232    ", nullptr));
        ResetPwd_varifypushButton->setText(QCoreApplication::translate("ResetPwdDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        ResetPwd_confirmpushButton->setText(QCoreApplication::translate("ResetPwdDialog", "\347\241\256\350\256\244", nullptr));
        ResetPwd_cancelpushButton->setText(QCoreApplication::translate("ResetPwdDialog", "\345\217\226\346\266\210", nullptr));
        ResetPwd_errorlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ResetPwdDialog: public Ui_ResetPwdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPWD_H
