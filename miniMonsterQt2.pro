#-------------------------------------------------
#
# Project created by QtCreator 2013-04-21T17:41:02
#
#-------------------------------------------------

include(G:\\work_temp\\MM\\MiMo_soft\\source\\qtsingleapp\\src\\qtsingleapplication.pri)

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TRANSLATIONS += miMo2_ru.ts

TARGET = miniMonsterQt2
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qminimonsterworker.cpp \
    qminimonsterscheduler.cpp \
    qminimonsterschedulertask.cpp \
    simplemainwindow.cpp

INCLUDEPATH += G:\\work_temp\\MM\\MiMo_soft\\source\\libqxt\\include\\QxtCore

LIBS += -LG:\\work_temp\\MM\\MiMo_soft\\source\\libqxt\\lib -lQxtCore

HEADERS  += mainwindow.h \
    qminimonsterworker.h \
    qminimonsterscheduler.h \
    qminimonsterschedulertask.h \
    simplemainwindow.h

FORMS    += mainwindow.ui \
    simplemainwindow.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    libqxt/libqxt.pro \
    ../notes.txt
