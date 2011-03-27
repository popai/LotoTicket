#ifndef SETDATA_H
#define SETDATA_H

#include <QDialog>

namespace Ui {
    class SetData;
}

class SetData : public QDialog
{
    Q_OBJECT

public:
    explicit SetData(QWidget *parent = 0);
    ~SetData();

private:
    Ui::SetData *ui;
};

#endif // SETDATA_H
