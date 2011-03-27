#include "mainloto.h"

MainLoto::MainLoto(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::LotoM)
{
    //ui->
    setupUi(this);
    this->setStyleSheet("QTableWidget { selection-background-color: rgb(255, 117, 24) }");
    bl = new Bilet(tab);
}

MainLoto::~MainLoto()
{
    //delete ui;
}
