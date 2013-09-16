/****************************************************************************
** Meta object code from reading C++ file 'chunkcontent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/chunkcontent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chunkcontent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chunkcontent_t {
    QByteArrayData data[11];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_chunkcontent_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_chunkcontent_t qt_meta_stringdata_chunkcontent = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 19),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 11),
QT_MOC_LITERAL(4, 46, 6),
QT_MOC_LITERAL(5, 53, 3),
QT_MOC_LITERAL(6, 57, 12),
QT_MOC_LITERAL(7, 70, 19),
QT_MOC_LITERAL(8, 90, 16),
QT_MOC_LITERAL(9, 107, 14),
QT_MOC_LITERAL(10, 122, 1)
    },
    "chunkcontent\0refresh_buildingdsc\0\0"
    "change_cont\0chunk*\0chp\0change_chunk\0"
    "change_building_dsc\0found_settlement\0"
    "button_clicked\0i\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chunkcontent[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a,
       6,    1,   48,    2, 0x0a,
       7,    1,   51,    2, 0x0a,
       8,    0,   54,    2, 0x0a,
       9,    1,   55,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void chunkcontent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chunkcontent *_t = static_cast<chunkcontent *>(_o);
        switch (_id) {
        case 0: _t->refresh_buildingdsc(); break;
        case 1: _t->change_cont((*reinterpret_cast< chunk*(*)>(_a[1]))); break;
        case 2: _t->change_chunk((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->change_building_dsc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->found_settlement(); break;
        case 5: _t->button_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chunkcontent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chunkcontent::refresh_buildingdsc)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject chunkcontent::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chunkcontent.data,
      qt_meta_data_chunkcontent,  qt_static_metacall, 0, 0}
};


const QMetaObject *chunkcontent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chunkcontent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chunkcontent.stringdata))
        return static_cast<void*>(const_cast< chunkcontent*>(this));
    return QWidget::qt_metacast(_clname);
}

int chunkcontent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void chunkcontent::refresh_buildingdsc()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
