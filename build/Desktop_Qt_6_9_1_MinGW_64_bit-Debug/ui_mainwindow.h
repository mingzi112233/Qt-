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
#include <QtWidgets/QFrame>
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
    QGridLayout *gridLayout_3;
    QPushButton *Login_Button;
    QPushButton *close_pushButton;
    QPushButton *recommend_pushButton;
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
    QFrame *playBarContainer;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *ModeButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *NextButton_2;
    QSlider *volumehorizontalSlider;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *TotalTimeLabel;
    QSlider *ProgresshorizontalSlider;
    QLabel *CurrentTimeLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *StopButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *NextButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *NextMusicListButton;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *Clear_History_Button;
    QLineEdit *FindmusicLineEdit;
    QPushButton *FindButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *help_pushButton;
    QPushButton *collect_Button;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(838, 706);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/button/help.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
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

        gridLayout_3->addWidget(Login_Button, 0, 4, 1, 1);

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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/button/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        close_pushButton->setIcon(icon2);
        close_pushButton->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(close_pushButton, 0, 6, 1, 1);

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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/button/Ai.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        recommend_pushButton->setIcon(icon3);
        recommend_pushButton->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(recommend_pushButton, 0, 2, 1, 1);

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


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 7);

        playBarContainer = new QFrame(centralwidget);
        playBarContainer->setObjectName("playBarContainer");
        playBarContainer->setFrameShape(QFrame::Shape::StyledPanel);
        playBarContainer->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(playBarContainer);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        ModeButton = new QPushButton(playBarContainer);
        ModeButton->setObjectName("ModeButton");
        ModeButton->setMinimumSize(QSize(20, 20));
        ModeButton->setMaximumSize(QSize(30, 30));
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("png/button/order.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ModeButton->setIcon(icon4);
        ModeButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(ModeButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        NextButton_2 = new QPushButton(playBarContainer);
        NextButton_2->setObjectName("NextButton_2");
        NextButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        NextButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        icon5.addFile(QString::fromUtf8(":/png/button/speaker.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NextButton_2->setIcon(icon5);
        NextButton_2->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(NextButton_2);

        volumehorizontalSlider = new QSlider(playBarContainer);
        volumehorizontalSlider->setObjectName("volumehorizontalSlider");
        volumehorizontalSlider->setMaximumSize(QSize(100, 20));
        volumehorizontalSlider->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        volumehorizontalSlider->setMaximum(100);
        volumehorizontalSlider->setValue(100);
        volumehorizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_8->addWidget(volumehorizontalSlider);

        label_6 = new QLabel(playBarContainer);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
""));

        horizontalLayout_8->addWidget(label_6);


        gridLayout->addLayout(horizontalLayout_8, 0, 4, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        TotalTimeLabel = new QLabel(playBarContainer);
        TotalTimeLabel->setObjectName("TotalTimeLabel");
        TotalTimeLabel->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
""));

        horizontalLayout_10->addWidget(TotalTimeLabel);

        ProgresshorizontalSlider = new QSlider(playBarContainer);
        ProgresshorizontalSlider->setObjectName("ProgresshorizontalSlider");
        ProgresshorizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_10->addWidget(ProgresshorizontalSlider);

        CurrentTimeLabel = new QLabel(playBarContainer);
        CurrentTimeLabel->setObjectName("CurrentTimeLabel");
        CurrentTimeLabel->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
""));

        horizontalLayout_10->addWidget(CurrentTimeLabel);


        gridLayout->addLayout(horizontalLayout_10, 1, 0, 1, 7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        prevButton = new QPushButton(playBarContainer);
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/button/prev.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevButton->setIcon(icon6);
        prevButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(prevButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        StopButton = new QPushButton(playBarContainer);
        StopButton->setObjectName("StopButton");
        StopButton->setMaximumSize(QSize(35, 35));
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/button/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        StopButton->setIcon(icon7);
        StopButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(StopButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        NextButton = new QPushButton(playBarContainer);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/png/button/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NextButton->setIcon(icon8);
        NextButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(NextButton);


        gridLayout->addLayout(horizontalLayout, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        NextMusicListButton = new QPushButton(playBarContainer);
        NextMusicListButton->setObjectName("NextMusicListButton");
        NextMusicListButton->setMinimumSize(QSize(20, 20));
        NextMusicListButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        NextMusicListButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/png/button/list.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NextMusicListButton->setIcon(icon9);
        NextMusicListButton->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(NextMusicListButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_4, 0, 6, 1, 1);


        gridLayout_3->addWidget(playBarContainer, 3, 0, 1, 7);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        Clear_History_Button = new QPushButton(groupBox);
        Clear_History_Button->setObjectName("Clear_History_Button");
        Clear_History_Button->setMinimumSize(QSize(150, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        Clear_History_Button->setFont(font1);
        Clear_History_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout_2->addWidget(Clear_History_Button, 0, 0, 1, 1);

        FindmusicLineEdit = new QLineEdit(groupBox);
        FindmusicLineEdit->setObjectName("FindmusicLineEdit");
        FindmusicLineEdit->setMinimumSize(QSize(0, 40));
        FindmusicLineEdit->setFont(font1);

        gridLayout_2->addWidget(FindmusicLineEdit, 0, 1, 1, 1);

        FindButton = new QPushButton(groupBox);
        FindButton->setObjectName("FindButton");
        FindButton->setMinimumSize(QSize(150, 40));
        FindButton->setFont(font1);
        FindButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout_2->addWidget(FindButton, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 7);

        horizontalSpacer_9 = new QSpacerItem(636, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 0, 0, 1, 1);

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

        gridLayout_3->addWidget(help_pushButton, 0, 5, 1, 1);

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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/png/button/love.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        collect_Button->setIcon(icon10);
        collect_Button->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(collect_Button, 0, 1, 1, 1);

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
        Login_Button->setText(QString());
        close_pushButton->setText(QString());
        recommend_pushButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\346\255\214\346\233\262", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\346\255\214\350\257\215", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\347\227\225\350\277\271", nullptr));
#if QT_CONFIG(tooltip)
        ModeButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        ModeButton->setText(QString());
#if QT_CONFIG(tooltip)
        NextButton_2->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        NextButton_2->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200", nullptr));
        CurrentTimeLabel->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200", nullptr));
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
        NextMusicListButton->setText(QString());
        groupBox->setTitle(QString());
        Clear_History_Button->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        FindmusicLineEdit->setText(QCoreApplication::translate("MainWindow", "\345\205\215\350\264\271", nullptr));
        FindButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242...", nullptr));
        help_pushButton->setText(QString());
        collect_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
