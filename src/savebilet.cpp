#include "savebilet.h"
#include "ui_savebilet.h"

SaveBilet::SaveBilet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveBilet)
{
    ui->setupUi(this);
}

SaveBilet::~SaveBilet()
{
    delete ui;
}
