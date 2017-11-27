QT += core
QT -= gui

TARGET = cgGedcom
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
    cggedcom.h

DEFINES += CGGEDCOM_EXPORTS

