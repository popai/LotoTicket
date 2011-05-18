/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/
#ifndef DELETE_H
#define DELETE_H

#include "ui_delete.h"

class Delete : public QDialog, private Ui::Delete
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = 0);

    void SetList(QListWidgetItem *numeB);
    //QListWidget* GetList();

    QString idBilet;

private slots:
    virtual void accept();

};

#endif // DELETE_H
