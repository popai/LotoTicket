/********************************************************************************
** Form generated from reading UI file 'codlist.ui'
**
** Created: Tue Jun 7 17:58:26 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODLIST_H
#define UI_CODLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_CodeList
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWizardPage *CodeList)
    {
        if (CodeList->objectName().isEmpty())
            CodeList->setObjectName(QString::fromUtf8("CodeList"));
        CodeList->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/table.png"), QSize(), QIcon::Normal, QIcon::Off);
        CodeList->setWindowIcon(icon);
        textBrowser = new QTextBrowser(CodeList);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(CodeList);

        QMetaObject::connectSlotsByName(CodeList);
    } // setupUi

    void retranslateUi(QWizardPage *CodeList)
    {
        CodeList->setWindowTitle(QApplication::translate("CodeList", "Code List", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CodeList: public Ui_CodeList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODLIST_H
