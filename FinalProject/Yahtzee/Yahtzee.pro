#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T19:10:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Yahtzee
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    die.cpp \
    scorecard.cpp \
    player.cpp \
    scorecardlayout.cpp

HEADERS  += gamewindow.h \
    die.h \
    scorecard.h \
    player.h \
    scorecardlayout.h

FORMS    += gamewindow.ui

RESOURCES += \
    sheetdie.qrc \
    icon.qrc

DISTFILES +=
