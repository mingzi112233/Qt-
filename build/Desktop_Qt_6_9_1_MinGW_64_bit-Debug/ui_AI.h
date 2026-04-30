/********************************************************************************
** Form generated from reading UI file 'AI.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AI_H
#define UI_AI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *Aiclose_pushButton;
    QListWidget *AI_listWidget;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Recommend_pushButton;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(317, 681);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        Aiclose_pushButton = new QPushButton(Dialog);
        Aiclose_pushButton->setObjectName("Aiclose_pushButton");
        Aiclose_pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Aiclose_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        Aiclose_pushButton->setIcon(icon);
        Aiclose_pushButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(Aiclose_pushButton, 0, 8, 1, 1);

        AI_listWidget = new QListWidget(Dialog);
        AI_listWidget->setObjectName("AI_listWidget");

        gridLayout->addWidget(AI_listWidget, 1, 0, 1, 9);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(41, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 6, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(89, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(106, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(41, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 7, 1, 2);

        Recommend_pushButton = new QPushButton(Dialog);
        Recommend_pushButton->setObjectName("Recommend_pushButton");

        gridLayout->addWidget(Recommend_pushButton, 2, 3, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 5, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Aiclose_pushButton->setText(QString());
        Recommend_pushButton->setText(QCoreApplication::translate("Dialog", "\350\277\233\350\241\214\346\216\250\350\215\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AI_H
