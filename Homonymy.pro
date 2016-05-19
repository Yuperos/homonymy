#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T23:27:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homonymy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapparser.cpp

HEADERS  += mainwindow.h \
    mapparser.h

FORMS    += mainwindow.ui

RESOURCES += \
    maps.qrc
