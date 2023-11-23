/****************************************************************************
** Meta object code from reading C++ file 'TCPServer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/cw_serv/include/cw_serv/modules/TCPServer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCPServer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPServer_t {
    QByteArrayData data[10];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPServer_t qt_meta_stringdata_TCPServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPServer"
QT_MOC_LITERAL(1, 10, 16), // "MessageForClient"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "message"
QT_MOC_LITERAL(4, 36, 10), // "idOfClient"
QT_MOC_LITERAL(5, 47, 13), // "NewConnection"
QT_MOC_LITERAL(6, 61, 20), // "LogMessageFromClient"
QT_MOC_LITERAL(7, 82, 11), // "std::string"
QT_MOC_LITERAL(8, 94, 8), // "levelLog"
QT_MOC_LITERAL(9, 103, 3) // "Run"

    },
    "TCPServer\0MessageForClient\0\0message\0"
    "idOfClient\0NewConnection\0LogMessageFromClient\0"
    "std::string\0levelLog\0Run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x08 /* Private */,
       6,    2,   40,    2, 0x08 /* Private */,
       9,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    3,    8,
    QMetaType::Void,

       0        // eod
};

void TCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCPServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MessageForClient((*reinterpret_cast< const QJsonObject(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->NewConnection(); break;
        case 2: _t->LogMessageFromClient((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->Run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TCPServer::*)(const QJsonObject & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPServer::MessageForClient)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TCPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<Module::staticMetaObject>(),
    qt_meta_stringdata_TCPServer.data,
    qt_meta_data_TCPServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer.stringdata0))
        return static_cast<void*>(this);
    return Module::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Module::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TCPServer::MessageForClient(const QJsonObject & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
