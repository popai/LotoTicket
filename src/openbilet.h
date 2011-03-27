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

};

#endif // OPENBILET_H
