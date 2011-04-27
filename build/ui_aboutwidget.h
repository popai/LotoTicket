/********************************************************************************
** Form generated from reading UI file 'aboutwidget.ui'
**
** Created: Wed Apr 27 21:20:40 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIDGET_H
#define UI_ABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aboutWidget
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *pixIcon;
    QLabel *lblTitle;
    QTextEdit *textEdit;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *okButton;

    void setupUi(QDialog *aboutWidget)
    {
        if (aboutWidget->objectName().isEmpty())
            aboutWidget->setObjectName(QString::fromUtf8("aboutWidget"));
        aboutWidget->resize(360, 330);
        aboutWidget->setMinimumSize(QSize(360, 330));
        aboutWidget->setMaximumSize(QSize(360, 330));
        vboxLayout = new QVBoxLayout(aboutWidget);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(8, 8, 8, 8);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        pixIcon = new QLabel(aboutWidget);
        pixIcon->setObjectName(QString::fromUtf8("pixIcon"));
        pixIcon->setMinimumSize(QSize(70, 70));
        pixIcon->setMaximumSize(QSize(70, 70));
        pixIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/cdfly.png")));

        hboxLayout->addWidget(pixIcon);

        lblTitle = new QLabel(aboutWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));

        hboxLayout->addWidget(lblTitle);


        vboxLayout->addLayout(hboxLayout);

        textEdit = new QTextEdit(aboutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        textEdit->setFont(font);
        textEdit->setReadOnly(true);

        vboxLayout->addWidget(textEdit);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        okButton = new QPushButton(aboutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout1->addWidget(okButton);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(aboutWidget);
        QObject::connect(okButton, SIGNAL(clicked()), aboutWidget, SLOT(accept()));

        QMetaObject::connectSlotsByName(aboutWidget);
    } // setupUi

    void retranslateUi(QDialog *aboutWidget)
    {
        aboutWidget->setWindowTitle(QApplication::translate("aboutWidget", "About CdFly", 0, QApplication::UnicodeUTF8));
        pixIcon->setText(QString());
        lblTitle->setText(QApplication::translate("aboutWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:28pt; font-weight:600;\">Bilet Loto</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:12pt; font-weight:600;\">by Popai</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("aboutWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("aboutWidget", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class aboutWidget: public Ui_aboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
