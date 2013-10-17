#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T22:53:20
#
#-------------------------------------------------

QT       += core gui opengl svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Generation
TEMPLATE = app


SOURCES += main.cpp\
        map_graphic.cpp \
    map_logic.cpp \
    map.cpp

HEADERS  += map_graphic.h \
    map_logic.h \
    map.h

RESOURCES += \
    MapFragment.qrc
