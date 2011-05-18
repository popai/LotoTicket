/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#include "delete.h"

Delete::Delete(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void Delete::SetList(QListWidgetItem *numeB)
{
    deleteList->addItem(numeB);
}

void Delete::accept()
{
    if(deleteList->currentItem())
        idBilet = deleteList->currentItem()->text();
    close();
}
