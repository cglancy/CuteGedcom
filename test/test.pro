QT += core testlib
QT -= gui

TARGET = cgGedcomTest
CONFIG += testcase 

TEMPLATE = app

SOURCES += gedcomtest.cpp

HEADERS += gedcomtest.h

INCLUDEPATH += ../src

CONFIG(debug, debug|release) {
    LIBS += -L../src/debug -lcgGedcom0
    PRE_TARGETDEPS += ../src/debug/cgGedcom0.dll
}
else {
    LIBS += -L../src/release -lcgGedcom0
    PRE_TARGETDEPS += ../src/release/cgGedcom0.dll
}
