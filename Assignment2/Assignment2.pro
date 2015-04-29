#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T13:30:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Assignment2
TEMPLATE = app


SOURCES += main.cpp\
        gameboard.cpp \
    card.cpp \
    cardmove.cpp \
    freecell.cpp \
    game.cpp \
    help.cpp \
    klondike.cpp \
    pile.cpp \
    rule.cpp \
    winningdialog.cpp \
    aboutdialog.cpp

HEADERS  += gameboard.h \
    card.h \
    cardmove.h \
    freecell.h \
    game.h \
    help.h \
    klondike.h \
    pile.h \
    rule.h \
    winningdialog.h \
    aboutdialog.h

FORMS    += gameboard.ui \
    aboutdialog.ui \
    help.ui \
    winningdialog.ui

RESOURCES += \
    cardsbmps.qrc
