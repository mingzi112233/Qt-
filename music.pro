QT       += core gui network sql multimedia multimediawidgets widgets concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ai.cpp \
    collect_music.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    reset_pwd.cpp

HEADERS += \
    ai.h \
    collect_music.h \
    login.h \
    mainwindow.h \
    register.h \
    reset_pwd.h

FORMS += \
    AI.ui \
    Collect_Music.ui \
    Login.ui \
    Register.ui \
    ResetPwd.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(smtp/smtp.pri)

RESOURCES += \
    res.qrc

DISTFILES +=
