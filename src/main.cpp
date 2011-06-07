/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#include <QtGui/QApplication>
#include "mainloto.h"
#include "BiletLoto.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Popai Software");
    QCoreApplication::setOrganizationDomain("popai.source");
    QCoreApplication::setApplicationName("LottoTicket");
    //QApplication a(argc, argv);
    //MainLoto w;
    BiletMain w;
    w.show();

    return app.exec();
}
