#-------------------------------------------------
#
# Project created by QtCreator 2016-09-11T11:26:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ping_pong
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    ppball.cpp \
    ppboundary.cpp

HEADERS  += dialog.h \
    ppball.h \
    ppboundary.h

FORMS    += dialog.ui
