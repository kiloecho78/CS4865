#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T15:24:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Yahtzee
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    die.cpp

HEADERS  += gamewindow.h \
    die.h

FORMS    += gamewindow.ui
