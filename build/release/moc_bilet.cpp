/****************************************************************************
** Meta object code from reading C++ file 'bilet.h'
**
** Created: Tue May 24 12:26:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/bilet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bilet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bilet[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,    6,    6,    6, 0x0a,
      38,    6,    6,    6, 0x0a,
      50,    6,    6,    6, 0x0a,
      62,    6,    6,    6, 0x0a,
      75,    6,    6,    6, 0x0a,
      88,    6,    6,    6, 0x0a,
     101,    6,    6,    6, 0x0a,
     118,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Bilet[] = {
    "Bilet\0\0SelectionChanged()\0nrSelectA()\0"
    "nrSelectB()\0nrSelectC()\0codSelectA()\0"
    "codSelectB()\0codSelectC()\0clearSelection()\0"
    "setCod()\0"
};

const QMetaObject Bilet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Bilet,
      qt_meta_data_Bilet, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bilet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bilet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bilet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bilet))
        return static_cast<void*>(const_cast< Bilet*>(this));
    return QWidget::qt_metacast(_clname);
}

int Bilet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SelectionChanged(); break;
        case 1: nrSelectA(); break;
        case 2: nrSelectB(); break;
        case 3: nrSelectC(); break;
        case 4: codSelectA(); break;
        case 5: codSelectB(); break;
        case 6: codSelectC(); break;
        case 7: clearSelection(); break;
        case 8: setCod(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Bilet::SelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
