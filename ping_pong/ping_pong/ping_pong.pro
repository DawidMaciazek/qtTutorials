#-------------------------------------------------
#
# Project created by QtCreator 2016-09-11T11:26:34
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ping_pong
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    ppball.cpp \
    ppboundary.cpp \
    pppaddle.cpp

HEADERS  += dialog.h \
    ppball.h \
    ppboundary.h \
    pppaddle.h

FORMS    += dialog.ui
