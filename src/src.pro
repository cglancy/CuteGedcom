QT       += core
QT       -= gui

TARGET = CuteGedcom
CONFIG   += dll
TEMPLATE = lib
VERSION	= 0.1.1

SOURCES += anselcodec.cpp \
    gedcomnode.cpp \
    gedcomparser.cpp

HEADERS += \
    anselcodec.h \
    gedcomnode.h \
    gedcomparser.h \
    cutegedcom.h

DEFINES += CUTEGEDCOM_EXPORTS

