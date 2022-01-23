/****************************************************************************
** Meta object code from reading C++ file 'Jeu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lib/Jeu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Jeu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Jeu_t {
    QByteArrayData data[10];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Jeu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Jeu_t qt_meta_stringdata_Jeu = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Jeu"
QT_MOC_LITERAL(1, 4, 13), // "creer_mechant"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "creer_gentil"
QT_MOC_LITERAL(4, 32, 7), // "maj_Map"
QT_MOC_LITERAL(5, 40, 4), // "play"
QT_MOC_LITERAL(6, 45, 12), // "afficherInfo"
QT_MOC_LITERAL(7, 58, 8), // "gameOver"
QT_MOC_LITERAL(8, 67, 6), // "gagner"
QT_MOC_LITERAL(9, 74, 7) // "rejouer"

    },
    "Jeu\0creer_mechant\0\0creer_gentil\0maj_Map\0"
    "play\0afficherInfo\0gameOver\0gagner\0"
    "rejouer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Jeu[] = {

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
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Jeu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Jeu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->creer_mechant(); break;
        case 1: _t->creer_gentil(); break;
        case 2: _t->maj_Map(); break;
        case 3: _t->play(); break;
        case 4: _t->afficherInfo(); break;
        case 5: _t->gameOver(); break;
        case 6: _t->gagner(); break;
        case 7: _t->rejouer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Jeu::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_Jeu.data,
    qt_meta_data_Jeu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Jeu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Jeu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Jeu.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Jeu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
