HEADERS       = \
    mapwidget.h \
    graficmap.h \
    graficitem.h \
    levelofdetalisation.h
RESOURCES     =
SOURCES       = \
    main.cpp \
    mapwidget.cpp \
    graficmap.cpp \
    graficitem.cpp \
    levelofdetalisation.cpp
QT           += widgets svg xml

qtHaveModule(opengl): QT += opengl

CONFIG += console c++11

# install
# target.path = $$[QT_INSTALL_EXAMPLES]/svg/svgviewer
# INSTALLS += target

wince*: {
     addFiles.files = files\\*.svg
     addFiles.path = "\\My Documents"
     DEPLOYMENT += addFiles
}
