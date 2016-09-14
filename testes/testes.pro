#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T13:07:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testes
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    item.cpp \
    functiondelta.cpp \
    functiongauss.cpp

HEADERS  += dialog.h \
    item.h \
    functiondelta.h \
    functiongauss.h

FORMS    += dialog.ui \
    item.ui \
    functiondelta.ui \
    functiongauss.ui
