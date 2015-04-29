#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T01:00:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGame
TEMPLATE = app


SOURCES += main.cpp\
        gameboard.cpp \
    card.cpp \
    cardmove.cpp \
    freecell.cpp \
    game.cpp \
    klondike.cpp \
    pile.cpp \
    rule.cpp \
    winningdialog.cpp \
    aboutdialog.cpp \
    help.cpp \
    matchgame.cpp

HEADERS  += gameboard.h \
    card.h \
    cardmove.h \
    freecell.h \
    game.h \
    klondike.h \
    pile.h \
    rule.h \
    winningdialog.h \
    aboutdialog.h \
    help.h \
    matchgame.h

FORMS    += gameboard.ui \
    aboutdialog.ui \
    help.ui \
    winningdialog.ui

RESOURCES += \
    cards.qrc

QMAKE_CFLAGS_RELEASE +=
QMAKE_CXXFLAGS_RELEASE +=
QMAKE_CXXFLAGS += -fpermissive

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

DISTFILES += \
    help_text.txt

