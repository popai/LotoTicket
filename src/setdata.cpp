#include "setdata.h"
#include "ui_setdata.h"

SetData::SetData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetData)
{
    ui->setupUi(this);
}

SetData::~SetData()
{
    delete ui;
}
