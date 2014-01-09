#-------------------------------------------------
#
# Project created by QtCreator 2013-11-22T10:05:17
#
#-------------------------------------------------

QT       += core gui svg opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = City
TEMPLATE = app


SOURCES += main.cpp\
    citymap.cpp \
    citydialog.cpp \
    city.cpp \
    cityleftpannel.cpp \
    cityrightpannel.cpp \
    cityinformelement.cpp \
    warehousedialog.cpp \
    data.cpp

HEADERS  += \
    citymap.h \
    citydialog.h \
    city.h \
    cityleftpannel.h \
    cityrightpannel.h \
    cityinformelement.h \
    warehousedialog.h \
    data.h

RESOURCES += \
    Forms.qrc

OTHER_FILES +=
