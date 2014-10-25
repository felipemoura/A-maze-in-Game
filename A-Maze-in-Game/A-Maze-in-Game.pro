#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T18:25:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A-Maze-in-Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    position.cpp \
    player.cpp \
    mazegeneration.cpp \
    onmap.cpp

HEADERS  += mainwindow.h \
    position.h \
    player.h \
    mazegeneration.h \
    onmap.h

FORMS    += mainwindow.ui
