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

