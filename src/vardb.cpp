//
// C++ Implementation: VarDb
//
// Description:
//
//
// Author: Popa Ionel <popai@b.astral.ro>, (C) 2011
//
// Copyright: See LICENSE file that comes with this distribution
//
//
#include "vardb.h"
#include <QtGui/QApplication>
#include <QtSql>



VarDb::VarDb(  ) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    if (!db.isValid())
        QMessageBox::critical( 0, QCoreApplication::applicationName(), QCoreApplication::tr("The database is not valid!") );
    db.setDatabaseName( "nou.sql" );
    //pt verificare
    if(!db.open())
        QMessageBox::critical( 0, QCoreApplication::applicationName(), QCoreApplication::tr("The database is not open!") );

}


VarDb::~VarDb() {
	if (db.isOpen()) db.close();
}


bool VarDb::newDB( QString name ) {
	if (db.isOpen()) db.close();

	db.setDatabaseName( name );
	db.open() ? this->aname = name : this->aname = "";

	if (this->aname.isEmpty()) return false;

        QString Bilet ("CREATE TABLE Bilet ( biletID TEXT NOT NULL UNIQUE, data DATETIME NOT NULL  DEFAULT CURRENT_DATE)");
        if(checkQuery(Bilet)) db.exec(Bilet);

        QString nrCampA ("CREATE TABLE nrCampA ( biletID TEXT NOT NULL  UNIQUE , nr1 INTEGER DEFAULT 0, nr2 INTEGER DEFAULT 0,\
                                                  nr3 INTEGER DEFAULT 0, nr4 INTEGER DEFAULT 0, nr5 INTEGER DEFAULT 0, nr6 INTEGER DEFAULT 0, \
                                                  nr7 INTEGER DEFAULT 0, nr8 INTEGER DEFAULT 0, nr9 INTEGER DEFAULT 0, nr10 INTEGER DEFAULT 0, \
                                                  nr11 INTEGER DEFAULT 0, nr12 INTEGER DEFAULT 0, nr13 INTEGER DEFAULT 0, nr14 INTEGER DEFAULT 0, \
                                                  nr15 INTEGER DEFAULT 0, nr16 INTEGER DEFAULT 0, cod INTEGER DEFAULT 0)");
        if(checkQuery(nrCampA)) db.exec(nrCampA);

        QString nrCampB ("CREATE TABLE nrCampB ( biletID TEXT NOT NULL  UNIQUE , nr1 INTEGER DEFAULT 0, nr2 INTEGER DEFAULT 0, \
                                                  nr3 INTEGER DEFAULT 0, nr4 INTEGER DEFAULT 0, nr5 INTEGER DEFAULT 0, nr6 INTEGER DEFAULT 0, \
                                                  nr7 INTEGER DEFAULT 0, nr8 INTEGER DEFAULT 0, nr9 INTEGER DEFAULT 0, nr10 INTEGER DEFAULT 0, \
                                                  nr11 INTEGER DEFAULT 0, nr12 INTEGER DEFAULT 0, nr13 INTEGER DEFAULT 0, nr14 INTEGER DEFAULT 0, \
                                                  nr15 INTEGER DEFAULT 0, nr16 INTEGER DEFAULT 0, cod INTEGER DEFAULT 0)");
        if(checkQuery(nrCampB)) db.exec(nrCampB);

        QString nrCampC ("CREATE TABLE nrCampC (  biletID TEXT NOT NULL  UNIQUE , nr1 INTEGER DEFAULT 0, nr2 INTEGER DEFAULT 0, \
                                                  nr3 INTEGER DEFAULT 0, nr4 INTEGER DEFAULT 0, nr5 INTEGER DEFAULT 0, nr6 INTEGER DEFAULT 0, \
                                                  nr7 INTEGER DEFAULT 0, nr8 INTEGER DEFAULT 0, nr9 INTEGER DEFAULT 0, nr10 INTEGER DEFAULT 0, \
                                                  nr11 INTEGER DEFAULT 0, nr12 INTEGER DEFAULT 0, nr13 INTEGER DEFAULT 0, nr14 INTEGER DEFAULT 0, \
                                                  nr15 INTEGER DEFAULT 0, nr16 INTEGER DEFAULT 0, cod INTEGER DEFAULT 0)");
        if(checkQuery(nrCampC)) db.exec(nrCampC);

	return true;
}


bool VarDb::checkQuery( QSqlQuery q ) {
	if ( q.lastError().type() != QSqlError::NoError ) {  
                QMessageBox::critical( 0, QCoreApplication::applicationName(), "SQL: " + q.lastQuery() + "\nError: " + q.lastError().text() );
		return false;
	}

	return true;
}

void VarDb::AddBilet( BiletRecord bilet )
{
        QString numere ;
        QString vnr ;

        QSqlQuery addBilet;
        addBilet.prepare("INSERT INTO Bilet(biletID) VALUES(:biletID)");
        addBilet.bindValue(":biletID",bilet.biletID);
        if(checkQuery(addBilet)&& (bilet.nrA.count() || bilet.nrB.count() || bilet.nrC.count()))
            addBilet.exec();
        addBilet.clear();

        //introducem Campul A
        for(int i=0; i<bilet.nrA.count(); i++){
            numere.append(QString(",nr%1").arg(i+1));
        }
        for(int i=0; i<bilet.nrA.count(); i++){
            vnr.append(QString(",:nr%1").arg(i+1));
        }
        QSqlQuery addA;
        addA.prepare("INSERT INTO nrCampA(biletID, cod" + numere+")VALUES(:biletID, :cod"+ vnr+")");
        addA.bindValue(":biletID", bilet.biletID );
        addA.bindValue(":cod", bilet.codA);

        for(int i=0; i<bilet.nrA.count(); i++){
            addA.bindValue(QString(",:nr%1").arg(i+1), bilet.nrA.at(i));
        }
        if(checkQuery(addA) && bilet.nrA.count()) addA.exec();
        addA.clear();

        //introducem Campul B
        numere.clear();
        vnr.clear();
        for(int i=0; i<bilet.nrB.count(); i++){
            numere.append(QString(",nr%1").arg(i+1));
        }
        for(int i=0; i<bilet.nrB.count(); i++){
            vnr.append(QString(",:nr%1").arg(i+1));
        }
        QSqlQuery addB;
        addB.prepare("INSERT INTO nrCampB(biletID, cod" + numere+")VALUES(:biletID, :cod"+ vnr+")");
        addB.bindValue(":biletID", bilet.biletID );
        addB.bindValue(":cod", bilet.codB);
        for(int i=0; i<bilet.nrB.count(); i++){
            addB.bindValue(QString(",:nr%1").arg(i+1), bilet.nrB.at(i));
        }
        if(checkQuery(addB) && bilet.nrB.count()) addB.exec();
        addB.clear();

        //introducem Campul C
        numere.clear();
        vnr.clear();
        for(int i=0; i<bilet.nrC.count(); i++){
            numere.append(QString(",nr%1").arg(i+1));
        }
        for(int i=0; i<bilet.nrC.count(); i++){
            vnr.append(QString(",:nr%1").arg(i+1));
        }
        //cout<<vnr.toStdString()<<endl;
        QSqlQuery addC;
        addC.prepare("INSERT INTO nrCampC(biletID, cod" + numere+")VALUES(:biletID, :cod"+ vnr+")");
        addC.bindValue(":biletID", bilet.biletID );
        addC.bindValue(":cod", bilet.codC);
        for(int i=0; i<bilet.nrC.count(); i++){
            addC.bindValue(QString(",:nr%1").arg(i+1), bilet.nrC.at(i));
        }
        if(checkQuery(addC) && bilet.nrC.count()) addC.exec();
        addC.clear();

}

void VarDb::DelBilet(QString biletID)
{
    QString biletTable ("DELETE  FROM Bilet WHERE biletID = \""+biletID+"\"");
    if(checkQuery(biletTable)) db.exec(biletTable);

    QString campATable ("DELETE  FROM nrCampA WHERE biletID = \""+biletID+"\"");
    if(checkQuery(campATable)) db.exec(campATable);

    QString campBTable ("DELETE  FROM nrCampB WHERE biletID = \""+biletID+"\"");
    if(checkQuery(campBTable)) db.exec(campBTable);

    QString campCTable ("DELETE  FROM nrCampC WHERE biletID = \""+biletID+"\"");
    if(checkQuery(campCTable)) db.exec(campCTable);
}


BiletRecord VarDb::getBilet( const QString bilet )
{
        //QSqlQuery resultBilet("SELECT *  FROM Bilet WHERE biletID=\""+bilet+"\"")
        QSqlQuery resultA("SELECT *  FROM nrCampA LEFT JOIN Bilet WHERE  nrCampA.biletID=\""+bilet+"\" AND nrCampA.biletID = Bilet.biletID");
        QSqlQuery resultB("SELECT *  FROM nrCampB LEFT JOIN Bilet WHERE  nrCampB.biletID=\""+bilet+"\" AND nrCampB.biletID = Bilet.biletID");
        QSqlQuery resultC("SELECT *  FROM nrCampC LEFT JOIN Bilet WHERE  nrCampC.biletID=\""+bilet+"\" AND nrCampC.biletID = Bilet.biletID");

        BiletRecord nr;
        if ( checkQuery(resultA) && checkQuery(resultB) && checkQuery(resultC) ) {
            if(!resultA.next())resultA.clear();
            if(!resultB.next())resultB.clear();
            if(!resultC.next())resultC.clear();

            // pertu verificari
            /*
            cout<<"A:"<<resultA.record().value(1).toString().toStdString()<<" ";
            cout<<"B:"<<resultB.record().value(1).toString().toStdString()<<" ";
            cout<<"C:"<<resultC.record().value(1).toString().toStdString()<<"\n";
            */

             nr = recordToBiletRecord( resultA.record(), resultB.record(), resultC.record() );
	}
	return nr;
}


QVariant VarDb::valueOf( QSqlRecord rec, QString field )
{
	int i = rec.indexOf(field);
	return rec.value(i);
}


int VarDb::getCount( QString where )
{
	if (!where.isEmpty())
		where.prepend(" WHERE ");
	QSqlQuery result( "SELECT COUNT(*) FROM nodes" + where );
	if ( checkQuery(result) ) {
		result.next();
		int count = result.record().value(0).toInt();
		result.clear();
		return count;
	}
	result.clear();
	return -1;
}


void VarDb::rename(int id, QString newname)
{
	if (!newname.isEmpty()) {
		QSqlQuery q;
                q.prepare("UPDATE nodes SET biletID=:newname WHERE biletID=:itemid");
		q.bindValue(":newname",newname);
		q.bindValue(":itemid",id);
                if(checkQuery(q)) q.exec();
		q.clear();
	}
}


QVector<BiletRecord> VarDb::getAll()
{
        QVector<BiletRecord> list;
        QSqlQuery allBilet( "SELECT * FROM Bilet ORDER BY data, biletID" );

        if ( checkQuery(allBilet))
        while (allBilet.next()){
            list.append(getBilet(allBilet.record().value(0).toString()));
        }
        allBilet.clear();
	return list;
}

BiletRecord VarDb::recordToBiletRecord( QSqlRecord a, QSqlRecord b, QSqlRecord c )
{
        BiletRecord nr;
        if(!a.isEmpty()){
            nr.data = a.value(19).toString();
            nr.biletID = a.value(0).toString();
            nr.codA = a.value(17).toInt();
            for(int i=1; i<17; i++){
                if(a.value(i).toInt())
                    nr.nrA << a.value(i).toInt();
            }
            //qSort(nr.nrA.begin(), nr.nrA.end());
        }
        if(!b.isEmpty()){
            nr.data = b.value(19).toString();
            nr.biletID = b.value(0).toString();
            nr.codB = b.value(17).toInt();
            for(int i=1; i<17; i++){
                if(b.value(i).toInt())
                    nr.nrB << b.value(i).toInt();
            }
            //qSort(nr.nrB.begin(), nr.nrB.end());
        }
        if(!c.isEmpty()){
            nr.biletID = c.value(0).toString();
            nr.data = c.value(19).toString();
            nr.codC = c.value(17).toInt();
            for(int i=1; i<17; i++){
                if(c.value(i).toInt())
                    nr.nrC << c.value(i).toInt();
            }
            //qSort(nr.nrC.begin(), nr.nrC.end());
        }
    return nr;
}
