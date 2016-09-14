#-------------------------------------------------
#
# Project created by QtCreator 2016-09-14T12:26:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mathExpr
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    tinyexpr.c \
    expparser.cpp

HEADERS  += dialog.h \
    tinyexpr.h \
    expparser.h

FORMS    += dialog.ui
