/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/
#ifndef MAINLOTO_H
#define MAINLOTO_H

#include <QMainWindow>
#include <bilet.h>
#include "ui_mainloto.h"

//namespace Ui {
  //  class LotoM;
//}

class MainLoto : public QMainWindow, private Ui::LotoM
{
    Q_OBJECT

public:
    explicit MainLoto(QWidget *parent = 0);
    ~MainLoto();
    Bilet *bl;

private:
    //Ui::LotoM *ui;
};

#endif // MAINLOTO_H
