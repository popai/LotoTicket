/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/
#include "savebilet.h"

SaveBilet::SaveBilet(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

SaveBilet::~SaveBilet()
{
    //delete ui;
}

void SaveBilet::accept()
{
    nameB = saveName->text();
    close();
}

void SaveBilet::SetList(QListWidgetItem *numeB)
{
    saveList->addItem(numeB);
}


