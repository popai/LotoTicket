//
// C++ Interface: vardb
//
// Description:
//
//
// Author: Massimiliano Torromeo <massimiliano.torromeo AT gmail DOT com>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef VARDB_H
#define VARDB_H

//#include <QtGui/QMessageBox>
#include <QVector>
#include <QString>
#include <QSqlDatabase>
#include <QDate>
#include <QMessageBox>

//class ProgressDialog;
//class QMessageBox;
class QStringList;
class QSqlQuery;
class QSqlRecord;
class QVariant;



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

/**
This class is meant to manage the db and provides various functions to ease the interactions with the collection

@author Ryo Saeba
*/
class VarDb{
private:
	QString aname;
	bool checkQuery(QSqlQuery q);

public:
        VarDb();
        ~VarDb();

	QSqlDatabase db;

	QString name() { return aname; }
        bool newDB( QString name );


	QVariant valueOf(QSqlRecord rec, QString field);
        BiletRecord recordToBiletRecord( QSqlRecord a, QSqlRecord b, QSqlRecord c );

        QVector<BiletRecord> getAll();
        BiletRecord getBilet(const QString node);
        void AddBilet( BiletRecord bilet );
        void DelBilet(QString biletID);
        //QVector<BiletRecord> getNodes(const int parent, QString where = "");


	int getCount(QString where = "");
	int getCountRecursive(int);
	void rename(int,QString);
        //void deleteNodes( const QVector<BiletRecord> list, ProgressDialog *prog );
};

#endif
