/***************************************************************************
 *   Copyright (C) 2005 by Massimiliano Torromeo                           *
 *   massimiliano.torromeo AT gmail DOT com                                *
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
	conf.startup = settings.value("startup",0).toInt();
        conf.lotoname = settings.value("lotoname","Romania").toString();
	conf.locale = settings.value("locale",QLocale::system().name()).toString();
	settings.endGroup();



        { langinfo l = {"en_EN","English"};
		languages << l; }
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

	//Localisations
	translator = new QTranslator();
        QString translatorFile = QApplication::applicationDirPath() + "/BiletMain_"+conf.locale;
	if (QFile::exists(translatorFile+".qm"))
		translator->load( translatorFile );
#ifndef Q_WS_WIN
	else
                translator->load( "/usr/share/BiletMain/BiletMain_"+conf.locale );
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



	} else {

		switch( conf.startup ) {
			case 0:

			break;
			case 1:

			break;
		}

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
        //sql->db.close();

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
        btnStop->setIcon( QIcon("images/Clear.png") );
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

        QicPicBox = new QGroupBox(grupBox);
        QicPicBox->setTitle(tr("QickPick"));
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


        label = new QLabel(grupBox);
        label->setText(tr("Set game date"));
        label->setGeometry(QRect(5, 220, 111, 16));
        dateEdit = new QDateEdit(grupBox);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate::currentDate());
        dateEdit->setGeometry(QRect(5, 240, 110, 22));

        spacerH = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        textBrows = new QTextBrowser(tab1);
        textBrows->setFixedWidth(200);
        //connect(viewVar,SIGNAL(clicked()),textBrows, SLOT(append(QString)));
        connect(viewVar, SIGNAL(clicked()), this, SLOT(writeVariante()));
        connect(clearTiket, SIGNAL(clicked()), textBrows, SLOT(clear()));
        layoutH = new QHBoxLayout;
        layoutH->addWidget(grupBox);
        layoutH->addItem(spacerH);
        layoutH->addWidget(bl);
        layoutH->addWidget(textBrows);
        tab1->setLayout(layoutH);

        tabWidget->addTab(tab1, tr("Tiket"));
//............End Tab1 ........................

//............Tab2..............................
        tab2 = new QWidget();
        grup2Box = new QGroupBox(tab2);
        grup2Box->setFixedWidth(191);
        label_2 = new QLabel(grup2Box);
        label_2->setText(tr("Extracted Numbers"));
        label_2->setGeometry(QRect(10, 10, 101, 20));

        layoutWidget2 = new QWidget(grup2Box);
        layoutWidget2->setGeometry(QRect(3, 25, 185, 20));
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
        horizontalLayout_2->addWidget(spinBox);

        spinBox_2 = new QSpinBox(layoutWidget2);
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setMaximum(49);
        horizontalLayout_2->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(layoutWidget2);
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_3->setMaximum(49);
        horizontalLayout_2->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(layoutWidget2);
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_4->setMaximum(49);
        horizontalLayout_2->addWidget(spinBox_4);

        spinBox_5 = new QSpinBox(layoutWidget2);
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_5->setMaximum(49);
        horizontalLayout_2->addWidget(spinBox_5);

        spinBox_6 = new QSpinBox(layoutWidget2);
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_6->setMaximum(49);
        horizontalLayout_2->addWidget(spinBox_6);

        line = new QFrame(grup2Box);
        line->setGeometry(QRect(10, 70, 171, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(grup2Box);
        line_2->setGeometry(QRect(10, 200, 171, 16));
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

        spinBox_7 = new QSpinBox(layoutWidget3);
        spinBox_7->setEnabled(true);
        spinBox_7->setMinimumSize(QSize(101, 20));
        spinBox_7->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_7->setMaximum(999999999);

        gridLayout->addWidget(spinBox_7, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget3);
        label_6->setText(tr("Cat   II"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        spinBox_8 = new QSpinBox(layoutWidget3);
        spinBox_8->setEnabled(true);
        spinBox_8->setMinimumSize(QSize(101, 20));
        spinBox_8->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_8->setMaximum(999999999);

        gridLayout->addWidget(spinBox_8, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget3);
        label_7->setText(tr("Cat  III"));


        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        spinBox_9 = new QSpinBox(layoutWidget3);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setEnabled(true);
        spinBox_9->setMinimumSize(QSize(101, 20));
        spinBox_9->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_9->setKeyboardTracking(true);
        spinBox_9->setMaximum(999999999);

        gridLayout->addWidget(spinBox_9, 2, 1, 1, 1);

        label_8 = new QLabel(layoutWidget3);
        label_8->setText(tr("Cat   IV"));


        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        spinBox_10 = new QSpinBox(layoutWidget3);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setEnabled(true);
        spinBox_10->setMinimumSize(QSize(101, 20));
        spinBox_10->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10->setMaximum(999999999);
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
        chackButton->setGeometry(QRect(10, 220, 75, 23));
        connect(chackButton,SIGNAL(clicked()),this, SLOT(ChackWin()));

        text2Brows = new QTextBrowser(tab2);
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

        setWindowTitle(tr("LotoTickets"));
        setWindowIcon(QIcon("images/about.png"));
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

        exitAct = new QAction(QIcon("images/Exit.png"), tr("&Quit"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	exitAct->setStatusTip(tr("Close application"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(fileExitClicked()));

        settingsAct = new QAction(QIcon("images/configure.png"), tr("&Settings"), this);
	settingsAct->setStatusTip(tr("Edit settings"));
        connect(settingsAct, SIGNAL(triggered()), this, SLOT(editSettingsClicked()));

        deleteAct = new QAction(QIcon("images/delete.png"), tr("&Delete"), this);
	deleteAct->setShortcut(tr("Del"));
	deleteAct->setStatusTip(tr("Delete"));
        connect(deleteAct, SIGNAL(triggered()), this, SLOT(editDeleteClicked()));

        findAct = new QAction(QIcon("images/!.png"), tr("&Find"), this);
	findAct->setShortcut(tr("Ctrl+F"));
	findAct->setStatusTip(tr("Search in the collection"));
        //connect(findAct, SIGNAL(triggered()), this, SLOT(editFindClicked()));

        aboutAct = new QAction(QIcon("images/BiletMain.png"), tr("&About BiletMain"), this);
	aboutAct->setStatusTip(tr("Show program info"));
        connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutClicked()));

        //eraseLocationAct = new QAction(QIcon("/images/locationbar_erase.png"), tr("&Erase Location"), this);
        //eraseLocationAct->setStatusTip(tr("Erase location"));
        //connect(eraseLocationAct, SIGNAL(triggered()), this, SLOT(cmdEraseLocationClick()));

        setPathAct = new QAction(QIcon("/images/key_enter.png"), tr("&Go To"), this);
	setPathAct->setStatusTip(tr("Go to specified location"));
        //connect(setPathAct, SIGNAL(triggered()), this, SLOT(cmdPathClick()));
}

/**
 * Creates the menuBar for the application.
 */
void BiletMain::createMenu() {
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction( newAct );
	fileMenu->addAction( openAct );
        fileMenu->addAction( saveAct );
	fileMenu->addSeparator();
	fileMenu->addAction( exitAct );

	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction( findAct );
	editMenu->addAction( deleteAct );
	editMenu->addSeparator();
	editMenu->addSeparator();
	editMenu->addAction( settingsAct );

	viewMenu = menuBar()->addMenu(tr("&View"));
	viewMenu->addAction( fileToolbar->toggleViewAction() );
	viewMenu->addAction( editToolbar->toggleViewAction() );
        //viewMenu->addAction( locationToolbar->toggleViewAction() );
	viewMenu->addSeparator();
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
	fileToolbar->addAction( newAct );
	fileToolbar->addAction( openAct );
        fileToolbar->addAction( saveAct );
        fileToolbar->addAction( deleteAct );

        editToolbar = addToolBar( tr("&WinChacke") );
	editToolbar->setObjectName("editToolbar");
        editToolbar->setIconSize( QSize(16,16) );
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
		settings.setValue("startup",conf.startup);
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
    textBrows->clear();

    textBrows->append(tr("<b>Variantele obtinute sunt</b>"));
    rezultate = new QString;
    QTextStream test(rezultate);
    //qSort(bl->nrA.begin(), bl->nrA.end());
    //bl->nrA
    //test.AlignRight;
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
    delete rezultate;
    //rezultate->append(bilet->tmp1);
    //textBrows->append(*rezultate);
    showProgress( false, 0 );
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

    if(bl->varbilet.isEmpty())
        bl->varbilet = bl->GenVarBilet();

    //text2Brows->setSource(tr("test.html"));
    text2Brows->clear();
    bool print = false;
    bool scris = false;
    int categorie = 0;
    int cat1, cat2, cat3, cat4;
    rezultate = new QString;
    QTextStream test(rezultate);
    text2Brows->append(tr("<b><font color=blue>Extract number on activ ticket ar in read</font></b>"));
    test<<"\n";
    for(int i=0; i<bl->varbilet.count(); i++){
        for(int j=0; j<6; j++){
            for(int k=0; k<6; k++){
                if(bl->varbilet.at(i)[j] == nrextrase[k]){
                    print = true;
                    scris = true;
                    categorie++;
                    test<<"<b><font color=red>"<<nrextrase[k]<<"   "<<"</font></b>";
                }
            }
            if(!scris) test<<bl->varbilet.at(i)[j]<<"   ";
            scris = false;
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
    delete rezultate;
}
