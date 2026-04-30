/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *help_pushButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *FindMusiclistWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *ShowMusiclistWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *HistoryMusiclistWidget;
    QPushButton *Login_Button;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Clear_History_Button;
    QLineEdit *FindmusicLineEdit;
    QPushButton *FindButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *StopButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *NextButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ModeButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSlider *volumehorizontalSlider;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *TotalTimeLabel;
    QSlider *ProgresshorizontalSlider;
    QLabel *CurrentTimeLabel;
    QPushButton *close_pushButton;
    QPushButton *collect_Button;
    QPushButton *recommend_pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(829, 681);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/button/help.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_9 = new QSpacerItem(636, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        help_pushButton = new QPushButton(centralwidget);
        help_pushButton->setObjectName("help_pushButton");
        help_pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        help_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        help_pushButton->setIcon(icon);
        help_pushButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(help_pushButton, 0, 5, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(" color:rgb(255,255,255);"));

        verticalLayout->addWidget(label);

        FindMusiclistWidget = new QListWidget(centralwidget);
        FindMusiclistWidget->setObjectName("FindMusiclistWidget");
        FindMusiclistWidget->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"background-color:rgba(255,255,255,50);\n"
""));
        FindMusiclistWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);

        verticalLayout->addWidget(FindMusiclistWidget);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(" color:rgb(255,255,255);"));

        verticalLayout_2->addWidget(label_2);

        ShowMusiclistWidget = new QListWidget(centralwidget);
        ShowMusiclistWidget->setObjectName("ShowMusiclistWidget");
        ShowMusiclistWidget->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"background-color:rgba(255,255,255,50);\n"
""));

        verticalLayout_2->addWidget(ShowMusiclistWidget);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8(" color:rgb(255,255,255);"));

        verticalLayout_3->addWidget(label_3);

        HistoryMusiclistWidget = new QListWidget(centralwidget);
        HistoryMusiclistWidget->setObjectName("HistoryMusiclistWidget");
        HistoryMusiclistWidget->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"background-color:rgba(255,255,255,50);\n"
""));

        verticalLayout_3->addWidget(HistoryMusiclistWidget);


        horizontalLayout_3->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 7);

        Login_Button = new QPushButton(centralwidget);
        Login_Button->setObjectName("Login_Button");
        Login_Button->setMinimumSize(QSize(0, 0));
        Login_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Login_Button->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/button/Login.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Login_Button->setIcon(icon1);
        Login_Button->setIconSize(QSize(32, 32));

        gridLayout->addWidget(Login_Button, 0, 4, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Clear_History_Button = new QPushButton(groupBox);
        Clear_History_Button->setObjectName("Clear_History_Button");
        Clear_History_Button->setMinimumSize(QSize(150, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        Clear_History_Button->setFont(font1);

        horizontalLayout_2->addWidget(Clear_History_Button);

        FindmusicLineEdit = new QLineEdit(groupBox);
        FindmusicLineEdit->setObjectName("FindmusicLineEdit");
        FindmusicLineEdit->setMinimumSize(QSize(0, 40));
        FindmusicLineEdit->setFont(font1);

        horizontalLayout_2->addWidget(FindmusicLineEdit);

        FindButton = new QPushButton(groupBox);
        FindButton->setObjectName("FindButton");
        FindButton->setMinimumSize(QSize(150, 40));
        FindButton->setFont(font1);

        horizontalLayout_2->addWidget(FindButton);


        gridLayout->addWidget(groupBox, 1, 0, 1, 7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName("prevButton");
        prevButton->setMinimumSize(QSize(20, 20));
        prevButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        prevButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	background-repeat:no-repeat;\n"
" 	border:none;\n"
" 	background-position:center center;\n"
"}\n"
"QPushButton:hovar{\n"
" 	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
" 	 background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/button/prev.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevButton->setIcon(icon2);
        prevButton->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(prevButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        StopButton = new QPushButton(centralwidget);
        StopButton->setObjectName("StopButton");
        StopButton->setMaximumSize(QSize(30, 30));
        StopButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        StopButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	background-repeat:no-repeat;\n"
" 	border:none;\n"
" 	background-position:center center;\n"
"}\n"
"QPushButton:hovar{\n"
" 	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
" 	 background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/button/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        StopButton->setIcon(icon3);
        StopButton->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(StopButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        NextButton = new QPushButton(centralwidget);
        NextButton->setObjectName("NextButton");
        NextButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        NextButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	background-repeat:no-repeat;\n"
" 	border:none;\n"
" 	background-position:center center;\n"
"}\n"
"QPushButton:hovar{\n"
" 	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
" 	 background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/button/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NextButton->setIcon(icon4);
        NextButton->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(NextButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        ModeButton = new QPushButton(centralwidget);
        ModeButton->setObjectName("ModeButton");
        ModeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ModeButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	background-repeat:no-repeat;\n"
" 	border:none;\n"
" 	background-position:center center;\n"
"}\n"
"QPushButton:hovar{\n"
" 	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
" 	 background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/png/button/order.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ModeButton->setIcon(icon5);
        ModeButton->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(ModeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        volumehorizontalSlider = new QSlider(centralwidget);
        volumehorizontalSlider->setObjectName("volumehorizontalSlider");
        volumehorizontalSlider->setMaximumSize(QSize(100, 20));
        volumehorizontalSlider->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        volumehorizontalSlider->setMaximum(100);
        volumehorizontalSlider->setValue(100);
        volumehorizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_5->addWidget(volumehorizontalSlider);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
""));

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        TotalTimeLabel = new QLabel(centralwidget);
        TotalTimeLabel->setObjectName("TotalTimeLabel");
        TotalTimeLabel->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
""));

        horizontalLayout_4->addWidget(TotalTimeLabel);

        ProgresshorizontalSlider = new QSlider(centralwidget);
        ProgresshorizontalSlider->setObjectName("ProgresshorizontalSlider");
        ProgresshorizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(ProgresshorizontalSlider);

        CurrentTimeLabel = new QLabel(centralwidget);
        CurrentTimeLabel->setObjectName("CurrentTimeLabel");
        CurrentTimeLabel->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
""));

        horizontalLayout_4->addWidget(CurrentTimeLabel);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 7);

        close_pushButton = new QPushButton(centralwidget);
        close_pushButton->setObjectName("close_pushButton");
        close_pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        close_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/button/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        close_pushButton->setIcon(icon6);
        close_pushButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(close_pushButton, 0, 6, 1, 1);

        collect_Button = new QPushButton(centralwidget);
        collect_Button->setObjectName("collect_Button");
        collect_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        collect_Button->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/button/love.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        collect_Button->setIcon(icon7);
        collect_Button->setIconSize(QSize(32, 32));

        gridLayout->addWidget(collect_Button, 0, 2, 1, 1);

        recommend_pushButton = new QPushButton(centralwidget);
        recommend_pushButton->setObjectName("recommend_pushButton");
        recommend_pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        recommend_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/png/button/Ai.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        recommend_pushButton->setIcon(icon8);
        recommend_pushButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(recommend_pushButton, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Windows", nullptr));
        help_pushButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\346\255\214\346\233\262", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\346\255\214\350\257\215", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\347\227\225\350\277\271", nullptr));
        Login_Button->setText(QString());
        groupBox->setTitle(QString());
        Clear_History_Button->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        FindmusicLineEdit->setText(QString());
        FindButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242...", nullptr));
#if QT_CONFIG(tooltip)
        prevButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        prevButton->setText(QString());
#if QT_CONFIG(tooltip)
        StopButton->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234/\346\222\255\346\224\276", nullptr));
#endif // QT_CONFIG(tooltip)
        StopButton->setText(QString());
#if QT_CONFIG(tooltip)
        NextButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        NextButton->setText(QString());
        ModeButton->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200", nullptr));
        CurrentTimeLabel->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200", nullptr));
        close_pushButton->setText(QString());
        collect_Button->setText(QString());
        recommend_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
