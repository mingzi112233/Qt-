/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_RegisterDialog
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
    QHBoxLayout *horizontalLayout;
    QLabel *register_userlabel;
    QLineEdit *register_userlineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *register_emaillabel;
    QLineEdit *register_emaillineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *register_pwdlabel;
    QLineEdit *register_pwdlineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *register_surepwdlabel;
    QLineEdit *register_surepwdlineEdit;
    QHBoxLayout *horizontalLayout_20;
    QLabel *register_varifylabel;
    QLineEdit *register_varifylineEdit;
    QPushButton *register_varifypushButton;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *register_confirmpushButton;
    QPushButton *register_cancelpushButton;
    QSpacerItem *verticalSpacer_9;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *register_errorlabel;
    QWidget *page_8;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(314, 589);
        gridLayout = new QGridLayout(RegisterDialog);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(RegisterDialog);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        register_userlabel = new QLabel(page_7);
        register_userlabel->setObjectName("register_userlabel");

        horizontalLayout->addWidget(register_userlabel);

        register_userlineEdit = new QLineEdit(page_7);
        register_userlineEdit->setObjectName("register_userlineEdit");

        horizontalLayout->addWidget(register_userlineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        register_emaillabel = new QLabel(page_7);
        register_emaillabel->setObjectName("register_emaillabel");

        horizontalLayout_2->addWidget(register_emaillabel);

        register_emaillineEdit = new QLineEdit(page_7);
        register_emaillineEdit->setObjectName("register_emaillineEdit");

        horizontalLayout_2->addWidget(register_emaillineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        register_pwdlabel = new QLabel(page_7);
        register_pwdlabel->setObjectName("register_pwdlabel");

        horizontalLayout_3->addWidget(register_pwdlabel);

        register_pwdlineEdit = new QLineEdit(page_7);
        register_pwdlineEdit->setObjectName("register_pwdlineEdit");
        register_pwdlineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(register_pwdlineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        register_surepwdlabel = new QLabel(page_7);
        register_surepwdlabel->setObjectName("register_surepwdlabel");

        horizontalLayout_4->addWidget(register_surepwdlabel);

        register_surepwdlineEdit = new QLineEdit(page_7);
        register_surepwdlineEdit->setObjectName("register_surepwdlineEdit");
        register_surepwdlineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_4->addWidget(register_surepwdlineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        register_varifylabel = new QLabel(page_7);
        register_varifylabel->setObjectName("register_varifylabel");

        horizontalLayout_20->addWidget(register_varifylabel);

        register_varifylineEdit = new QLineEdit(page_7);
        register_varifylineEdit->setObjectName("register_varifylineEdit");

        horizontalLayout_20->addWidget(register_varifylineEdit);

        register_varifypushButton = new QPushButton(page_7);
        register_varifypushButton->setObjectName("register_varifypushButton");

        horizontalLayout_20->addWidget(register_varifypushButton);


        verticalLayout->addLayout(horizontalLayout_20);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        register_confirmpushButton = new QPushButton(page_7);
        register_confirmpushButton->setObjectName("register_confirmpushButton");

        horizontalLayout_21->addWidget(register_confirmpushButton);

        register_cancelpushButton = new QPushButton(page_7);
        register_cancelpushButton->setObjectName("register_cancelpushButton");

        horizontalLayout_21->addWidget(register_cancelpushButton);


        verticalLayout->addLayout(horizontalLayout_21);

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
        register_errorlabel = new QLabel(widget);
        register_errorlabel->setObjectName("register_errorlabel");
        register_errorlabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_2->addWidget(register_errorlabel, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        stackedWidget->addWidget(page_8);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(RegisterDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegisterDialog", "                   \346\202\250\346\255\243\345\234\250\346\263\250\345\206\214\350\264\246\346\210\267", nullptr));
        register_userlabel->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        register_emaillabel->setText(QCoreApplication::translate("RegisterDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        register_pwdlabel->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        register_surepwdlabel->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        register_varifylabel->setText(QCoreApplication::translate("RegisterDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        register_varifypushButton->setText(QCoreApplication::translate("RegisterDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        register_confirmpushButton->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244", nullptr));
        register_cancelpushButton->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
        register_errorlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
