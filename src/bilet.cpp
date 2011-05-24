/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#include "bilet.h"
#include <ctime>

Bilet::Bilet(QWidget *parent)
    : QWidget(parent)
{
    setupUi(parent);
    connect(CampA,SIGNAL(itemSelectionChanged()),this, SLOT(nrSelectA()));
    connect(CampB,SIGNAL(itemSelectionChanged()),this, SLOT(nrSelectB()));
    connect(CampC,SIGNAL(itemSelectionChanged()),this, SLOT(nrSelectC()));
    connect(CodA,SIGNAL(itemSelectionChanged()),this, SLOT(codSelectA()));
    connect(CodB,SIGNAL(itemSelectionChanged()),this, SLOT(codSelectB()));
    connect(CodC,SIGNAL(itemSelectionChanged()),this, SLOT(codSelectC()));
    srand((unsigned)time(0));
    biletOK = false;
    codA = -1;
    codB = -1;
    codC = -1;
}

void Bilet::clearSelection()
{
    CampA->clearSelection();
    CodA->clearSelection();

    CampB->clearSelection();
    CodB->clearSelection();

    CampC->clearSelection();
    CodC->clearSelection();
    emit SelectionChanged();
}

dateV Bilet::setStop(int cod)
{
    dateV nrstop;
    nrstop.n = 0;
    nrstop.k = 0;
    nrstop.v = 0;
    nrstop.cod = "complet";
    switch(cod){
        case -1 : nrstop.n = 12;
            nrstop.k = 6;
            break;
        case 0 : nrstop.n = 12;
            nrstop.k = 6;
            break;
        case 1 : nrstop.n = 12;
            nrstop.k = 1;
            break;
        case 2 : nrstop.n = 12;
            nrstop.k = 2;
            break;
        case 3 : nrstop.n = 12;
            nrstop.k = 3;
            break;
        case 4 : nrstop.n = 12;
            nrstop.k = 4;
            break;
        case 5 : nrstop.n = 12;
            nrstop.k = 5;
            break;
        case 10 : nrstop.n = 10;
            nrstop.k = 2;
            nrstop.v = 5;
            nrstop.cod = "10.txt";
            break;
    case 16 : nrstop.n = 12;
        nrstop.k = 2;
        nrstop.v = 6;
        nrstop.cod = "16.txt";
        break;
    case 17 : nrstop.n = 14;
        nrstop.k = 2;
        nrstop.v = 7;
        nrstop.cod = "17.txt";
        break;
    case 18 : nrstop.n = 16;
        nrstop.k = 2;
        nrstop.v = 8;
        nrstop.cod = "18.txt";
        break;
    case 19 : nrstop.n = 18;
        nrstop.k = 2;
        nrstop.v = 9;
        nrstop.cod = "19.txt";
        break;
    case 20 : nrstop.n = 20;
        nrstop.k = 2;
        nrstop.v = 10;
        nrstop.cod = "20.txt";
        break;
    case 26 : nrstop.n = 7;
        nrstop.k = 3;
        nrstop.v = 7;
        nrstop.cod = "26.txt";
        break;
    case 27 : nrstop.n = 9;
        nrstop.k = 3;
        nrstop.v = 12;
        nrstop.cod = "27.txt";
        break;
    case 28 : nrstop.n = 13;
        nrstop.k = 3;
        nrstop.v = 26;
        nrstop.cod = "28.txt";
        break;
    case 29 : nrstop.n = 15;
        nrstop.k = 3;
        nrstop.v = 35;
        nrstop.cod = "29.txt";
        break;
    case 30 : nrstop.n = 19;
        nrstop.k = 3;
        nrstop.v = 57;
        nrstop.cod = "30.txt";
        break;
    case 36 : nrstop.n = 21;
        nrstop.k = 3;
        nrstop.v = 70;
        nrstop.cod = "36.txt";
        break;
    case 37 : nrstop.n = 25;
        nrstop.k = 3;
        nrstop.v = 100;
        nrstop.cod = "37.txt";
        break;
    case 38 : nrstop.n = 8;
        nrstop.k = 4;
        nrstop.v = 14;
        nrstop.cod = "38.txt";
        break;
    case 39 : nrstop.n = 10;
        nrstop.k = 4;
        nrstop.v = 30;
        nrstop.cod = "39.txt";
        break;
    case 40 : nrstop.n = 16;
        nrstop.k = 4;
        nrstop.v = 140;
        nrstop.cod = "40.txt";
        break;
    case 46 : nrstop.n = 20;
        nrstop.k = 4;
        nrstop.v = 285;
        nrstop.cod = "46.txt";
        break;
    case 47 : nrstop.n = 32;
        nrstop.k = 4;
        nrstop.v = 1240;
        nrstop.cod = "47.txt";
        break;
        case 48 : nrstop.n = 9;
            nrstop.k = 6;
            nrstop.v = 12;
            nrstop.cod = "48.txt";
            break;
        case 49 : nrstop.n = 10;
            nrstop.k = 6;
            nrstop.v = 15;
            nrstop.cod = "49.txt";
            break;

        case 50 : nrstop.n = 10;
            nrstop.k = 6;
            nrstop.v = 30;
            nrstop.cod = "50.txt";
            break;

        case 56 : nrstop.n = 11;
            nrstop.k = 6;
            nrstop.v = 66;
            nrstop.cod = "56.txt";
            break;

        case 57 : nrstop.n = 12;
            nrstop.k = 6;
            nrstop.v = 22;
            nrstop.cod = "57.txt";
            break;

        case 58 : nrstop.n = 12;
            nrstop.k = 6;
            nrstop.v = 132;
            nrstop.cod = "58.txt";
            break;

        case 59 : nrstop.n = 16;
            nrstop.k = 6;
            nrstop.v = 112;
            nrstop.cod = "59.txt";
            break;

    default :  nrstop.n = 0;
    }
    return nrstop;
}

void Bilet::codSelectA()
{

    QString tmp;

    if(CodA->selectedItems().count() > 2)
        for(int i = 2;  i <= CodA->selectedItems().count();i++)
            CodA->selectedItems().at(i)->setSelected(false);
    Acod = CodA->selectedItems();

    QList<int> list;
    list[0]=-1;
    for(int i = 0;  i < Acod.count(); i++)
        list<<Acod.at(i)->text().toInt();

    if(Acod.count()==2){
        qSort(list.begin(), list.end());
        if(list[0] == 0)tmp.sprintf("%d%d",list[1],list[0]);
        else tmp.sprintf("%d%d",list[0],list[1]);
    }
    else tmp.sprintf("%d",list[0]);
    codA = tmp.toInt();

    //dor pt verificare.......
    //tmp1 = QString::number(codA);
    //tmp1 = QString::number(setStop(codA).n);
    //.........
    emit SelectionChanged();
    tmp.clear();
}
void Bilet::codSelectB()
{
    QString tmp;
    if(CodB->selectedItems().count() > 2)
        for(int i = 2;  i <= CodB->selectedItems().count();i++)
            CodB->selectedItems().at(i)->setSelected(false);
    Bcod = CodB->selectedItems();

    QList<int> list;
    list[0]=-1;
    for(int i = 0;  i < Bcod.count(); i++)
        list<<Bcod.at(i)->text().toInt();

    if(Bcod.count()==2){
        qSort(list.begin(), list.end());
        if(list[0] == 0)tmp.sprintf("%d%d",list[1],list[0]);
        else tmp.sprintf("%d%d",list[0],list[1]);
    }
    else tmp.sprintf("%d",list[0]);
    codB = tmp.toInt();
    //dor pt verificare.......
    //tmp1 = QString::number(codB);
    //tmp1 = QString::number(setStop(codB).n);
    //.........
    emit SelectionChanged();
    tmp.clear();
}

void Bilet::codSelectC()
{
    QString tmp;
    tmp.clear();
    if(CodC->selectedItems().count() > 2)
        for(int i = 2;  i <= CodC->selectedItems().count();i++)
            CodC->selectedItems().at(i)->setSelected(false);
    Ccod = CodC->selectedItems();

    QList<int> list;
    list[0]=-1;
    for(int i = 0;  i < Ccod.count(); i++)
        list<<Ccod.at(i)->text().toInt();

    if(Ccod.count()==2){
        qSort(list.begin(), list.end());
        if(list[0] == 0)tmp.sprintf("%d%d",list[1],list[0]);
        else tmp.sprintf("%d%d",list[0],list[1]);
    }
    else tmp.sprintf("%d",list[0]);
    codC = tmp.toInt();

    //dor pt verificare.......
    //tmp1 = QString::number(codC);
    //tmp1 = QString::number(setStop(codC).n);
    //.........
    emit SelectionChanged();
    tmp.clear();
}


void Bilet::setCod()
{

}


void Bilet::nrSelectA()
{
    //selectare nr Camp A
    //************************************
    //short int nrstopA = setStop(codA).n;
    varbilet.clear();
    if(CampA->selectedItems().count() > setStop(codA).n)
        for(int i = setStop(codA).n;  i <= CampA->selectedItems().count();i++)
            CampA->selectedItems().at(i)->setSelected(false);
    nrA = CampA->selectedItems();
    emit SelectionChanged();
    //qSort(nrA.begin(), nrA.end());
    //end camp A ************
}
void Bilet::nrSelectB()
{
    //short int nrstopB = setStop(codB).n;
    varbilet.clear();
    if(CampB->selectedItems().count() > setStop(codB).n)
        for(int i = setStop(codB).n;  i <= CampB->selectedItems().count();i++)
            CampB->selectedItems().at(i)->setSelected(false);

    nrB = CampB->selectedItems();
    emit SelectionChanged();
}
void Bilet::nrSelectC()
{
    //short int nrstopC = setStop(codC).n;
    varbilet.clear();
    if(CampC->selectedItems().count() > setStop(codC).n)
        for(int i = setStop(codC).n;  i <= CampC->selectedItems().count();i++)
            CampC->selectedItems().at(i)->setSelected(false);
    nrC = CampC->selectedItems();
    emit SelectionChanged();
}

QVector<short int*>Bilet::GenVarBilet()
{
    QVector<short int*> tmpvar(0);
    short int *tmp = 0;
    QString charnr;
    Variante varA = Variante(nrA,setStop(codA));
    Variante varB = Variante(nrB,setStop(codB));
    Variante varC = Variante(nrC,setStop(codC));

    if((nrA.count() < setStop(codA).k) && nrA.count() > 0){
        msgBox = new QMessageBox;
        msgBox->setText("Pleas select more number on fild A");
        msgBox->exec();
        delete msgBox;
        return tmpvar;
    }
    if(setStop(codA).cod != "complet" && nrA.count() < setStop(codA).n){
        msgBox = new QMessageBox;
        charnr.sprintf("%d",setStop(codA).n);
        msgBox->setText("Fild A mast have "+charnr+" numbers");
        msgBox->exec();
        delete msgBox;
        return tmpvar;
    }

    if(nrB.count() < setStop(codB).k && nrB.count() > 0){
        msgBox = new QMessageBox;
        msgBox->setText("Pleas select more number on fild B");
        msgBox->exec();
        delete msgBox;
        return tmpvar;
    }
    if(setStop(codB).cod != "complet" && nrB.count() < setStop(codB).n){
        msgBox = new QMessageBox;
        charnr.sprintf("%d",setStop(codB).n);
        msgBox->setText("Fild B mast have "+charnr+" numbers");
        msgBox->exec();
        delete msgBox;
        return tmpvar;
    }


    if(nrC.count() < setStop(codC).k && nrC.count() > 0)
    {
        msgBox = new QMessageBox;
        msgBox->setText("Pleas select more number on fild C");
        msgBox->exec();
        delete msgBox;
        return tmpvar;
    }
    if(setStop(codC).cod != "complet" && nrC.count() < setStop(codC).n){
        msgBox = new QMessageBox;
        charnr.sprintf("%d",setStop(codC).n);
        msgBox->setText("Fild C mast have "+charnr+" numbers");
        msgBox->exec();
        delete msgBox;
        return tmpvar;
    }

    //if(nrA.count() < )

    if(setStop(codA).k == 6){
        tmpvar<<varA.variante;
        if(setStop(codB).k == 6){
            tmpvar<<varB.variante;
        if(setStop(codC).k == 6)
            tmpvar<<varC.variante;
        else {
            msgBox = new QMessageBox;
            msgBox->setText("Campul C este completat gresit");
            msgBox->exec();
            delete msgBox;
            return tmpvar;
            }
        }
        //schema compusa C+B
        else if((setStop(codC).k + setStop(codB).k) == 6)
            if(Diff(nrC, nrB)){
             for(int vb = 0; vb < varB.variante.count(); vb++ )
                for(int vc = 0; vc < varC.variante.count(); vc++ ){
                    tmp = new short int[6];
                    for(int i = 0; i < setStop(codB).k; i++ )
                        tmp[i] = varB.variante.at(vb)[i];
                    for(int j = 0; j < setStop(codC).k; j++ )
                        tmp[setStop(codB).k + j] = varC.variante.at(vc)[j];
                    tmpvar<<tmp;
                    }
                }
             else{
                msgBox = new QMessageBox;
                msgBox->setText("Numerele din campurile B si C trebui sa fie diferite");
                msgBox->exec();
                delete msgBox;
                return tmpvar;
                }

            else {// prelucrare bilet camp B
                msgBox = new QMessageBox;
                msgBox->setText("Campul B este completat gresit");
                msgBox->exec();
                delete msgBox;
                return tmpvar;
                }

    }
    else if((setStop(codA).k + setStop(codB).k) == 6){ //A+B = 6
        if(Diff(nrA, nrB))
        for(int va = 0; va < varA.variante.count(); va++ )
            for(int vb = 0; vb < varB.variante.count(); vb++ ){
                tmp = new short int[6];
                for(int i = 0; i < setStop(codA).k; i++ )
                    tmp[i] = varA.variante.at(va)[i];
                for(int j = 0; j < setStop(codB).k; j++ )
                    tmp[setStop(codA).k + j] = varB.variante.at(vb)[j];
                tmpvar<<tmp;
            }
        else{
            msgBox = new QMessageBox;
            msgBox->setText("Numerele din campurile A si B trebui sa fie diferite");
            msgBox->exec();
            delete msgBox;
            return tmpvar;
        }

        if(setStop(codC).k == 6) tmpvar<<varC.variante;
        else{
            msgBox = new QMessageBox;
            msgBox->setText("Campul C este completat gresit");
            msgBox->exec();
            delete msgBox;
            return tmpvar;
        }
    }
        else if((setStop(codA).k + setStop(codB).k) + setStop(codC).k == 6)
            if(Diff(nrA, nrB, nrC))
            for(int va = 0; va < varA.variante.count(); va++ )
                for(int vb = 0; vb < varB.variante.count(); vb++ )
                    for(int vc = 0; vc < varC.variante.count(); vc++ ){
                        tmp = new short int[6];
                        for(int i = 0; i < setStop(codA).k; i++ )
                            tmp[i] = varA.variante.at(va)[i];
                        for(int j = 0; j < setStop(codB).k; j++ )
                            tmp[setStop(codA).k + j] = varB.variante.at(vb)[j];
                        for(int k = 0; k < setStop(codC).k; k++ )
                            tmp[setStop(codA).k + setStop(codB).k + k] = varC.variante.at(vc)[k];
                        tmpvar<<tmp;
                    }
            else { // prelucrare bilet camp A
                 msgBox = new QMessageBox;
                 msgBox->setText("Numerele din campurile A, B si C trebui sa fie diferite");
                 msgBox->exec();
                 delete msgBox;
                 return tmpvar;
                 }

            else { // prelucrare bilet camp A
                msgBox = new QMessageBox;
                msgBox->setText("Campul A este completat gresit");
                msgBox->exec();
                delete msgBox;
                return tmpvar;
                }
    biletOK = true;
    return tmpvar;
}

bool Bilet::Diff(QList<QTableWidgetItem *> a, QList<QTableWidgetItem *> b)
{
    for(int i = 0; i<a.count(); i++)
        for(int j = 0; j < b.count(); j++)
            if(b.at(j)->text().toInt() == a.at(i)->text().toInt())
                    return false;
    return true;
}

bool Bilet::Diff(QList<QTableWidgetItem *> a, QList<QTableWidgetItem *> b, QList<QTableWidgetItem *> c )
{
    for(int i = 0; i<a.count(); i++)
        for(int j = 0; j < b.count(); j++)
            for(int k = 0; k < c.count(); k++){
            if(c.at(k)->text().toInt() == b.at(j)->text().toInt())
                return false;
            if(c.at(k)->text().toInt() == a.at(i)->text().toInt())
                return false;
            if(b.at(j)->text().toInt() == a.at(i)->text().toInt())
                return false;
            }

    return true;
}

void Bilet::RecToBl(BiletRecord brec)
{
    clearSelection();
    int x = 0;
    int y = 0;
    int row = 0;
    int column = 0;
 //set numerele selectate si codul pe campil A
    if(brec.codA > 0){
        if(brec.codA > 5){
            //modf(((double)brec.codA/10), &x);
            x = brec.codA/10;
            y = brec.codA - x*10;
            CodA->item(x-1,0)->setSelected(true);
            if(y == 0) CodA->item(4,1)->setSelected(true);
            else CodA->item(y-6,1)->setSelected(true);
        }
        else CodA->item(brec.codA-1,0)->setSelected(true);
    }

    if(brec.nrA.count() > 0){
        for(int i=0; i<brec.nrA.count(); i++){
            row = (brec.nrA[i]-1)/10;
            column = (brec.nrA[i]-1) - row*10;
            CampA->item(row, column)->setSelected(true);
        }
    }
 //sfarsit camp A

 //set numerele selectate si codul pe campil B
    if(brec.codB > 0){
        if(brec.codB > 5){
            x = brec.codB/10;
            y = brec.codB - x*10;
            CodB->item(x-1,0)->setSelected(true);
            if(y == 0) CodB->item(4,1)->setSelected(true);
            else CodB->item(y-6,1)->setSelected(true);
        }
        else CodB->item(brec.codB-1,0)->setSelected(true);
    }
    if(brec.nrB.count() > 0){
        for(double i=0; i<brec.nrB.count(); i++){
            row = (brec.nrB[i]-1)/10;
            column = (brec.nrB[i]-1) - row*10;
            CampB->item(row, column)->setSelected(true);
        }
    }
//sfarsit camp B

//set numerele selectate si codul pe campil C
    if(brec.codC > 0){
        if(brec.codC > 5){
            x = brec.codC/10;
            y = brec.codC - x*10;
            CodC->item(x-1,0)->setSelected(true);
            if(y == 0) CodC->item(4,1)->setSelected(true);
            else CodC->item(y-6,1)->setSelected(true);
        }
        else CodC->item(brec.codC-1,0)->setSelected(true);
    }

    if(brec.nrC.count() > 0){
        for(double i=0; i<brec.nrC.count(); i++){
            row = (brec.nrC[i]-1)/10;
            column = (brec.nrC[i]-1) - row*10;
            CampC->item(row, column)->setSelected(true);
        }
    }
//sfarsit camp C
}

void Bilet::RandNr(int a)
{

    //int range_row = 4, row[16];
    //int range_column = 10, column[16];
    //int lowest=0, highest=49;
    //int range=(highest-lowest)+1;
    int rand_nr[49], row = 0, column = 0;
    QTableWidget *camp = CampA;
    if(a==1) camp = CampA;
    if(a==2) camp = CampB;
    if(a==3) camp = CampC;
    for(int i=0; i<6; i++){
        iar:
        rand_nr[i] = 1 + int(48*rand()/(RAND_MAX + 1.0));
        for(int j=0; j<i; j++){
            if(rand_nr[i]==rand_nr[j])
                goto iar;//rand_nr[i]=1+int(48*rand()/(RAND_MAX + 1.0));
        }
        row = (rand_nr[i]-1)/10;
        column = (rand_nr[i]-1) - row*10;
        camp->item(row, column)->setSelected(true);
    }
    /*
    for(int index=0; index<6; index++){
        row[index] = 0+int(range_row*rand()/(RAND_MAX + 1.0));
        column[index] = 0+int(range_column*rand()/(RAND_MAX + 1.0));
        if(index>0 && (row[index]==row[index-1]&& column[index]==column[index-1])){
            row[index] = 0+int(range_row*rand()/(RAND_MAX + 1.0));
            column[index] = 0+int(range_column*rand()/(RAND_MAX + 1.0));
        }
        if(row[index]==3 && column[index]==9){
            row[index] = 0+int(range_row*rand()/(RAND_MAX + 1.0));
            column[index] = 0+int(range_column*rand()/(RAND_MAX + 1.0));
        }
        else camp->item(row[index], column[index])->setSelected(true);
    }*/
}





