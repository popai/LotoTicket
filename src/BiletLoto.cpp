/***************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                      *
 *   popai@b.astral.ro                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QtGui>
//#include <QtSql>

#include "BiletLoto.h"
#include "settings.h"
#include "ui_aboutwidget.h"

/**
 * Creation of the form:
 * - load settings
 * - start translator
 * - setupUI for interface
 * - create actions, menus and toolbars
 * - create sql connection (not opened yet)
 * - connect() all signals
 * - switch what to do on startup and eventually open a collection
 * @param parent
 * @return
 */
BiletMain::BiletMain(QWidget *parent) : QMainWindow( parent ) {
	QSettings settings;

	settings.beginGroup("application");
        conf.price_V = settings.value("priceV",0).toInt();
        conf.lotoname = settings.value("lotoname","Romania").toString();
	conf.locale = settings.value("locale",QLocale::system().name()).toString();
	settings.endGroup();



        { langinfo l = {"en_EN","English"};
		languages << l; }
        { langinfo l = {"ro_RO",QString::fromUtf8("Romanian")};
                languages << l; }
        /*
	{ langinfo l = {"fr_FR",QString::fromUtf8("Français")};
		languages << l; }
	{ langinfo l = {"he_IL",QString::fromUtf8("עברית")};
		languages << l; }
	{ langinfo l = {"it_IT","Italiano"};
		languages << l; }
	{ langinfo l = {"pl_PL","Polski"};
		languages << l; }
	{ langinfo l = {"ru_RU",QString::fromUtf8("Pусский")};
		languages << l; }
	{ langinfo l = {"tr_TR",QString::fromUtf8("Türkçe")};
		languages << l; }
        */
	//Localisations
	translator = new QTranslator();
        QString translatorFile = QApplication::applicationDirPath() + "/translate/LottoTicket_"+conf.locale;
	if (QFile::exists(translatorFile+".qm"))
		translator->load( translatorFile );
#ifndef Q_WS_WIN
	else
                translator->load( "/usr/share/LottoTicket/LottoTicket_"+conf.locale );
#endif
	QApplication::installTranslator(translator);

        setupWidgets();

        resize( settings.value("window/size", QSize(650, 450)).toSize() );
	restoreState( settings.value("window/state").toByteArray() );

	settings.deleteLater();

        //sql = new CdSql( &conf );

        this->setStyleSheet("QTableWidget { selection-background-color: rgb(255, 117, 24) }");
        QMetaObject::connectSlotsByName(this);


	if ( QApplication::argc()>0 && QFile::exists(QApplication::argv()[QApplication::argc()]) ) {



        }
}

/**
 * On form destruction, destroy formFind if not NULL
 * @return
 */
BiletMain::~BiletMain() {
        //delete sql;
        //if (formFind!=NULL)
        //	delete formFind;
}

/**
 * Executes last operations before closing application:
 * - if a search is in progress, stop it
 * - close the db
 * - save settings
 * @param
 */
void BiletMain::closeEvent(QCloseEvent *) {
        //if (formFind!=NULL)
        //	formFind->stopSearch();
        //db.db.close();

	QSettings settings;
        settings.setValue("window/size",size());
        //settings.setValue("tableview/name", dirList->horizontalHeader()->sectionSize(0));
	settings.setValue("window/state", saveState());
	settings.deleteLater();
}

void BiletMain::setupWidgets() {
	//PROGRESS STATUS
        this->setFixedSize(QSize(650, 430));
	progress = new QProgressBar( statusBar() );
	progress->setMaximumSize( QSize(200,24) );
	progress->setVisible( false );
	statusBar()->addPermanentWidget( progress );

	btnStop = new QToolButton( statusBar() );
	btnStop->setVisible( false );
        btnStop->setIcon( QIcon("images/Save1.png") );
	statusBar()->addPermanentWidget( btnStop );
        //connect( btnStop, SIGNAL( clicked() ), this, SLOT( stopClicked() ) );

        tabWidget = new QTabWidget(this);
        tabWidget->setMinimumSize(QSize(650, 360));
        setCentralWidget(tabWidget);

//............Tab1..............................
        tab1 = new QWidget();
        bl = new Bilet(tab1);
        grupBox = new QGroupBox(tab1);
        grupBox->setFixedWidth(120);
        clearTiket = new QPushButton(grupBox);
        clearTiket->setText(tr("ClearTiket"));
        clearTiket->setGeometry(QRect(10, 15, 75, 23));
        connect(clearTiket,SIGNAL(clicked()),bl, SLOT(clearSelection()));

        viewVar = new QPushButton(grupBox);
        viewVar->setText(tr("ViewVar"));
        viewVar->setGeometry(QRect(10, 55, 75, 23));
        connect(viewVar, SIGNAL(clicked()), this, SLOT(writeVariante()));

        QicPicBox = new QGroupBox(grupBox);
        QicPicBox->setTitle(tr("QuickPick"));
        QicPicBox->setGeometry(QRect(10, 85, 91, 131));
        widget = new QWidget(QicPicBox);
        widget->setGeometry(QRect(11, 21, 77, 94));
        layoutV = new QVBoxLayout(widget);
        layoutV->setSpacing(6);
        layoutV->setContentsMargins(10, 10, 10, 10);
        //layoutV->setObjectName(QString::fromUtf8("layoutV"));
        layoutV->setContentsMargins(0, 0, 0, 0);
        checkBoxA = new QCheckBox(widget);
        checkBoxA->setText(tr("fild A"));
        layoutV->addWidget(checkBoxA);

        checkBoxB = new QCheckBox(widget);
        checkBoxB->setText(tr("fild B"));
        layoutV->addWidget(checkBoxB);

        checkBoxC = new QCheckBox(widget);
        checkBoxC->setText(tr("fild C"));
        layoutV->addWidget(checkBoxC);

        pickButon = new QPushButton(widget);
        pickButon->setText(tr("Pick"));
        pickButon->setMaximumSize(50, 20);
        layoutV->addWidget(pickButon);
        connect(pickButon,SIGNAL(clicked()),this, SLOT(QuickPick()));


        label = new QLabel(grupBox);
        label->setText(tr("Set game date"));
        label->setGeometry(QRect(5, 220, 111, 16));
        dateEdit = new QDateEdit(grupBox);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate::currentDate());
        dateEdit->setGeometry(QRect(5, 240, 110, 22));

        /*
        label_t1 = new QLabel(grupBox);
        label_t1->setText(tr("price for one variant"));
        label_t1->setGeometry(QRect(5, 270, 111, 16));

        spinBox_t1= new QSpinBox(grupBox);
        spinBox_t1->setEnabled(true);
        spinBox_t1->setGeometry(QRect(5, 290, 110, 22));
        //spinBox_t1->setMinimumSize(QSize(101, 20));
        spinBox_t1->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_t1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_t1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_t1->setMaximum(999999999);
        */

        spacerH = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        textBrows = new QTextBrowser(tab1);
        textBrows->setFixedWidth(200);
        //connect(clearTiket, SIGNAL(clicked()), textBrows, SLOT(clear()));
        connect(bl, SIGNAL(SelectionChanged()), textBrows, SLOT(clear()));
        layoutH = new QHBoxLayout;
        layoutH->addWidget(grupBox);
        layoutH->addItem(spacerH);
        layoutH->addWidget(bl);
        layoutH->addWidget(textBrows);
        tab1->setLayout(layoutH);

        tabWidget->addTab(tab1, tr("Ticket"));
//............End Tab1 ........................

//............Tab2..............................
        tab2 = new QWidget();
        grup2Box = new QGroupBox(tab2);
        grup2Box->setFixedWidth(191);
        label_2 = new QLabel(grup2Box);
        label_2->setText(tr("Extracted Numbers"));
        label_2->setGeometry(QRect(10, 10, 101, 20));

        layoutWidget2 = new QWidget(grup2Box);
        layoutWidget2->setGeometry(QRect(3, 40, 185, 20));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setEnabled(true);
        spinBox->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMaximum(49);
        connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(ChackWin()));
        horizontalLayout_2->addWidget(spinBox);

        spinBox_2 = new QSpinBox(layoutWidget2);
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setMaximum(49);
        connect(spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(ChackWin()));
        horizontalLayout_2->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(layoutWidget2);
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_3->setMaximum(49);
        connect(spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(ChackWin()));
        horizontalLayout_2->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(layoutWidget2);
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_4->setMaximum(49);
        connect(spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(ChackWin()));
        horizontalLayout_2->addWidget(spinBox_4);

        spinBox_5 = new QSpinBox(layoutWidget2);
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_5->setMaximum(49);
        connect(spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(ChackWin()));
        horizontalLayout_2->addWidget(spinBox_5);

        spinBox_6 = new QSpinBox(layoutWidget2);
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_6->setMaximum(49);
        connect(spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(ChackWin()));
        horizontalLayout_2->addWidget(spinBox_6);

        line = new QFrame(grup2Box);
        line->setGeometry(QRect(10, 70, 171, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(grup2Box);
        line_2->setGeometry(QRect(10, 230, 171, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        layoutWidget3 = new QWidget(grup2Box);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 101, 171, 100));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(grup2Box);
        label_4->setText(tr("Win Fonds"));
        label_4->setGeometry(QRect(10, 80, 121, 16));
        label_5 = new QLabel(layoutWidget3);
        label_5->setText(tr("Cat    I"));


        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        spinBox_7 = new QDoubleSpinBox(layoutWidget3);
        spinBox_7->setEnabled(true);
        spinBox_7->setMinimumSize(QSize(101, 20));
        spinBox_7->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_7->setMaximum(999999999.999);

        gridLayout->addWidget(spinBox_7, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget3);
        label_6->setText(tr("Cat   II"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        spinBox_8 = new QDoubleSpinBox(layoutWidget3);
        spinBox_8->setEnabled(true);
        spinBox_8->setMinimumSize(QSize(101, 20));
        spinBox_8->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_8->setMaximum(999999999.999);

        gridLayout->addWidget(spinBox_8, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget3);
        label_7->setText(tr("Cat  III"));


        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        spinBox_9 = new QDoubleSpinBox(layoutWidget3);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setEnabled(true);
        spinBox_9->setMinimumSize(QSize(101, 20));
        spinBox_9->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_9->setKeyboardTracking(true);
        spinBox_9->setMaximum(999999999.999);

        gridLayout->addWidget(spinBox_9, 2, 1, 1, 1);

        label_8 = new QLabel(layoutWidget3);
        label_8->setText(tr("Cat   IV"));


        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        spinBox_10 = new QDoubleSpinBox(layoutWidget3);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setEnabled(true);
        spinBox_10->setMinimumSize(QSize(101, 20));
        spinBox_10->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10->setMaximum(999999999.999);
        gridLayout->addWidget(spinBox_10, 3, 1, 1, 1);

        dateEdit_2 = new QDateEdit(grup2Box);
        dateEdit_2->setCalendarPopup(true);
        dateEdit_2->setDate(QDate::currentDate());
        dateEdit_2->setGeometry(QRect(10, 270, 110, 22));
        label_3 = new QLabel(grup2Box);
        label_3->setText(tr("Extraction Date"));
        label_3->setGeometry(QRect(10, 250, 81, 21));
        chackButton = new QPushButton(grup2Box);
        chackButton->setText(tr("ChackWin"));
        chackButton->setGeometry(QRect(35, 205, 75, 23));
        connect(chackButton,SIGNAL(clicked()),this, SLOT(ChackWin()));

        text2Brows = new QTextBrowser(tab2);
        connect(bl, SIGNAL(SelectionChanged()), text2Brows, SLOT(clear()));
        layout2H = new QHBoxLayout;
        layout2H->addWidget(grup2Box);
        layout2H->addWidget(text2Brows);
        tab2->setLayout(layout2H);

        tabWidget->addTab(tab2, tr("WinCheck"));
//............End Tab2 ........................

        //formFind = NULL;
	createActions();
	createToolbar();
	createMenu();

        setWindowTitle(tr("LottoTicket"));
        setWindowIcon(QIcon("images/app.ico"));
}


/**
 * Creates all actions used by both menubars and toolbars.
 */
void BiletMain::createActions() {
        newAct = new QAction(QIcon("images/new.png"), tr("&New Loteri"), this);
	newAct->setShortcut(tr("Ctrl+N"));
        newAct->setStatusTip(tr("New Loteri"));
        connect(newAct, SIGNAL(triggered()), this, SLOT(fileNewClicked()));

        openAct = new QAction(QIcon("images/Open.png"), tr("&Open"), this);
	openAct->setShortcut(tr("Ctrl+O"));
        openAct->setStatusTip(tr("Open ticket"));
        connect(openAct, SIGNAL(triggered()), this, SLOT(fileOpenClicked()));

        saveAct = new QAction(QIcon("images/Save.png"), tr("&Save"), this);
        saveAct->setShortcut(tr("Ctrl+S"));
        saveAct->setStatusTip(tr("Save ticket"));
        connect(saveAct, SIGNAL(triggered()), this, SLOT(fileSaveClicked()));

        exitAct = new QAction(QIcon("images/Exit1.png"), tr("&Quit"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	exitAct->setStatusTip(tr("Close application"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(fileExitClicked()));

        settingsAct = new QAction(QIcon("images/settings.png"), tr("&Settings"), this);
	settingsAct->setStatusTip(tr("Edit settings"));
        connect(settingsAct, SIGNAL(triggered()), this, SLOT(editSettingsClicked()));

        deleteAct = new QAction(QIcon("images/delete.png"), tr("&Delete"), this);
        deleteAct->setShortcut(tr("Ctrl+D"));
	deleteAct->setStatusTip(tr("Delete"));
        connect(deleteAct, SIGNAL(triggered()), this, SLOT(editDeleteClicked()));

        clearAct = new QAction(QIcon("images/Clear.png"), tr("&Clear"), this);
        clearAct->setShortcut(tr("Ctrl+C"));
        clearAct->setStatusTip(tr("Clear selected numbers on ticket"));
        connect(clearAct, SIGNAL(triggered()), bl, SLOT(clearSelection()));
        connect(clearAct, SIGNAL(triggered()), textBrows, SLOT(clear()));
        connect(clearAct, SIGNAL(triggered()), text2Brows, SLOT(clear()));

        viewAct = new QAction(QIcon("images/view.png"), tr("&View Variants"), this);
        viewAct->setShortcut(tr("Ctrl+V"));
        viewAct->setStatusTip(tr("write the variants for selectet numbers"));
        connect(viewAct, SIGNAL(triggered()), this, SLOT(writeVariante()));


        findAct = new QAction(QIcon("images/!.png"), tr("&ChackWin"), this);
        findAct->setShortcut(tr("Ctrl+W"));
        findAct->setStatusTip(tr("Check the Wining"));
        connect(findAct, SIGNAL(triggered()), this, SLOT(ChackWin()));

        aboutAct = new QAction(QIcon("images/info.png"), tr("&About LottoTicket"), this);
	aboutAct->setStatusTip(tr("Show program info"));
        connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutClicked()));
}

/**
 * Creates the menuBar for the application.
 */
void BiletMain::createMenu() {
        fileMenu = menuBar()->addMenu(tr("&Ticket"));
        //fileMenu->addAction( newAct );
	fileMenu->addAction( openAct );
        fileMenu->addAction( saveAct );
        fileMenu->addSeparator();
        fileMenu->addAction( deleteAct );
	fileMenu->addSeparator();
	fileMenu->addAction( exitAct );

        viewMenu = menuBar()->addMenu(tr("&Variants"));
        viewMenu->addAction( clearAct );
        viewMenu->addAction( viewAct );
        viewMenu->addSeparator();
        viewMenu->addAction( findAct );
        //viewMenu->addSeparator();


        viewMenu = menuBar()->addMenu(tr("&Option"));
	viewMenu->addAction( fileToolbar->toggleViewAction() );
	viewMenu->addAction( editToolbar->toggleViewAction() );

	viewMenu->addSeparator();
        viewMenu->addAction( settingsAct );
        //viewMenu->addAction( locationToolbar->toggleViewAction() );
        //viewMenu->addAction( cdDock->toggleViewAction() );
        //viewMenu->addAction( thumbDock->toggleViewAction() );

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction( aboutAct );
}

/**
 * Creates the toolbars and inserts the default actions.
 */
void BiletMain::createToolbar() {
        fileToolbar = addToolBar( tr("&Ticket") );
	fileToolbar->setObjectName("fileToolbar");
        fileToolbar->setIconSize( QSize(16,16) );
        fileToolbar->addAction( exitAct );
        //fileToolbar->addAction( newAct );
	fileToolbar->addAction( openAct );
        fileToolbar->addAction( saveAct );
        fileToolbar->addAction( deleteAct );

        editToolbar = addToolBar( tr("&WinChacke") );
	editToolbar->setObjectName("editToolbar");
        editToolbar->setIconSize( QSize(16,16) );
        editToolbar->addAction( clearAct );
        editToolbar->addAction( viewAct );
	editToolbar->addAction( findAct );
}


BiletRecord BiletMain::biletToRecord(QString numeBilet)
{
    BiletRecord record;
    record.biletID = numeBilet;
    record.codA = bl->codA;
    record.codB = bl->codB;
    record.codC = bl->codC;

    for(int i=0; i < bl->nrA.count(); i++){
        if(bl->nrA.at(i)->text().toInt())
            record.nrA << bl->nrA.at(i)->text().toInt();
    }
    //qSort(record.nrA.begin(), record.nrA.end());
    for(int i=0; i < bl->nrB.count(); i++){
        if(bl->nrB.at(i)->text().toInt())
            record.nrB << bl->nrB.at(i)->text().toInt();
    }
    //qSort(record.nrB.begin(), record.nrB.end());
    for(int i=0; i < bl->nrC.count(); i++){
        if(bl->nrC.at(i)->text().toInt())
            record.nrC << bl->nrC.at(i)->text().toInt();
    }
    //qSort(record.nrC.begin(), record.nrC.end());
    return record;
}



/**
 * Creates a dialog and sets its content with aboutWidget::setupUi, the it modally shows it
 */
void BiletMain::aboutClicked() {
	QDialog *diag = new QDialog(this);
	Ui::aboutWidget().setupUi(diag);
	diag->exec();
	delete diag;
}

void BiletMain::editSettingsClicked() {
	Settings *set = new Settings(this);
	if (set->exec()) {
		QSettings settings;

		settings.beginGroup("application");
                settings.setValue("priceV",conf.price_V);
                settings.setValue("lotoname",conf.lotoname);
                settings.setValue("nrextrase",conf.nrextrase);
                settings.setValue("nrmax",conf.nrmax);
		settings.setValue("locale",conf.locale);
		settings.endGroup();

		settings.deleteLater();
	}
	delete set;
}


void BiletMain::editFindClicked() {

}

void BiletMain::showProgress( bool show, int max ) {
	progress->setVisible( show );
	btnStop->setVisible( show );
	progress->setMaximum( max );
}

void BiletMain::setProgress( int pos ) {
	progress->setValue( pos );
}

void BiletMain::editDeleteClicked()
{
    del = new Delete();

    //OpenBilet::openList->clear();

    QVector<BiletRecord> lista = db.getAll();
    //QMessageBox::about(this,"db-ver","basdhfkjdfhkjf");// lista.at(0).biletID);
    QVectorIterator<BiletRecord> i(lista);
    QListWidgetItem* newBilet;
    while (i.hasNext()) {
            BiletRecord nr = i.next();
            newBilet = new QListWidgetItem;
            newBilet->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEnabled );
            newBilet->setIcon( QIcon("images/about.png") );
            //newBilet->id = nr.biletID;
            newBilet->setText( nr.biletID+"             "+nr.data);
            del->SetList(newBilet);
    }
    del->exec();

    if(!del->idBilet.isEmpty()){
        aFilename = del->idBilet.remove(QRegExp(" (.*)"));
        QMessageBox msgBox;
        msgBox.setText("Do you want delete ticket?");
        msgBox.setInformativeText("Pres delete to procide, Abord to cancel");
        QPushButton *delButton = msgBox.addButton(tr("Delete"), QMessageBox::ActionRole);
        QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);

        msgBox.exec();

         if (msgBox.clickedButton() == delButton) {
             db.DelBilet(aFilename);
         } else if (msgBox.clickedButton() == abortButton) {
             // abort
         }
    }
    //textBrows->append(aFilename);
    //QString cdf = QFileDialog::getOpenFileName( this, tr("Choose a BiletMain collection"), "", "BiletMain collections (*.cdf)" );
    //db.delBilet(aFilename); de implementat delBilet in db.
    delete del;

}

void BiletMain::fileNewClicked() {

}

void BiletMain::fileExitClicked() {
	close();
}

void BiletMain::fileSaveClicked()
{
    //BiletRecord br;
    svb = new SaveBilet();

    QVector<BiletRecord> nodes = db.getAll();
    QVectorIterator<BiletRecord> i(nodes);
    QListWidgetItem* newBilet;
    while (i.hasNext()) {
            BiletRecord nr = i.next();
            newBilet = new QListWidgetItem;
            newBilet->setFlags(Qt::ItemIsEnabled );
            newBilet->setIcon( QIcon("images/about.png") );
            newBilet->setText( nr.biletID+"             "+nr.data);
            svb->SetList(newBilet);
    }
    svb->exec();
    QVectorIterator<BiletRecord> j(nodes);
    while (j.hasNext()) {
        BiletRecord nr = j.next();
        if(nr.biletID == svb->nameB){
            QMessageBox::critical( 0, QCoreApplication::applicationName(), QCoreApplication::tr("Ticket exist. Try diferent name") );
            svb->exec();
            //svb->nameB = "";
        }
        //de verificare
        //textBrows->append(nr.biletID);
    }

    //textBrows->append(svb->nameB);
    if(!svb->nameB.isEmpty()){
        if(bl->biletOK)
            db.AddBilet(biletToRecord(svb->nameB));
        else
            QMessageBox::critical( 0, QCoreApplication::applicationName(), QCoreApplication::tr("Ticket not save, try viewVar for more info") );
    }

    delete svb;
}

void BiletMain::fileOpenClicked()
{
    opb = new OpenBilet();

    //OpenBilet::openList->clear();

    QVector<BiletRecord> lista = db.getAll();
    //QMessageBox::about(this,"db-ver","basdhfkjdfhkjf");// lista.at(0).biletID);
    QVectorIterator<BiletRecord> i(lista);
    QListWidgetItem* newBilet;
    while (i.hasNext()) {
            BiletRecord nr = i.next();
            newBilet = new QListWidgetItem;
            newBilet->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEnabled );
            newBilet->setIcon( QIcon("images/about.png") );
            newBilet->setText( nr.biletID+"             "+nr.data);
            //newBilet->setStatusTip(nr.data);
            opb->SetList(newBilet);
    }
    opb->exec();
    BiletRecord opBilet;
    if(!opb->idBilet.isEmpty()){
        aFilename = opb->idBilet.remove(QRegExp(" (.*)"));
        opBilet = db.getBilet(aFilename);
    }
    //Open the bilet
    bl->RecToBl(opBilet);
    delete opb;
}



void BiletMain::writeVariante()
{
    tabWidget->setCurrentWidget(tab1);

    textBrows->clear();
    textBrows->append(tr("<b>Obtained variants are</b>"));
    rezultate = new QString;
    QTextStream test(rezultate);

    test<<"\n";
    bl->varbilet = bl->GenVarBilet();
    showProgress( true, bl->varbilet.count()-1 );
    for(int i=0; i<bl->varbilet.count(); i++){
        test<<i+1<<".   ";
        setProgress( i );
        for(int j=0; j<6; j++){
            test<<bl->varbilet.at(i)[j]<<"  ";
        }
        //test<<"\n";
        textBrows->append(*rezultate);
        rezultate->clear();
    }
    //rezultate->append(bl->tmp1);
    //test<<"codA:"<<bl->codA<<" "<<"codB:"<<bl->codB<<" "<<"codC:"<<bl->codC<<endl;
    //test<<"cod selectat:"<<bl->tmp1<<endl;
    //test<<"Nr de variante:"<<bl->varbilet.count();
    test<<tr("<b><font color=#0000ff>Cost</font><font color=#ff0000> : ")<<conf.price_V*bl->varbilet.count()<<tr(" Euro</font><b>");
    textBrows->append(*rezultate);
    rezultate->clear();
    showProgress( false, 0 );
    delete rezultate;
}

void BiletMain::ChackWin()
{
    QVector<int> nrextrase;
    nrextrase<<spinBox->value();
    nrextrase<<spinBox_2->value();
    nrextrase<<spinBox_3->value();
    nrextrase<<spinBox_4->value();
    nrextrase<<spinBox_5->value();
    nrextrase<<spinBox_6->value();
    qSort(nrextrase.begin(), nrextrase.end());
    tabWidget->setCurrentWidget(tab2);
    if(bl->varbilet.isEmpty())
        bl->varbilet = bl->GenVarBilet();

    //text2Brows->setSource(tr("test.html"));
    text2Brows->clear();
    bool print = false;
    int categorie = 0;
    int cat1 = 0, cat2 = 0, cat3 = 0, cat4 = 0;
    rezultate = new QString;
    QTextStream test(rezultate);

    text2Brows->append(tr("<b><font color=#0000ff>Extract number on activ ticket ar</font></b>"));
    for(int i=0; i<bl->varbilet.count(); i++){
        for(int j=0; j<6; j++){
            if(nrextrase.contains(bl->varbilet.at(i)[j])){
                    print = true;
                    categorie++;
                    test<<"<b><font color=red>"<<bl->varbilet.at(i)[j]<<"   "<<"</font></b>";
                }
            else test<<bl->varbilet.at(i)[j]<<"   ";
          }
        if(print){
            text2Brows->append(*rezultate);
            print = false;
        }
        rezultate->clear();
        switch(categorie){
            case 6: cat1++;
                break;
            case 5: cat2++;
                break;
            case 4: cat3++;
                break;
            case 3: cat4++;
                break;
        default:;
        }
        categorie = 0;
    }

    test<<"<br>";
    test<<tr("<font color=green> Win on Categori   I: </font><b><font color=#ff4411>")<<cat1<<tr("</font></b><font color=green> variants </font>");
    text2Brows->append(*rezultate);
    rezultate->clear();
    test<<tr("<font color=green> Win on Categori  II: </font><b><font color=#ff4411>")<<cat2<<tr("</font></b><font color=green> variants </font>");
    text2Brows->append(*rezultate);
    rezultate->clear();
    test<<tr("<font color=green> Win on Categori III: </font><b><font color=#ff4411>")<<cat3<<tr("</font></b><font color=green> variants </font>");
    text2Brows->append(*rezultate);
    rezultate->clear();
    test<<tr("<font color=green> Win on Categori  IV: </font><b><font color=#ff4411>")<<cat4<<tr("</font></b><font color=green> variants </font>");
    text2Brows->append(*rezultate);
    rezultate->clear();
    //test<<"&nbsp";
    test<<"<br>";
    test<<"<table style=\"text-align: left; width: 434px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"2\">";
    test<<"<tbody> <tr>";
    test<<"<td style=\"width: 76px; text-align: center; font-weight: bold; \
             color: yellow; background-color: rgb(0, 153, 0);\">"<<tr("CATEG.")<<"</td>";
    test<<"<td style=\"text-align: center; width: 152px; font-weight: \
             bold; color: yellow; background-color: rgb(0, 153, 0);\">"<<tr("NUMBERS OF WIN")<<"</td>";
    test<<"<td style=\"text-align: center; width: 178px; font-weight: bold; \
             color: yellow; background-color: rgb(0, 153, 0);\">"<<tr("WINING AMONT")<<"</td>";
    test<<"</tr> <tr>";
    test<<"<td style=\"width: 74px; text-align: center;\">1 (6/6)</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat1<<"</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat1*spinBox_7->value()<<"</td>";
    test<<"</tr> <tr>";
    test<<"<td style=\"width: 74px; text-align: center;\">2 (5/6)</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat2<<"</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat2*spinBox_8->value()<<"</td>";
    test<<"</tr> <tr>";
    test<<"<td style=\"width: 74px; text-align: center;\">3 (4/6)</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat3<<"</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat3*spinBox_9->value()<<"</td>";
    test<<"</tr> <tr>";
    test<<"<td style=\"width: 74px; text-align: center;\">4 (3/6)</td>";
    test<<"<td style=\"text-align: center; width: 152px;\">"<<cat4<<"</td>";
    test<<"<td style=\"text-align=center; width: 152px;\">"<<cat4*spinBox_10->value()<<"</td>";
    test<<"</tr> <tr>";
    test<<"<td colspan=\"3\" rowspan=\"1\"";
    test<<"style=\"width: 74px; text-align: center; background-color: rgb(255, 255, 102);\">";
    test<<"<span style=\"font-weight: bold; color: red;\">"<<tr("TOTAL WINING: ")<<"</span>";
    double total = cat1*spinBox_7->value() + cat2*spinBox_8->value() + cat3*spinBox_9->value() + cat4*spinBox_10->value();
    test<<"<span style=\"font-weight: bold;\">"<<total<<tr(" EURO")<<"</span></td></tr>";

    test<<"</tbody></table><br>";

    text2Brows->append(*rezultate);
    //text2Brows->setSource(tr("TABEL.html"));
    delete rezultate;
}

void BiletMain::QuickPick()
{
    if(checkBoxA->isChecked()){
        bl->RandNr(1);
    }
    if(checkBoxB->isChecked()){
        bl->RandNr(2);
    }
    if(checkBoxC->isChecked()){
        bl->RandNr(3);
    }
}
