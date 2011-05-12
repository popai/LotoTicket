#ifndef SAVEBILET_H
#define SAVEBILET_H

#include <QDialog>
#include "ui_savebilet.h"

class SaveBilet : public QDialog, private Ui::USaveBilet
{
    Q_OBJECT

public:
    explicit SaveBilet(QWidget *parent = 0);
    ~SaveBilet();

    void SetList(QListWidgetItem *numeB);

    QString nameB;

public slots:
    //void NameB();
    virtual void accept();


//private:
};

#endif // SAVEBILET_H
