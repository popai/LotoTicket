#include <QtGui/QApplication>
#include "mainloto.h"
#include "BiletLoto.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainLoto w;
    BiletMain w;
    w.show();

    return a.exec();
}
