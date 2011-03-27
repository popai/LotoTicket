/********************************************************************************
** Form generated from reading UI file 'setdata.ui'
**
** Created: Tue Apr 26 19:18:17 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDATA_H
#define UI_SETDATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SetData
{
public:
    QDateEdit *dateEdit;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *SetData)
    {
        if (SetData->objectName().isEmpty())
            SetData->setObjectName(QString::fromUtf8("SetData"));
        SetData->resize(232, 194);
        dateEdit = new QDateEdit(SetData);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(10, 170, 110, 22));
        calendarWidget = new QCalendarWidget(SetData);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 232, 161));

        retranslateUi(SetData);

        QMetaObject::connectSlotsByName(SetData);
    } // setupUi

    void retranslateUi(QDialog *SetData)
    {
        SetData->setWindowTitle(QApplication::translate("SetData", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetData: public Ui_SetData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDATA_H
