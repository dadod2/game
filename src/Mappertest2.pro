#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T21:36:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mappertest2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    window1.cpp \
    menu.cpp \
    cont1.cpp \
    cont2.cpp \
    cont3.cpp \
    map.cpp \
    mapdiag.cpp \
    mapcontainer.cpp \
    chunk.cpp \
    chunklabel.cpp \
    contdelete.cpp \
    movebutton.cpp \
    chunkcontent.cpp \
    contaddbuild.cpp \
    building.cpp \
    building_props.cpp \
    tableclass.cpp \
    settlement.cpp \
    management.cpp

HEADERS  += mainwindow.h \
    window1.h \
    menu.h \
    cont1.h \
    cont2.h \
    cont3.h \
    map.h \
    mapdiag.h \
    mapcontainer.h \
    chunk.h \
    chunklabel.h \
    contdelete.h \
    movebutton.h \
    chunkcontent.h \
    contaddbuild.h \
    building.h \
    building_props.h \
    tableclass.h \
    settlement.h \
    management.h

FORMS    += mainwindow.ui \
    mapdiag.ui

OTHER_FILES += \
    doc_add.txt
