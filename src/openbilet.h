/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/
#ifndef OPENBILET_H
#define OPENBILET_H

#include <QDialog>
#include "ui_openbilet.h"


class OpenBilet : public QDialog, private Ui::UOpenBilet
{
    Q_OBJECT

public:
    explicit OpenBilet(QWidget *parent = 0);
    ~OpenBilet();

    void SetList(QListWidgetItem *numeB);
    //QListWidget* GetList();

    QString idBilet;

private slots:
    virtual void accept();

};

#endif // OPENBILET_H
