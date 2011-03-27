#ifndef SAVEBILET_H
#define SAVEBILET_H

#include <QDialog>

namespace Ui {
    class SaveBilet;
}

class SaveBilet : public QDialog
{
    Q_OBJECT

public:
    explicit SaveBilet(QWidget *parent = 0);
    ~SaveBilet();

private:
    Ui::SaveBilet *ui;
};

#endif // SAVEBILET_H
