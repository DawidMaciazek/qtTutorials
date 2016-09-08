#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T18:46:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_ui
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mywidget.cpp \
    mylogin.cpp

HEADERS  += widget.h \
    mywidget.h \
    mylogin.h

FORMS    += widget.ui \
    mywidget.ui \
    mylogin.ui
