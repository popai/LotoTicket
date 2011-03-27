#-------------------------------------------------
#
# Project created by QtCreator 2011-03-31T22:28:39
#
#-------------------------------------------------

QT       += core gui
QT       +=sql


TARGET = LotoTicket
TEMPLATE = app


SOURCES += main.cpp\
        mainloto.cpp \
    bilet.cpp \
    BiletLoto.cpp \
    settings.cpp \
    variante.cpp \
    vardb.cpp \
    setdata.cpp \
    savebilet.cpp \
    openbilet.cpp

HEADERS  += mainloto.h \
    bilet.h \
    BiletLoto.h \
    settings.h \
    vardb.h \
    setdata.h \
    savebilet.h \
    openbilet.h \
    variante.h

FORMS    += mainloto.ui \
    bilet.ui \
    settingwidget.ui \
    aboutwidget.ui \
    setdata.ui \
    savebilet.ui \
    openbilet.ui
