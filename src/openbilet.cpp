#include "openbilet.h"

OpenBilet::OpenBilet(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
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
    idBilet = openList->currentItem()->text();
    close();
}
