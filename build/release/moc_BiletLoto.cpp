/****************************************************************************
** Meta object code from reading C++ file 'BiletLoto.h'
**
** Created: Thu Apr 28 10:55:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/BiletLoto.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BiletLoto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BiletMain[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      27,   10,   10,   10, 0x0a,
      42,   10,   10,   10, 0x0a,
      64,   10,   10,   10, 0x0a,
      82,   10,   10,   10, 0x0a,
     102,   10,   10,   10, 0x0a,
     120,   10,   10,   10, 0x0a,
     138,   10,   10,   10, 0x0a,
     155,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BiletMain[] = {
    "BiletMain\0\0writeVariante()\0aboutClicked()\0"
    "editSettingsClicked()\0editFindClicked()\0"
    "editDeleteClicked()\0fileExitClicked()\0"
    "fileOpenClicked()\0fileNewClicked()\0"
    "fileSaveClicked()\0"
};

const QMetaObject BiletMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BiletMain,
      qt_meta_data_BiletMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BiletMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BiletMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BiletMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BiletMain))
        return static_cast<void*>(const_cast< BiletMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BiletMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: writeVariante(); break;
        case 1: aboutClicked(); break;
        case 2: editSettingsClicked(); break;
        case 3: editFindClicked(); break;
        case 4: editDeleteClicked(); break;
        case 5: fileExitClicked(); break;
        case 6: fileOpenClicked(); break;
        case 7: fileNewClicked(); break;
        case 8: fileSaveClicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
