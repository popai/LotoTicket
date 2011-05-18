/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#include "mainloto.h"

MainLoto::MainLoto(QWidget *parent) :
    QMainWindow(parent)
{

    setupUi(this);
    this->setStyleSheet("QTableWidget { selection-background-color: rgb(255, 117, 24) }");
    bl = new Bilet(tab);
}

MainLoto::~MainLoto()
{
    //delete ui;
}
