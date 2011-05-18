/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#include "openbilet.h"

OpenBilet::OpenBilet(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    idBilet = "";
}

OpenBilet::~OpenBilet()
{
    //delete ui;
}

void OpenBilet::SetList(QListWidgetItem *numeB)
{
    openList->addItem(numeB);
}

void OpenBilet::accept()
{
    if(openList->currentItem())
        idBilet = openList->currentItem()->text();
    close();
}
