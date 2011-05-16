/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created: Mon May 16 12:01:50 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingWidget
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *tabWidget;
    QWidget *tabGeneral;
    QVBoxLayout *vboxLayout1;
    QLabel *label;
    QComboBox *cmbLocale;
    QSpacerItem *spacerItem;
    QWidget *tabStart;
    QVBoxLayout *vboxLayout2;
    QGroupBox *grpOnStart;
    QVBoxLayout *vboxLayout3;
    QRadioButton *radStartLast;
    QRadioButton *radStartSpecified;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem1;
    QLineEdit *txtStart;
    QToolButton *btnBrowseKat;
    QRadioButton *radStartBlank;
    QSpacerItem *spacerItem2;
    QWidget *tabLoteri;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout1;
    QLabel *LotoName;
    QLineEdit *lotoName;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *MaxNr;
    QSpacerItem *horizontalSpacer;
    QSpinBox *extractNr;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *maxNr;
    QHBoxLayout *hboxLayout2;
    QPushButton *buttonHelp;
    QSpacerItem *spacerItem3;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *settingWidget)
    {
        if (settingWidget->objectName().isEmpty())
            settingWidget->setObjectName(QString::fromUtf8("settingWidget"));
        settingWidget->resize(416, 287);
        vboxLayout = new QVBoxLayout(settingWidget);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(8, 8, 8, 8);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        tabWidget = new QTabWidget(settingWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QString::fromUtf8("tabGeneral"));
        vboxLayout1 = new QVBoxLayout(tabGeneral);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(8, 8, 8, 8);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        label = new QLabel(tabGeneral);
        label->setObjectName(QString::fromUtf8("label"));

        vboxLayout1->addWidget(label);

        cmbLocale = new QComboBox(tabGeneral);
        cmbLocale->setObjectName(QString::fromUtf8("cmbLocale"));

        vboxLayout1->addWidget(cmbLocale);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);

        tabWidget->addTab(tabGeneral, QString());
        tabStart = new QWidget();
        tabStart->setObjectName(QString::fromUtf8("tabStart"));
        vboxLayout2 = new QVBoxLayout(tabStart);
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(8, 8, 8, 8);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        grpOnStart = new QGroupBox(tabStart);
        grpOnStart->setObjectName(QString::fromUtf8("grpOnStart"));
        vboxLayout3 = new QVBoxLayout(grpOnStart);
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
        vboxLayout3->setContentsMargins(8, 8, 8, 8);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        radStartLast = new QRadioButton(grpOnStart);
        radStartLast->setObjectName(QString::fromUtf8("radStartLast"));

        vboxLayout3->addWidget(radStartLast);

        radStartSpecified = new QRadioButton(grpOnStart);
        radStartSpecified->setObjectName(QString::fromUtf8("radStartSpecified"));

        vboxLayout3->addWidget(radStartSpecified);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(1);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        txtStart = new QLineEdit(grpOnStart);
        txtStart->setObjectName(QString::fromUtf8("txtStart"));

        hboxLayout->addWidget(txtStart);

        btnBrowseKat = new QToolButton(grpOnStart);
        btnBrowseKat->setObjectName(QString::fromUtf8("btnBrowseKat"));

        hboxLayout->addWidget(btnBrowseKat);


        vboxLayout3->addLayout(hboxLayout);

        radStartBlank = new QRadioButton(grpOnStart);
        radStartBlank->setObjectName(QString::fromUtf8("radStartBlank"));
        radStartBlank->setChecked(true);

        vboxLayout3->addWidget(radStartBlank);


        vboxLayout2->addWidget(grpOnStart);

        spacerItem2 = new QSpacerItem(21, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem2);

        tabWidget->addTab(tabStart, QString());
        tabLoteri = new QWidget();
        tabLoteri->setObjectName(QString::fromUtf8("tabLoteri"));
        layoutWidget = new QWidget(tabLoteri);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 361, 22));
        hboxLayout1 = new QHBoxLayout(layoutWidget);
        hboxLayout1->setSpacing(1);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        LotoName = new QLabel(layoutWidget);
        LotoName->setObjectName(QString::fromUtf8("LotoName"));

        hboxLayout1->addWidget(LotoName);

        lotoName = new QLineEdit(layoutWidget);
        lotoName->setObjectName(QString::fromUtf8("lotoName"));

        hboxLayout1->addWidget(lotoName);

        layoutWidget1 = new QWidget(tabLoteri);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 40, 361, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MaxNr = new QLabel(layoutWidget1);
        MaxNr->setObjectName(QString::fromUtf8("MaxNr"));

        horizontalLayout->addWidget(MaxNr);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        extractNr = new QSpinBox(layoutWidget1);
        extractNr->setObjectName(QString::fromUtf8("extractNr"));

        horizontalLayout->addWidget(extractNr);

        layoutWidget2 = new QWidget(tabLoteri);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 80, 361, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        maxNr = new QSpinBox(layoutWidget2);
        maxNr->setObjectName(QString::fromUtf8("maxNr"));

        horizontalLayout_2->addWidget(maxNr);

        tabWidget->addTab(tabLoteri, QString());

        vboxLayout->addWidget(tabWidget);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        buttonHelp = new QPushButton(settingWidget);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        buttonHelp->setAutoDefault(true);

        hboxLayout2->addWidget(buttonHelp);

        spacerItem3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem3);

        buttonOk = new QPushButton(settingWidget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(true);
        buttonOk->setDefault(true);

        hboxLayout2->addWidget(buttonOk);

        buttonCancel = new QPushButton(settingWidget);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(true);

        hboxLayout2->addWidget(buttonCancel);


        vboxLayout->addLayout(hboxLayout2);

        QWidget::setTabOrder(tabWidget, radStartLast);
        QWidget::setTabOrder(radStartLast, radStartSpecified);
        QWidget::setTabOrder(radStartSpecified, txtStart);
        QWidget::setTabOrder(txtStart, radStartBlank);
        QWidget::setTabOrder(radStartBlank, lotoName);
        QWidget::setTabOrder(lotoName, buttonHelp);
        QWidget::setTabOrder(buttonHelp, buttonOk);
        QWidget::setTabOrder(buttonOk, buttonCancel);

        retranslateUi(settingWidget);
        QObject::connect(buttonCancel, SIGNAL(clicked()), settingWidget, SLOT(reject()));
        QObject::connect(radStartSpecified, SIGNAL(clicked()), txtStart, SLOT(setFocus()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(settingWidget);
    } // setupUi

    void retranslateUi(QDialog *settingWidget)
    {
        settingWidget->setWindowTitle(QApplication::translate("settingWidget", "Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settingWidget", "Language <i>(requires restart to take effect)</i>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGeneral), QApplication::translate("settingWidget", "General", 0, QApplication::UnicodeUTF8));
        grpOnStart->setTitle(QApplication::translate("settingWidget", "On startup...", 0, QApplication::UnicodeUTF8));
        radStartLast->setText(QApplication::translate("settingWidget", "Open last used tiket", 0, QApplication::UnicodeUTF8));
        radStartSpecified->setText(QApplication::translate("settingWidget", "Open this tiket:", 0, QApplication::UnicodeUTF8));
        btnBrowseKat->setText(QApplication::translate("settingWidget", "...", 0, QApplication::UnicodeUTF8));
        radStartBlank->setText(QApplication::translate("settingWidget", "Do not open a tiket", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabStart), QApplication::translate("settingWidget", "Start/Close", 0, QApplication::UnicodeUTF8));
        LotoName->setText(QApplication::translate("settingWidget", "Loteri Name", 0, QApplication::UnicodeUTF8));
        MaxNr->setText(QApplication::translate("settingWidget", "Extract Numbers", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settingWidget", "Max Number", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabLoteri), QApplication::translate("settingWidget", "Loteri", 0, QApplication::UnicodeUTF8));
        buttonHelp->setText(QApplication::translate("settingWidget", "&Help", 0, QApplication::UnicodeUTF8));
        buttonHelp->setShortcut(QApplication::translate("settingWidget", "F1", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("settingWidget", "&OK", 0, QApplication::UnicodeUTF8));
        buttonOk->setShortcut(QString());
        buttonCancel->setText(QApplication::translate("settingWidget", "&Cancel", 0, QApplication::UnicodeUTF8));
        buttonCancel->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class settingWidget: public Ui_settingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
