/********************************************************************************
** Form generated from reading UI file 'openbilet.ui'
**
** Created: Thu May 19 14:12:54 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENBILET_H
#define UI_OPENBILET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_UOpenBilet
{
public:
    QDialogButtonBox *OpenBox;
    QListWidget *openList;

    void setupUi(QDialog *UOpenBilet)
    {
        if (UOpenBilet->objectName().isEmpty())
            UOpenBilet->setObjectName(QString::fromUtf8("UOpenBilet"));
        UOpenBilet->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        UOpenBilet->setWindowIcon(icon);
        OpenBox = new QDialogButtonBox(UOpenBilet);
        OpenBox->setObjectName(QString::fromUtf8("OpenBox"));
        OpenBox->setGeometry(QRect(30, 250, 341, 32));
        OpenBox->setOrientation(Qt::Horizontal);
        OpenBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Open);
        openList = new QListWidget(UOpenBilet);
        openList->setObjectName(QString::fromUtf8("openList"));
        openList->setGeometry(QRect(10, 10, 381, 231));

        retranslateUi(UOpenBilet);
        QObject::connect(OpenBox, SIGNAL(accepted()), UOpenBilet, SLOT(accept()));
        QObject::connect(OpenBox, SIGNAL(rejected()), UOpenBilet, SLOT(reject()));
        QObject::connect(openList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), UOpenBilet, SLOT(accept()));

        QMetaObject::connectSlotsByName(UOpenBilet);
    } // setupUi

    void retranslateUi(QDialog *UOpenBilet)
    {
        UOpenBilet->setWindowTitle(QApplication::translate("UOpenBilet", "Open", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UOpenBilet: public Ui_UOpenBilet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENBILET_H
