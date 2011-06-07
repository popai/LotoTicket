/****************************************************************************
 *   Copyright (C) 2005 by Popa Ionel                                       *
 *   popai@b.astral.ro                                                      *
 *
 ****************************************************************************/

#include "codlist.h"

CodList::CodList(QWidget *parent) :
    QWizardPage(parent)
{
    setupUi(this);
    textBrowser->setSource(tr("tabel-cod.html"));
}
