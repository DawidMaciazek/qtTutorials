#-------------------------------------------------
#
# Project created by QtCreator 2016-10-06T20:20:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = drag_and_drop_test
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    dragger.cpp \
    qcustomplot.cpp

HEADERS  += dialog.h \
    dragger.h \
    qcustomplot.h

FORMS    += dialog.ui \
    dragger.ui
