/********************************************************************************
** Form generated from reading UI file 'mainloto.ui'
**
** Created: Sun May 15 22:41:15 2011
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
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
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
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QDateEdit *dateEdit_2;
    QLabel *label_3;
    QPushButton *varButton_2;
    QLabel *label_4;
    QFrame *line;
    QFrame *line_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QSpinBox *spinBox_7;
    QLabel *label_6;
    QSpinBox *spinBox_8;
    QLabel *label_7;
    QSpinBox *spinBox_9;
    QLabel *label_8;
    QSpinBox *spinBox_10;
    QTextBrowser *textBrowser_2;
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
        tabWidget->setGeometry(QRect(10, 10, 631, 361));
        tabWidget->setMinimumSize(QSize(0, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 601, 303));
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
        groupBox_2 = new QGroupBox(tab2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 191, 311));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 101, 20));
        dateEdit_2 = new QDateEdit(groupBox_2);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(10, 270, 110, 22));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 250, 81, 21));
        varButton_2 = new QPushButton(groupBox_2);
        varButton_2->setObjectName(QString::fromUtf8("varButton_2"));
        varButton_2->setGeometry(QRect(10, 220, 75, 23));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 121, 16));
        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 70, 171, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 200, 171, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 40, 188, 22));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(true);
        QFont font;
        font.setKerning(true);
        spinBox->setFont(font);
        spinBox->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox->setWrapping(false);
        spinBox->setFrame(true);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setKeyboardTracking(true);
        spinBox->setMaximum(49);
        spinBox->setSingleStep(1);

        horizontalLayout_2->addWidget(spinBox);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(widget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(widget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_4);

        spinBox_5 = new QSpinBox(widget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_5);

        spinBox_6 = new QSpinBox(widget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_6);

        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(11, 101, 171, 100));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        spinBox_7 = new QSpinBox(widget1);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setEnabled(true);
        spinBox_7->setMinimumSize(QSize(101, 20));
        spinBox_7->setFont(font);
        spinBox_7->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_7->setWrapping(false);
        spinBox_7->setFrame(true);
        spinBox_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_7->setKeyboardTracking(true);
        spinBox_7->setMaximum(999999999);
        spinBox_7->setSingleStep(1);

        gridLayout->addWidget(spinBox_7, 0, 1, 1, 1);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        spinBox_8 = new QSpinBox(widget1);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setEnabled(true);
        spinBox_8->setMinimumSize(QSize(101, 20));
        spinBox_8->setFont(font);
        spinBox_8->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_8->setWrapping(false);
        spinBox_8->setFrame(true);
        spinBox_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_8->setKeyboardTracking(true);
        spinBox_8->setMaximum(999999999);
        spinBox_8->setSingleStep(1);

        gridLayout->addWidget(spinBox_8, 1, 1, 1, 1);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        spinBox_9 = new QSpinBox(widget1);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setEnabled(true);
        spinBox_9->setMinimumSize(QSize(101, 20));
        spinBox_9->setFont(font);
        spinBox_9->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_9->setWrapping(false);
        spinBox_9->setFrame(true);
        spinBox_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_9->setKeyboardTracking(true);
        spinBox_9->setMaximum(999999999);
        spinBox_9->setSingleStep(1);

        gridLayout->addWidget(spinBox_9, 2, 1, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        spinBox_10 = new QSpinBox(widget1);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setEnabled(true);
        spinBox_10->setMinimumSize(QSize(101, 20));
        spinBox_10->setFont(font);
        spinBox_10->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_10->setWrapping(false);
        spinBox_10->setFrame(true);
        spinBox_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10->setKeyboardTracking(true);
        spinBox_10->setMaximum(999999999);
        spinBox_10->setSingleStep(1);

        gridLayout->addWidget(spinBox_10, 3, 1, 1, 1);

        textBrowser_2 = new QTextBrowser(tab2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(240, 20, 361, 301));
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

        tabWidget->setCurrentIndex(1);


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
        groupBox_2->setTitle(QApplication::translate("LotoM", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LotoM", "Extracted Numbers", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LotoM", "Extration Date", 0, QApplication::UnicodeUTF8));
        varButton_2->setText(QApplication::translate("LotoM", "Win Chack ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LotoM", "Win Fonds", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LotoM", "Cat         I", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LotoM", "Cat        II", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LotoM", "Cat       III", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LotoM", "Cat        IV", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("LotoM", "WinChak", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LotoM: public Ui_LotoM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLOTO_H
