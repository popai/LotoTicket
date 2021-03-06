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

#ifndef _BILETLOTO_H_
#define _BILETLOTO_H_

#include <cmath>
#include <QMainWindow>
#include "bilet.h"
#include "vardb.h"
#include "savebilet.h"
#include "openbilet.h"
#include "delete.h"
#include "codlist.h"


class QListWidget;
class QTableWidget;
class QTabWidget;
class QProgressBar;
class QToolButton;
class QLineEdit;
class QLabel;
class QMenu;
class QAction;
class QToolBar;
class QTranslator;

struct configuration {

        int nrextrase, nrmax;
        double price_V;
        QString lotoname, locale;
};

struct langinfo {
	QString langcode, langname;
};

/**
 * @short Application Main Window
 * @author Ryo Saeba <ryosaeba@dotgeek.org>
 * @version 0.3
 */
class BiletMain : public QMainWindow {
		Q_OBJECT
	protected:
                void closeEvent(QCloseEvent *);

	private:
		QString aFilename;

		//PROGRESS STATUS
		QProgressBar *progress;
		QToolButton *btnStop;

		//MENUS
		QMenu *fileMenu;
		QMenu *editMenu;
		QMenu *viewMenu;
		QMenu *helpMenu;

		//TOOLBARS
		QToolBar *fileToolbar;
		QToolBar *editToolbar;
		QToolBar *locationToolbar;

                //TabWidget
                QTabWidget *tabWidget;
                QWidget *tab1;
                QWidget *tab2;

                //tab1 widgets
                QTextBrowser *textBrows;
                QSpacerItem *spacerH;
                QGroupBox *grupBox;
                QPushButton *clearTiket;
                QPushButton *viewVar;
                QGroupBox *QicPicBox;
                QLabel *label, *label_t1;
                QDateEdit *dateEdit;
                QSpinBox *spinBox_t1;
                QHBoxLayout *layoutH;
                QVBoxLayout *layoutV;
                QCheckBox *checkBoxA;
                QCheckBox *checkBoxB;
                QCheckBox *checkBoxC;
                QPushButton *pickButon;
                QWidget *widget;


                //tab2 widgets
                QTextBrowser *text2Brows;
                QGroupBox *grup2Box;
                QHBoxLayout *layout2H;
                QVBoxLayout *layout2V;
                QLabel *label_2, *label_3, *label_4, *label_5, *label_6, *label_7, *label_8;
                QSpinBox *spinBox, *spinBox_1, *spinBox_2, *spinBox_3, *spinBox_4, *spinBox_5, *spinBox_6;
                QDoubleSpinBox *spinBox_7, *spinBox_8, *spinBox_9, *spinBox_10;
                QWidget *layoutWidget2, *layoutWidget3;
                QHBoxLayout *horizontalLayout_2;
                QGridLayout *gridLayout;
                QFrame *line, *line_2;
                QPushButton *chackButton;
                QDateEdit *dateEdit_2;

		//ACTIONS
		QAction *newAct;
		QAction *openAct;
                QAction *saveAct;
		QAction *exitAct;

		QAction *settingsAct;
		QAction *findAct;
		QAction *deleteAct;
                QAction *viewAct;
                QAction *clearAct;

		QAction *aboutAct;
                QAction *codlistAct;

                //QAction *eraseLocationAct;
                //QAction *setPathAct;

                //void createCdlist();
		void createActions();
		void createMenu();
		void createToolbar();

                //void clearDirList();

		void setupWidgets();

	public slots:

                virtual void writeVariante();
                virtual void ChackWin();
                virtual void QuickPick();
                virtual void Cod_List();

		//menu events
		virtual void aboutClicked();
		virtual void editSettingsClicked();
		virtual void editFindClicked();
		virtual void editDeleteClicked();
		virtual void fileExitClicked();
		virtual void fileOpenClicked();
		virtual void fileNewClicked();
                virtual void fileSaveClicked();

	public:

		configuration conf;

		QTranslator *translator;
		QVector<langinfo> languages;

                BiletRecord biletToRecord(QString numeBilet);

		void showProgress( bool, int max = 100 );
		void setProgress( int );

                Bilet *bl;
                VarDb db;
                SaveBilet *svb;
                OpenBilet *opb;
                Delete *del;
                CodList *codlist;
                QString *rezultate;

		/**
		 * Default Constructor
		 */
                BiletMain(QWidget *parent = 0);

		/**
		 * Default Destructor
		 */
                ~BiletMain();
};

#endif // _BILETLOTO_H_
