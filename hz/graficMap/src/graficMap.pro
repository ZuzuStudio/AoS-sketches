HEADERS       = \
    widget.h
RESOURCES     =
SOURCES       = main.cpp \
    widget.cpp
QT           += widgets svg xml

qtHaveModule(opengl): QT += opengl

CONFIG += console

# install
# target.path = $$[QT_INSTALL_EXAMPLES]/svg/svgviewer
# INSTALLS += target

wince*: {
     addFiles.files = files\\*.svg
     addFiles.path = "\\My Documents"
     DEPLOYMENT += addFiles
}
