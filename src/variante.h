/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#ifndef VARIANTE_H
#define VARIANTE_H
#include <QList>
#include <QTableWidgetItem>
#include<QtAlgorithms>
#include<QMessageBox>
#include <QFile>
#include <zzip/zzip.h>

struct dateV
{
    short int n;    //nr. de numere selectate
    short int k;    //nr. de numere in varianta "combinari de n luata cate k"
    short int v;    //nr. de variante, pentru variantele reduse
    QString cod;    //vodul ales, pentru fisierul cu variantele reduse
};

class Variante
{
public:
    Variante(QList<QTableWidgetItem *> nrCamp, dateV cod);
    ~Variante();

    //QMessageBox msgVBox;

    //QList<short int*> calcVar(int pas);

    //short int varSimpla[6];

    QVector<short int*> variante;
    QVector<short int> nrj;

private:
    QVector<short int*> Combinari(int pas);
    void SetVar();
    void VarRedus();
    void ReadFile(QString fileName);
    //QVector<int> nrj;
    //QVector<short int> tmp;
    QMessageBox *msgVBox;
    short int *tmp;
    //short int cod;
    short int indic;
    short int a[49];
    short int b[49];
    int n, k, nrv_max;
    //int codv;
    QString codv;
};

#endif // VARIANTE_H
