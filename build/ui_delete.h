/********************************************************************************
** Form generated from reading UI file 'delete.ui'
**
** Created: Tue Jun 7 17:56:52 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Delete
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *deleteList;

    void setupUi(QDialog *Delete)
    {
        if (Delete->objectName().isEmpty())
            Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        Delete->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Delete);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        deleteList = new QListWidget(Delete);
        deleteList->setObjectName(QString::fromUtf8("deleteList"));
        deleteList->setGeometry(QRect(10, 10, 381, 221));

        retranslateUi(Delete);
        QObject::connect(buttonBox, SIGNAL(accepted()), Delete, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Delete, SLOT(reject()));
        QObject::connect(deleteList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), Delete, SLOT(accept()));

        QMetaObject::connectSlotsByName(Delete);
    } // setupUi

    void retranslateUi(QDialog *Delete)
    {
        Delete->setWindowTitle(QApplication::translate("Delete", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Delete: public Ui_Delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
