/****************************************************************************
** Meta object code from reading C++ file 'workerthreads.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spark-store/workerthreads.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workerthreads.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpkAppInfoLoaderThread_t {
    QByteArrayData data[30];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpkAppInfoLoaderThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpkAppInfoLoaderThread_t qt_meta_stringdata_SpkAppInfoLoaderThread = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SpkAppInfoLoaderThread"
QT_MOC_LITERAL(1, 23, 14), // "requestResetUi"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "requestSetTags"
QT_MOC_LITERAL(4, 54, 12), // "QStringList*"
QT_MOC_LITERAL(5, 67, 7), // "tagList"
QT_MOC_LITERAL(6, 75, 24), // "requestSetAppInformation"
QT_MOC_LITERAL(7, 100, 8), // "QString*"
QT_MOC_LITERAL(8, 109, 4), // "name"
QT_MOC_LITERAL(9, 114, 7), // "details"
QT_MOC_LITERAL(10, 122, 4), // "info"
QT_MOC_LITERAL(11, 127, 7), // "website"
QT_MOC_LITERAL(12, 135, 11), // "packageName"
QT_MOC_LITERAL(13, 147, 5), // "QUrl*"
QT_MOC_LITERAL(14, 153, 7), // "fileUrl"
QT_MOC_LITERAL(15, 161, 11), // "isInstalled"
QT_MOC_LITERAL(16, 173, 16), // "finishedIconLoad"
QT_MOC_LITERAL(17, 190, 8), // "QPixmap*"
QT_MOC_LITERAL(18, 199, 4), // "icon"
QT_MOC_LITERAL(19, 204, 22), // "finishedScreenshotLoad"
QT_MOC_LITERAL(20, 227, 5), // "index"
QT_MOC_LITERAL(21, 233, 16), // "finishAllLoading"
QT_MOC_LITERAL(22, 250, 6), // "setUrl"
QT_MOC_LITERAL(23, 257, 3), // "url"
QT_MOC_LITERAL(24, 261, 9), // "setServer"
QT_MOC_LITERAL(25, 271, 6), // "server"
QT_MOC_LITERAL(26, 278, 16), // "downloadFinished"
QT_MOC_LITERAL(27, 295, 8), // "exitcode"
QT_MOC_LITERAL(28, 304, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(29, 325, 6) // "status"

    },
    "SpkAppInfoLoaderThread\0requestResetUi\0"
    "\0requestSetTags\0QStringList*\0tagList\0"
    "requestSetAppInformation\0QString*\0"
    "name\0details\0info\0website\0packageName\0"
    "QUrl*\0fileUrl\0isInstalled\0finishedIconLoad\0"
    "QPixmap*\0icon\0finishedScreenshotLoad\0"
    "index\0finishAllLoading\0setUrl\0url\0"
    "setServer\0server\0downloadFinished\0"
    "exitcode\0QProcess::ExitStatus\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpkAppInfoLoaderThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       6,    7,   63,    2, 0x06 /* Public */,
      16,    1,   78,    2, 0x06 /* Public */,
      19,    2,   81,    2, 0x06 /* Public */,
      21,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,   87,    2, 0x0a /* Public */,
      24,    1,   90,    2, 0x0a /* Public */,
      26,    2,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 13, QMetaType::Bool,    8,    9,   10,   11,   12,   14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Int,   18,   20,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 28,   27,   29,

       0        // eod
};

void SpkAppInfoLoaderThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpkAppInfoLoaderThread *_t = static_cast<SpkAppInfoLoaderThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestResetUi(); break;
        case 1: _t->requestSetTags((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 2: _t->requestSetAppInformation((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2])),(*reinterpret_cast< QString*(*)>(_a[3])),(*reinterpret_cast< QString*(*)>(_a[4])),(*reinterpret_cast< QString*(*)>(_a[5])),(*reinterpret_cast< QUrl*(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        case 3: _t->finishedIconLoad((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 4: _t->finishedScreenshotLoad((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->finishAllLoading(); break;
        case 6: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 7: _t->setServer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->downloadFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpkAppInfoLoaderThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpkAppInfoLoaderThread::requestResetUi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpkAppInfoLoaderThread::*)(QStringList * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpkAppInfoLoaderThread::requestSetTags)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpkAppInfoLoaderThread::*)(QString * , QString * , QString * , QString * , QString * , QUrl * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpkAppInfoLoaderThread::requestSetAppInformation)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SpkAppInfoLoaderThread::*)(QPixmap * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpkAppInfoLoaderThread::finishedIconLoad)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SpkAppInfoLoaderThread::*)(QPixmap * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpkAppInfoLoaderThread::finishedScreenshotLoad)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SpkAppInfoLoaderThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpkAppInfoLoaderThread::finishAllLoading)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpkAppInfoLoaderThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SpkAppInfoLoaderThread.data,
      qt_meta_data_SpkAppInfoLoaderThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SpkAppInfoLoaderThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpkAppInfoLoaderThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpkAppInfoLoaderThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SpkAppInfoLoaderThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SpkAppInfoLoaderThread::requestResetUi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SpkAppInfoLoaderThread::requestSetTags(QStringList * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpkAppInfoLoaderThread::requestSetAppInformation(QString * _t1, QString * _t2, QString * _t3, QString * _t4, QString * _t5, QUrl * _t6, bool _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SpkAppInfoLoaderThread::finishedIconLoad(QPixmap * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SpkAppInfoLoaderThread::finishedScreenshotLoad(QPixmap * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SpkAppInfoLoaderThread::finishAllLoading()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
