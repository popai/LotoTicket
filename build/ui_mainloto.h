/********************************************************************************
** Form generated from reading UI file 'mainloto.ui'
**
** Created: Tue Apr 26 21:01:37 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINLOTO_H
#define UI_MAINLOTO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LotoM
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QDateEdit *dateEdit;
    QPushButton *ClearButton;
    QPushButton *varButton;
    QLabel *label;
    QGroupBox *QicPicBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxA;
    QCheckBox *checkBoxB;
    QCheckBox *checkBoxC;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser;
    QWidget *tab2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LotoM)
    {
        if (LotoM->objectName().isEmpty())
            LotoM->setObjectName(QString::fromUtf8("LotoM"));
        LotoM->setWindowModality(Qt::ApplicationModal);
        LotoM->resize(650, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LotoM->sizePolicy().hasHeightForWidth());
        LotoM->setSizePolicy(sizePolicy);
        LotoM->setMinimumSize(QSize(650, 430));
        LotoM->setMaximumSize(QSize(650, 430));
        centralWidget = new QWidget(LotoM);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 531, 361));
        tabWidget->setMinimumSize(QSize(0, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 511, 303));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(128, 288));
        groupBox->setMaximumSize(QSize(120, 16777215));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(10, 250, 110, 22));
        ClearButton = new QPushButton(groupBox);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setGeometry(QRect(10, 20, 75, 23));
        varButton = new QPushButton(groupBox);
        varButton->setObjectName(QString::fromUtf8("varButton"));
        varButton->setGeometry(QRect(10, 50, 75, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 230, 81, 16));
        QicPicBox = new QGroupBox(groupBox);
        QicPicBox->setObjectName(QString::fromUtf8("QicPicBox"));
        QicPicBox->setGeometry(QRect(10, 90, 91, 121));
        layoutWidget1 = new QWidget(QicPicBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 21, 77, 94));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxA = new QCheckBox(layoutWidget1);
        checkBoxA->setObjectName(QString::fromUtf8("checkBoxA"));

        verticalLayout->addWidget(checkBoxA);

        checkBoxB = new QCheckBox(layoutWidget1);
        checkBoxB->setObjectName(QString::fromUtf8("checkBoxB"));

        verticalLayout->addWidget(checkBoxB);

        checkBoxC = new QCheckBox(layoutWidget1);
        checkBoxC->setObjectName(QString::fromUtf8("checkBoxC"));

        verticalLayout->addWidget(checkBoxC);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(textBrowser);

        tabWidget->addTab(tab, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        tabWidget->addTab(tab2, QString());
        LotoM->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LotoM);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 20));
        LotoM->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LotoM);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LotoM->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LotoM);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LotoM->setStatusBar(statusBar);

        retranslateUi(LotoM);
        QObject::connect(varButton, SIGNAL(clicked()), textBrowser, SLOT(reload()));
        QObject::connect(ClearButton, SIGNAL(clicked()), textBrowser, SLOT(clear()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LotoM);
    } // setupUi

    void retranslateUi(QMainWindow *LotoM)
    {
        LotoM->setWindowTitle(QApplication::translate("LotoM", "MainLoto", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LotoM", "GroupBox", 0, QApplication::UnicodeUTF8));
        ClearButton->setText(QApplication::translate("LotoM", "ClearTiket", 0, QApplication::UnicodeUTF8));
        varButton->setText(QApplication::translate("LotoM", "ViewVar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LotoM", "Set game date", 0, QApplication::UnicodeUTF8));
        QicPicBox->setTitle(QApplication::translate("LotoM", "QuickPick", 0, QApplication::UnicodeUTF8));
        checkBoxA->setText(QApplication::translate("LotoM", "camp A", 0, QApplication::UnicodeUTF8));
        checkBoxB->setText(QApplication::translate("LotoM", "camp B", 0, QApplication::UnicodeUTF8));
        checkBoxC->setText(QApplication::translate("LotoM", "camp C", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LotoM", "PushButton", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LotoM", "CreateTiket", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("LotoM", "WinChak", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LotoM: public Ui_LotoM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLOTO_H
