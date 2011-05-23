#-------------------------------------------------
#
# Project created by QtCreator 2011-03-31T22:28:39
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

win32:LIBS += D:\Dev\QT\mingw\lib\libzziplib.a


TARGET = LotoTicket
TEMPLATE = app


SOURCES += main.cpp\
        mainloto.cpp \
    bilet.cpp \
    BiletLoto.cpp \
    settings.cpp \
    variante.cpp \
    vardb.cpp \
    savebilet.cpp \
    openbilet.cpp \
    delete.cpp

HEADERS  += mainloto.h \
    bilet.h \
    BiletLoto.h \
    settings.h \
    vardb.h \
    savebilet.h \
    openbilet.h \
    variante.h \
    delete.h

FORMS    += mainloto.ui \
    bilet.ui \
    settingwidget.ui \
    aboutwidget.ui \
    savebilet.ui \
    openbilet.ui \
    delete.ui

TRANSLATIONS += \
    LottoTicket_ro_RO.ts

RC_FILE = app.rc

RESOURCES += \
    ../build/images/resurce.qrc

