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
	conf.mountpoint = settings.value("mountpoint","").toString();
	conf.startup = settings.value("startup",0).toInt();
	conf.startkat = settings.value("startkat","").toString();
	conf.lastkat = settings.value("lastkat","").toString();
	conf.locale = settings.value("locale",QLocale::system().name()).toString();
	settings.endGroup();

	settings.beginGroup("thumbnails");
	conf.thperdir = settings.value("perdir",3).toInt();
	conf.thenabled = settings.value("enabled",true).toBool();
	conf.thsize = settings.value("size",120).toInt();
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
        /*......
         *widget of tab2
        */
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
        newAct = new QAction(QIcon("images/new.png"), tr("&New"), this);
	newAct->setShortcut(tr("Ctrl+N"));
        newAct->setStatusTip(tr("New ticket"));
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
        //connect(deleteAct, SIGNAL(triggered()), this, SLOT(editDeleteClicked()));

        findAct = new QAction(QIcon("images/!.png"), tr("&Find"), this);
	findAct->setShortcut(tr("Ctrl+F"));
	findAct->setStatusTip(tr("Search in the collection"));
        //connect(findAct, SIGNAL(triggered()), this, SLOT(editFindClicked()));

        addCDAct = new QAction(QIcon("images/cdrom_unmount.png"), tr("&Add CD"), this);
	addCDAct->setShortcut(tr("Ctrl+Ins"));
	addCDAct->setStatusTip(tr("Add a CD"));
        //connect(addCDAct, SIGNAL(triggered()), this, SLOT(katalogAddClicked()));

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
	editMenu->addAction( addCDAct );
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
	fileToolbar = addToolBar( tr("&File") );
	fileToolbar->setObjectName("fileToolbar");
        fileToolbar->setIconSize( QSize(16,16) );
        fileToolbar->addAction( exitAct );
	fileToolbar->addAction( newAct );
	fileToolbar->addAction( openAct );
        fileToolbar->addAction( saveAct );

	editToolbar = addToolBar( tr("&Edit") );
	editToolbar->setObjectName("editToolbar");
        editToolbar->setIconSize( QSize(16,16) );
	editToolbar->addAction( findAct );
	editToolbar->addAction( deleteAct );
	editToolbar->addAction( addCDAct );

        /*LOCATION BAR
	locationToolbar = addToolBar( tr("&Location") );
	locationToolbar->setObjectName("locationToolbar");
        locationToolbar->setIconSize( QSize(16,16) );
	locationToolbar->addAction( eraseLocationAct );

	lblPath = new QLabel( tr("Location"), locationToolbar );
	locationToolbar->addWidget( lblPath );

	txtPath = new QLineEdit(locationToolbar);
	txtPath->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	locationToolbar->addWidget( txtPath );
	connect(txtPath, SIGNAL(returnPressed()), this, SLOT(cmdPathClick()));

	locationToolbar->addAction( setPathAct );
        */
}

/**
 * Attempts to open the collection specified by the filename property. If the collection is opened conf.lastkat is updated to remeber this as the last collection opened.

void BiletMain::open() {
	if (!filename().isEmpty()) {

		if ( !sql->setName(filename()) ) {
			cdlist->clear();
			clearDirList();
			txtPath->setText("");
			setFilename("");
			sql->db.close();
			QMessageBox::critical(this, QCoreApplication::applicationName(), tr("Error during file opening")+"\n"+sql->db.lastError().text());
		} else {
			//lastPathNode helps prevent useless dirList refresh
			lastPathNode = -1;
			createCdlist();
			setPath("/");
			conf.lastkat = filename();

			QSettings settings;
			settings.setValue("application/lastkat",conf.lastkat);
			settings.deleteLater();
		}
	}
}


**
 * Generates the cd list
 *
void BiletMain::createCdlist() {
	cdlist->clear();

	QVector<NodeRecord> nodes = sql->getNodes(-1);
	QVectorIterator<NodeRecord> i(nodes);
	while (i.hasNext()) {
		NodeRecord nr = i.next();
		QSqlListItem* newCD = new QSqlListItem(cdlist);
		newCD->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled );
                newCD->setIcon( QIcon("/images/cdrom_unmount.png") );
		newCD->id = nr.id;
		newCD->setText( nr.name );
	}
}

**
 * Filename getter
 * @return current filename
 *
QString BiletMain::filename() {
	return this->aFilename;
}

**
 * Filename setter, this sets also the Window Title to include filename
 * @param name the name to set
 *
void BiletMain::setFilename( const QString name ) {
	this->aFilename = name;
	this->setWindowTitle( QCoreApplication::applicationName() );
	if (!name.isEmpty())
		this->setWindowTitle( this->windowTitle() + " - \"" + name + "\"" );
}





*/

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
    for(int i=0; i < bl->nrB.count(); i++){
        if(bl->nrB.at(i)->text().toInt())
            record.nrB << bl->nrB.at(i)->text().toInt();
    }
    for(int i=0; i < bl->nrC.count(); i++){
        if(bl->nrC.at(i)->text().toInt())
            record.nrC << bl->nrC.at(i)->text().toInt();
    }

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
		settings.setValue("mountpoint",conf.mountpoint);
		settings.setValue("startup",conf.startup);
		settings.setValue("startkat",conf.startkat);
		settings.setValue("locale",conf.locale);
		settings.endGroup();

		settings.beginGroup("thumbnails");
		settings.setValue("perdir",conf.thperdir);
		settings.setValue("enabled",conf.thenabled);
		settings.setValue("size",conf.thsize);
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

void BiletMain::editDeleteClicked() {

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
    svb->exec();

    QVector<BiletRecord> nodes = db.getAll();
    QVectorIterator<BiletRecord> i(nodes);
    while (i.hasNext()) {
            BiletRecord nr = i.next();
            //if(nr.biletID.contains(svb->nameB)) {
            if(nr.biletID == svb->nameB){
                QMessageBox::critical( 0, QCoreApplication::applicationName(), QCoreApplication::tr("Ticket exist. Try diferent name") );
                svb->exec();
            }
            //de verificare
            //textBrows->append(nr.biletID);
    }

    //textBrows->append(svb->nameB);
    if(!svb->nameB.isEmpty())
        if(bl->biletOK)
            db.AddBilet(biletToRecord(svb->nameB));
        else
            QMessageBox::critical( 0, QCoreApplication::applicationName(), QCoreApplication::tr("Ticket not save, try viewVar for more info") );

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
            newBilet->setIcon( QIcon("images/Save1.png") );
            //newBilet->id = nr.biletID;
            newBilet->setText( nr.biletID+"             "+nr.data);
            opb->SetList(newBilet);
    }
    opb->exec();
    aFilename = opb->idBilet.remove(QRegExp(" (.*)"));
    textBrows->append(aFilename);
    BiletRecord opBilet;
    opBilet = db.getBilet(aFilename);
    //QString cdf = QFileDialog::getOpenFileName( this, tr("Choose a BiletMain collection"), "", "BiletMain collections (*.cdf)" );
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
            //varEdit->setTextColor("blue");
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

