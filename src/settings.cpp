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

#include "settings.h"
#include "BiletLoto.h"

Settings::Settings(QWidget *parent)
                : QDialog(parent)
{
	setupUi(this);

        //connect( btnBrowseKat, SIGNAL(clicked()), this, SLOT(browseKat()) );
	connect( buttonOk, SIGNAL(clicked()), this, SLOT(apply()) );

        conf = &((BiletMain*)parent)->conf;
	switch(conf->startup) {
			case 0:
			radStartLast->setChecked(true);
			break;
			case 1:
			radStartSpecified->setChecked(true);
			break;
			case 2:
			radStartBlank->setChecked(true);
	}


	//Locale
        languages = &((BiletMain*)parent)->languages;
	for (int x=0; x<languages->size(); x++) {
		cmbLocale->insertItem(x,QIcon(":/flags/"+languages->at(x).langcode.left(2)+".png"),languages->at(x).langname);
		if (languages->at(x).langcode == conf->locale)
			cmbLocale->setCurrentIndex(x);
	}
}

void Settings::apply() {
        conf->lotoname = lotoName->text();
        conf->nrextrase = extractNr->value();
        conf->nrmax = maxNr->value();


	if (radStartLast->isChecked())
		conf->startup = 0;
	if (radStartSpecified->isChecked())
		conf->startup = 1;
	if (radStartBlank->isChecked())
		conf->startup = 2;
        //conf->startkat = txtStart->text();

	//Locale
	conf->locale = languages->at(cmbLocale->currentIndex()).langcode;

	accept();
}
