/****************************************************************************
** Meta object code from reading C++ file 'QtWidgetsApplication3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QtWidgetsApplication3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtWidgetsApplication3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtWidgetsApplication3_t {
    QByteArrayData data[7];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtWidgetsApplication3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtWidgetsApplication3_t qt_meta_stringdata_QtWidgetsApplication3 = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QtWidgetsApplication3"
QT_MOC_LITERAL(1, 22, 26), // "on_buttonAddVehicleClicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 7), // "checked"
QT_MOC_LITERAL(4, 58, 29), // "on_buttonAddParkingLotClicked"
QT_MOC_LITERAL(5, 88, 25), // "on_buttonAddTicketClicked"
QT_MOC_LITERAL(6, 114, 22) // "on_buttonIncomeClicked"

    },
    "QtWidgetsApplication3\0on_buttonAddVehicleClicked\0"
    "\0checked\0on_buttonAddParkingLotClicked\0"
    "on_buttonAddTicketClicked\0"
    "on_buttonIncomeClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtWidgetsApplication3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       1,    0,   57,    2, 0x2a /* Public | MethodCloned */,
       4,    1,   58,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x2a /* Public | MethodCloned */,
       5,    1,   62,    2, 0x0a /* Public */,
       5,    0,   65,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   66,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void QtWidgetsApplication3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtWidgetsApplication3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonAddVehicleClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_buttonAddVehicleClicked(); break;
        case 2: _t->on_buttonAddParkingLotClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_buttonAddParkingLotClicked(); break;
        case 4: _t->on_buttonAddTicketClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_buttonAddTicketClicked(); break;
        case 6: _t->on_buttonIncomeClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_buttonIncomeClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtWidgetsApplication3::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QtWidgetsApplication3.data,
    qt_meta_data_QtWidgetsApplication3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtWidgetsApplication3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtWidgetsApplication3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtWidgetsApplication3.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtWidgetsApplication3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
