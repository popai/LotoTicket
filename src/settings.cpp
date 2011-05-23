/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/


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

        //priceV
        priceV->setValue(conf->price_V);


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
        conf->price_V = priceV->value();



        //conf->startkat = txtStart->text();

	//Locale
	conf->locale = languages->at(cmbLocale->currentIndex()).langcode;

	accept();
}
