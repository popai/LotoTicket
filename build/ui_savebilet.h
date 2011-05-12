/********************************************************************************
** Form generated from reading UI file 'savebilet.ui'
**
** Created: Thu May 12 13:32:13 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEBILET_H
#define UI_SAVEBILET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_USaveBilet
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *saveName;
    QListWidget *saveList;

    void setupUi(QDialog *USaveBilet)
    {
        if (USaveBilet->objectName().isEmpty())
            USaveBilet->setObjectName(QString::fromUtf8("USaveBilet"));
        USaveBilet->resize(391, 298);
        buttonBox = new QDialogButtonBox(USaveBilet);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        saveName = new QLineEdit(USaveBilet);
        saveName->setObjectName(QString::fromUtf8("saveName"));
        saveName->setGeometry(QRect(10, 220, 371, 21));
        saveList = new QListWidget(USaveBilet);
        saveList->setObjectName(QString::fromUtf8("saveList"));
        saveList->setGeometry(QRect(10, 10, 371, 201));

        retranslateUi(USaveBilet);
        QObject::connect(buttonBox, SIGNAL(accepted()), USaveBilet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), USaveBilet, SLOT(reject()));

        QMetaObject::connectSlotsByName(USaveBilet);
    } // setupUi

    void retranslateUi(QDialog *USaveBilet)
    {
        USaveBilet->setWindowTitle(QApplication::translate("USaveBilet", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class USaveBilet: public Ui_USaveBilet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEBILET_H
