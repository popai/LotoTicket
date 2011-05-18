/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/
#ifndef BILET_H
#define BILET_H

#include "ui_bilet.h"
#include <QtGui>
#include"variante.h"
#include"vardb.h"

//struct BiletRecord;
/*
struct BiletRecord {
        short int codA;
        short int codB;
        short int codC;
        QVector<short int> nrA;
        QVector<short int> nrB;
        QVector<short int> nrC;
        QString data;
        QString biletID;

        //valori implicite pt cod.
        BiletRecord():codA(0),codB(0),codC(0){}
};

struct dateV
{
    short int n;    //nr. de numere selectate
    short int k;    //nr. de numere in varianta "combinari de n luata cate k"
    short int v;    //nr. de variante, pentru variantele reduse
    QString cod;    //codul ales, pentru fisierul cu variantele reduse
};
*/

class Bilet :public QWidget, private Ui::UBilet
{
    Q_OBJECT
public:
    Bilet(QWidget *parent = 0);

    //bool VerificBilet(){return 0;}
    void RecToBl(BiletRecord brec);
    QVector<short int*> GenVarBilet();
    bool Diff(QList<QTableWidgetItem *> a, QList<QTableWidgetItem *> b );
    bool Diff(QList<QTableWidgetItem *> a, QList<QTableWidgetItem *> b, QList<QTableWidgetItem *> c );


    QList<QTableWidgetItem *> nrA;
    QList<QTableWidgetItem *> nrB;
    QList<QTableWidgetItem *> nrC;

    QList<QTableWidgetItem *> Acod;
    QList<QTableWidgetItem *> Bcod;
    QList<QTableWidgetItem *> Ccod;

    QVector<short int*> varbilet;

    short int codA;
    short int codB;
    short int codC;
    //BiletRecord bRec;
    QString tmp1;
    bool biletOK;
    //int row,column;

public slots:
    void nrSelectA();
    void nrSelectB();
    void nrSelectC();

    void codSelectA();
    void codSelectB();
    void codSelectC();
    //dateV GetCod();

    void clearSelection();
    void setCod();

private:

    //int setStop(int cod);
    dateV setStop(int cod);

    QMessageBox *msgBox;

};

#endif // BILET_H
