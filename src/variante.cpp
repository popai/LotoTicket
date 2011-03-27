/****************************************************************************
**
**
**
****************************************************************************/

#include "variante.h"

Variante::Variante(QList<QTableWidgetItem *> nrCamp, dateV cod)
{
    //nrj = nrCamp.toVector();
    //n = nrCamp.count();
    n = cod.n;
    k = cod.k;
    nrv_max = cod.v;
    codv = cod.cod;
    indic = 0;
    tmp = 0;
    for(int i = 0; i<49; i++){
        a[i]=0;
        b[i]=0;
    }

    //cod = codCamp;
    for(int i=0; i<nrCamp.count(); i++)
        nrj<<nrCamp.at(i)->text().toInt();
    qSort(nrj.begin(), nrj.end());
    //Combinari(1);
    SetVar();

}

QVector<short int*>Variante::Combinari(int pas)
{
    tmp = new short int[k];
    if(pas-1 == k) //afisam solutia
        {
        for(int i = 1; i <= k;i++)
            tmp[i-1] = nrj.value(a[i]); 

        variante<<tmp;
    }
    else
    {
        for(int  i = 1; i <= nrj.count(); i++)
           if(!b[i] && a[pas-1] < i)  //ne asiguram ca generam solutiile crescatoare si unice
          {
                a[pas] = i-1;
                b[i] = 1; //o folosim
                Combinari(pas+1); //trecem la pasul urmator
                b[i] = 0;   //o eliberam
          }
    }
    return variante;
}

void Variante::ReadFile(QString fileName)
{
    QFile ifile(fileName);
    if(!ifile.open(QIODevice::ReadOnly | QIODevice::Text)){
        //msgVBox = new QMessageBox;
        msgVBox->setText("Eroare citire fisier variante reduse");
        msgVBox->exec();
    }
    else{
        tmp = new short int[6];
        char *c = new char;
        int i=0;
        int j=0;
        //int nrv=0;
        //variante[0]=new short int[6];

        while(!ifile.atEnd()){
            ifile.getChar(c);
            if(*c == '\t') i++;
            if(*c == '\n'){
                i=0;
                j=0;
                //nrv++;
                //var.resize(nrv);
                variante<<tmp;
                //if(nrv != nrv_max)
                    tmp = new short int[6];
            }
            if(*c == 'x'){
                tmp[j] = nrj[i-1];
                j++;
                }
        }

    }
    ifile.close();
}

void Variante::SetVar()
{
    msgVBox = new QMessageBox;
    if(nrj.count())
        if(!codv.compare("complet"))
            Combinari(1);
        else ReadFile(codv);
    else if(codv.compare("complet")){
        msgVBox->setText("Nu ati completat numere");
        msgVBox->exec();
        }
}

Variante::~Variante()
{
    //delete nrj;
    delete tmp;
}

