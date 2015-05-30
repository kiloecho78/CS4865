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
    rulesdialog.cpp

HEADERS  += gamewindow.h \
    die.h \
    scorecard.h \
    player.h \
    rulesdialog.h

FORMS    += gamewindow.ui \
    rulesdialog.ui

RESOURCES += \
    sheetdie.qrc \
    icon.qrc

DISTFILES +=
