/********************************************************************************
** Form generated from reading UI file 'savebilet.ui'
**
** Created: Tue Apr 26 19:18:17 2011
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
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveBilet
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *saveName;
    QTableWidget *tableWidget;

    void setupUi(QDialog *SaveBilet)
    {
        if (SaveBilet->objectName().isEmpty())
            SaveBilet->setObjectName(QString::fromUtf8("SaveBilet"));
        SaveBilet->resize(391, 298);
        buttonBox = new QDialogButtonBox(SaveBilet);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        saveName = new QLineEdit(SaveBilet);
        saveName->setObjectName(QString::fromUtf8("saveName"));
        saveName->setGeometry(QRect(10, 220, 371, 21));
        tableWidget = new QTableWidget(SaveBilet);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 371, 191));

        retranslateUi(SaveBilet);
        QObject::connect(buttonBox, SIGNAL(accepted()), SaveBilet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SaveBilet, SLOT(reject()));

        QMetaObject::connectSlotsByName(SaveBilet);
    } // setupUi

    void retranslateUi(QDialog *SaveBilet)
    {
        SaveBilet->setWindowTitle(QApplication::translate("SaveBilet", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SaveBilet", "BieltID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SaveBilet", "DATA", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaveBilet: public Ui_SaveBilet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEBILET_H
