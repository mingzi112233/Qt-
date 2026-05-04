/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "finish",
        "",
        "lyricShow",
        "firstClicke",
        "SetCollectText",
        "name",
        "updateList",
        "on_close_pushButton_clicked",
        "on_prevButton_clicked",
        "on_StopButton_clicked",
        "on_NextButton_clicked",
        "on_ModeButton_clicked",
        "on_volumehorizontalSlider_valueChanged",
        "value",
        "on_ProgresshorizontalSlider_valueChanged",
        "updateDuration",
        "netReply",
        "QNetworkReply*",
        "lyricTextShow",
        "role",
        "content",
        "SendMusicTitle",
        "downloadPlayer",
        "hash",
        "handleDeepSeekReply",
        "reply",
        "on_FindButton_clicked",
        "processAiRecommendations",
        "names",
        "on_help_pushButton_clicked",
        "showSearchContextMenu",
        "pos",
        "handleFavoriteLogic",
        "QListWidgetItem*",
        "item",
        "handleNextPlayLogic",
        "handleLoginSuccess",
        "username",
        "backgrouptoDefault",
        "ReadHistoryList",
        "on_sky_pushButton_clicked",
        "startPlay",
        "JsonData",
        "handleMediaStatusChanged",
        "QMediaPlayer::MediaStatus",
        "status",
        "GetCurrentRow",
        "playFindMusic",
        "downloadFile",
        "url",
        "savePath",
        "deleteLastDownloadedFile",
        "on_recommend_pushButton_clicked",
        "on_Clear_History_Button_clicked",
        "on_HistoryMusiclistWidget_itemDoubleClicked",
        "on_Login_Button_clicked",
        "on_collect_Button_clicked",
        "on_NextMusicListButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'finish'
        QtMocHelpers::SignalData<void(QByteArray)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 2 },
        }}),
        // Signal 'lyricShow'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'firstClicke'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'SetCollectText'
        QtMocHelpers::SignalData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Signal 'updateList'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_close_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_prevButton_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_StopButton_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_NextButton_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ModeButton_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volumehorizontalSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'on_ProgresshorizontalSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'updateDuration'
        QtMocHelpers::SlotData<void(qint64)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 14 },
        }}),
        // Slot 'netReply'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 2 },
        }}),
        // Slot 'lyricTextShow'
        QtMocHelpers::SlotData<void(QString, QString)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 20 }, { QMetaType::QString, 21 },
        }}),
        // Slot 'SendMusicTitle'
        QtMocHelpers::SlotData<void(QString, QString)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'downloadPlayer'
        QtMocHelpers::SlotData<void(QString)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 24 },
        }}),
        // Slot 'handleDeepSeekReply'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 26 },
        }}),
        // Slot 'on_FindButton_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'processAiRecommendations'
        QtMocHelpers::SlotData<void(QStringList)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 29 },
        }}),
        // Slot 'on_help_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showSearchContextMenu'
        QtMocHelpers::SlotData<void(const QPoint &)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QPoint, 32 },
        }}),
        // Slot 'handleFavoriteLogic'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 34, 35 },
        }}),
        // Slot 'handleNextPlayLogic'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 34, 35 },
        }}),
        // Slot 'handleLoginSuccess'
        QtMocHelpers::SlotData<void(QString)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 38 },
        }}),
        // Slot 'backgrouptoDefault'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'ReadHistoryList'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sky_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'startPlay'
        QtMocHelpers::SlotData<void(QString)>(42, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 43 },
        }}),
        // Slot 'handleMediaStatusChanged'
        QtMocHelpers::SlotData<void(QMediaPlayer::MediaStatus)>(44, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 45, 46 },
        }}),
        // Slot 'GetCurrentRow'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'playFindMusic'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'downloadFile'
        QtMocHelpers::SlotData<bool(const QString &, const QString &)>(49, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { QMetaType::QString, 50 }, { QMetaType::QString, 51 },
        }}),
        // Slot 'deleteLastDownloadedFile'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_recommend_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_Clear_History_Button_clicked'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_HistoryMusiclistWidget_itemDoubleClicked'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(55, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 34, 35 },
        }}),
        // Slot 'on_Login_Button_clicked'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_collect_Button_clicked'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_NextMusicListButton_clicked'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->finish((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->lyricShow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->firstClicke(); break;
        case 3: _t->SetCollectText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->updateList(); break;
        case 5: _t->on_close_pushButton_clicked(); break;
        case 6: _t->on_prevButton_clicked(); break;
        case 7: _t->on_StopButton_clicked(); break;
        case 8: _t->on_NextButton_clicked(); break;
        case 9: _t->on_ModeButton_clicked(); break;
        case 10: _t->on_volumehorizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_ProgresshorizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->updateDuration((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 13: _t->netReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 14: _t->lyricTextShow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->SendMusicTitle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->downloadPlayer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->handleDeepSeekReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 18: _t->on_FindButton_clicked(); break;
        case 19: _t->processAiRecommendations((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 20: _t->on_help_pushButton_clicked(); break;
        case 21: _t->showSearchContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 22: _t->handleFavoriteLogic((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 23: _t->handleNextPlayLogic((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 24: _t->handleLoginSuccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->backgrouptoDefault(); break;
        case 26: _t->ReadHistoryList(); break;
        case 27: _t->on_sky_pushButton_clicked(); break;
        case 28: _t->startPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->handleMediaStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 30: _t->GetCurrentRow(); break;
        case 31: _t->playFindMusic(); break;
        case 32: { bool _r = _t->downloadFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->deleteLastDownloadedFile(); break;
        case 34: _t->on_recommend_pushButton_clicked(); break;
        case 35: _t->on_Clear_History_Button_clicked(); break;
        case 36: _t->on_HistoryMusiclistWidget_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 37: _t->on_Login_Button_clicked(); break;
        case 38: _t->on_collect_Button_clicked(); break;
        case 39: _t->on_NextMusicListButton_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QByteArray )>(_a, &MainWindow::finish, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QString )>(_a, &MainWindow::lyricShow, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::firstClicke, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(QString )>(_a, &MainWindow::SetCollectText, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::updateList, 4))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::finish(QByteArray _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MainWindow::lyricShow(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void MainWindow::firstClicke()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::SetCollectText(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void MainWindow::updateList()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
