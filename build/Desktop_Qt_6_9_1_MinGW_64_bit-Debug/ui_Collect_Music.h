/********************************************************************************
** Form generated from reading UI file 'Collect_Music.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLECT_MUSIC_H
#define UI_COLLECT_MUSIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CollectDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *collectTextlabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *collectClose_pushButton;
    QListWidget *collect_listWidget;

    void setupUi(QDialog *CollectDialog)
    {
        if (CollectDialog->objectName().isEmpty())
            CollectDialog->setObjectName("CollectDialog");
        CollectDialog->resize(373, 722);
        gridLayout = new QGridLayout(CollectDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        collectTextlabel = new QLabel(CollectDialog);
        collectTextlabel->setObjectName("collectTextlabel");

        gridLayout->addWidget(collectTextlabel, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(121, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        collectClose_pushButton = new QPushButton(CollectDialog);
        collectClose_pushButton->setObjectName("collectClose_pushButton");
        collectClose_pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        collectClose_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        collectClose_pushButton->setIcon(icon);
        collectClose_pushButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(collectClose_pushButton, 0, 3, 1, 1);

        collect_listWidget = new QListWidget(CollectDialog);
        collect_listWidget->setObjectName("collect_listWidget");

        gridLayout->addWidget(collect_listWidget, 1, 0, 1, 4);


        retranslateUi(CollectDialog);

        QMetaObject::connectSlotsByName(CollectDialog);
    } // setupUi

    void retranslateUi(QDialog *CollectDialog)
    {
        CollectDialog->setWindowTitle(QCoreApplication::translate("CollectDialog", "Dialog", nullptr));
        collectTextlabel->setText(QCoreApplication::translate("CollectDialog", "\346\224\266\350\227\217\345\272\223", nullptr));
        collectClose_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CollectDialog: public Ui_CollectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLECT_MUSIC_H
