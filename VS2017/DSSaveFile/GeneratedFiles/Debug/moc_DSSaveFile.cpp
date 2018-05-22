/****************************************************************************
** Meta object code from reading C++ file 'DSSaveFile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DSSaveFile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DSSaveFile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DSSaveFile_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DSSaveFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DSSaveFile_t qt_meta_stringdata_DSSaveFile = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DSSaveFile"
QT_MOC_LITERAL(1, 11, 8), // "loadFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "saveFile"
QT_MOC_LITERAL(4, 30, 10), // "renameFile"
QT_MOC_LITERAL(5, 41, 10), // "deleteFile"
QT_MOC_LITERAL(6, 52, 16), // "onProfileChanged"
QT_MOC_LITERAL(7, 69, 5), // "index"
QT_MOC_LITERAL(8, 75, 13), // "onNewFileName"
QT_MOC_LITERAL(9, 89, 1) // "s"

    },
    "DSSaveFile\0loadFile\0\0saveFile\0renameFile\0"
    "deleteFile\0onProfileChanged\0index\0"
    "onNewFileName\0s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DSSaveFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void DSSaveFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DSSaveFile *_t = static_cast<DSSaveFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadFile(); break;
        case 1: _t->saveFile(); break;
        case 2: _t->renameFile(); break;
        case 3: _t->deleteFile(); break;
        case 4: _t->onProfileChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onNewFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DSSaveFile::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DSSaveFile.data,
      qt_meta_data_DSSaveFile,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DSSaveFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DSSaveFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DSSaveFile.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DSSaveFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
