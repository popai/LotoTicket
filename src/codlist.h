/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#ifndef CODLIST_H
#define CODLIST_H

#include "ui_codlist.h"

class CodList : public QWizardPage, private Ui::CodeList
{
    Q_OBJECT

public:
    explicit CodList(QWidget *parent = 0);
};

#endif // CODLIST_H
