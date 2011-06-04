/********************************************************************************
** Form generated from reading UI file 'mainloto.ui'
**
** Created: Sat Jun 4 12:07:18 2011
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
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
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionQwit;
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
    QFrame *line;
    QFrame *line_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_11;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_9;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_10;
    QTextBrowser *textBrowser_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
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
        actionOpen = new QAction(LotoM);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(LotoM);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave = new QAction(LotoM);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQwit = new QAction(LotoM);
        actionQwit->setObjectName(QString::fromUtf8("actionQwit"));
        centralWidget = new QWidget(LotoM);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 641, 361));
        tabWidget->setMinimumSize(QSize(0, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 631, 321));
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
        varButton_2->setGeometry(QRect(10, 230, 75, 23));
        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 60, 171, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 210, 171, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 40, 188, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(layoutWidget2);
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

        spinBox_2 = new QSpinBox(layoutWidget2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(layoutWidget2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(layoutWidget2);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_4);

        spinBox_5 = new QSpinBox(layoutWidget2);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_5);

        spinBox_6 = new QSpinBox(layoutWidget2);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(spinBox_6);

        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 81, 160, 126));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(widget);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setEnabled(true);
        doubleSpinBox_11->setMinimumSize(QSize(101, 20));
        doubleSpinBox_11->setFont(font);
        doubleSpinBox_11->setInputMethodHints(Qt::ImhDigitsOnly);
        doubleSpinBox_11->setWrapping(false);
        doubleSpinBox_11->setFrame(true);
        doubleSpinBox_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_11->setKeyboardTracking(true);

        gridLayout->addWidget(doubleSpinBox_11, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(widget);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setEnabled(false);
        doubleSpinBox_7->setMinimumSize(QSize(101, 20));
        doubleSpinBox_7->setFont(font);
        doubleSpinBox_7->setInputMethodHints(Qt::ImhDigitsOnly);
        doubleSpinBox_7->setWrapping(false);
        doubleSpinBox_7->setFrame(true);
        doubleSpinBox_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_7->setKeyboardTracking(true);

        gridLayout->addWidget(doubleSpinBox_7, 1, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(widget);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setEnabled(false);
        doubleSpinBox_8->setMinimumSize(QSize(101, 20));
        doubleSpinBox_8->setFont(font);
        doubleSpinBox_8->setInputMethodHints(Qt::ImhDigitsOnly);
        doubleSpinBox_8->setWrapping(false);
        doubleSpinBox_8->setFrame(true);
        doubleSpinBox_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_8->setKeyboardTracking(true);

        gridLayout->addWidget(doubleSpinBox_8, 2, 1, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(widget);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setEnabled(false);
        doubleSpinBox_9->setMinimumSize(QSize(101, 20));
        doubleSpinBox_9->setFont(font);
        doubleSpinBox_9->setInputMethodHints(Qt::ImhDigitsOnly);
        doubleSpinBox_9->setWrapping(false);
        doubleSpinBox_9->setFrame(true);
        doubleSpinBox_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_9->setKeyboardTracking(true);

        gridLayout->addWidget(doubleSpinBox_9, 3, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(widget);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setEnabled(false);
        doubleSpinBox_10->setMinimumSize(QSize(101, 20));
        doubleSpinBox_10->setFont(font);
        doubleSpinBox_10->setInputMethodHints(Qt::ImhDigitsOnly);
        doubleSpinBox_10->setWrapping(false);
        doubleSpinBox_10->setFrame(true);
        doubleSpinBox_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_10->setKeyboardTracking(true);

        gridLayout->addWidget(doubleSpinBox_10, 4, 1, 1, 1);

        textBrowser_2 = new QTextBrowser(tab2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(240, 20, 361, 301));
        tabWidget->addTab(tab2, QString());
        LotoM->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LotoM);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        LotoM->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LotoM);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        LotoM->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LotoM);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LotoM->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionQwit);
        mainToolBar->addSeparator();

        retranslateUi(LotoM);
        QObject::connect(varButton, SIGNAL(clicked()), textBrowser, SLOT(reload()));
        QObject::connect(ClearButton, SIGNAL(clicked()), textBrowser, SLOT(clear()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LotoM);
    } // setupUi

    void retranslateUi(QMainWindow *LotoM)
    {
        LotoM->setWindowTitle(QApplication::translate("LotoM", "MainLoto", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("LotoM", "Open", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("LotoM", "Close", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("LotoM", "Save", 0, QApplication::UnicodeUTF8));
        actionQwit->setText(QApplication::translate("LotoM", "Qwit", 0, QApplication::UnicodeUTF8));
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
        menuFile->setTitle(QApplication::translate("LotoM", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LotoM: public Ui_LotoM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLOTO_H
