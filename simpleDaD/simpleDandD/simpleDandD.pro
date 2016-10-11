#-------------------------------------------------
#
# Project created by QtCreator 2016-10-08T19:54:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleDandD
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    dragitem.cpp

HEADERS  += dialog.h \
    dragitem.h

FORMS    += dialog.ui

RESOURCES += \
    resource.qrc
