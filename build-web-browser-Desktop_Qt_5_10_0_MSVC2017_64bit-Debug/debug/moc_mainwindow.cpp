/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../web-browser/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "NewTab"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 3), // "url"
QT_MOC_LITERAL(4, 23, 8), // "CloseTab"
QT_MOC_LITERAL(5, 32, 8), // "GoToPage"
QT_MOC_LITERAL(6, 41, 16), // "GoToPreviousPage"
QT_MOC_LITERAL(7, 58, 12), // "GoToNextPage"
QT_MOC_LITERAL(8, 71, 12), // "GoToHomePage"
QT_MOC_LITERAL(9, 84, 11), // "StopLoading"
QT_MOC_LITERAL(10, 96, 11), // "RefreshPage"
QT_MOC_LITERAL(11, 108, 5), // "About"
QT_MOC_LITERAL(12, 114, 14), // "LoadingStarted"
QT_MOC_LITERAL(13, 129, 17), // "LoadingInProgress"
QT_MOC_LITERAL(14, 147, 11), // "pourcentage"
QT_MOC_LITERAL(15, 159, 15), // "LoadingFinished"
QT_MOC_LITERAL(16, 175, 2), // "ok"
QT_MOC_LITERAL(17, 178, 11), // "ChangeTitle"
QT_MOC_LITERAL(18, 190, 5), // "title"
QT_MOC_LITERAL(19, 196, 9), // "ChangeUrl"
QT_MOC_LITERAL(20, 206, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(21, 234, 5) // "index"

    },
    "MainWindow\0NewTab\0\0url\0CloseTab\0"
    "GoToPage\0GoToPreviousPage\0GoToNextPage\0"
    "GoToHomePage\0StopLoading\0RefreshPage\0"
    "About\0LoadingStarted\0LoadingInProgress\0"
    "pourcentage\0LoadingFinished\0ok\0"
    "ChangeTitle\0title\0ChangeUrl\0"
    "on_tabWidget_currentChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       1,    0,   97,    2, 0x28 /* Private | MethodCloned */,
       4,    0,   98,    2, 0x08 /* Private */,
       5,    0,   99,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,
      19,    1,  116,    2, 0x08 /* Private */,
      20,    1,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, QMetaType::Int,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->NewTab(); break;
        case 2: _t->CloseTab(); break;
        case 3: _t->GoToPage(); break;
        case 4: _t->GoToPreviousPage(); break;
        case 5: _t->GoToNextPage(); break;
        case 6: _t->GoToHomePage(); break;
        case 7: _t->StopLoading(); break;
        case 8: _t->RefreshPage(); break;
        case 9: _t->About(); break;
        case 10: _t->LoadingStarted(); break;
        case 11: _t->LoadingInProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->LoadingFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->ChangeTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->ChangeUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 15: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
