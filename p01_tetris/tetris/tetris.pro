#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T11:42:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dashboard.cpp

HEADERS  += mainwindow.h \
    dashboard.h

FORMS    += mainwindow.ui \
    dashboard.ui
