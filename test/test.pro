QT       += core testlib
QT       -= gui

TARGET = TestCuteGedcom
CONFIG   += testcase 

TEMPLATE = app

SOURCES += testcutegedcom.cpp

HEADERS += testcutegedcom.h

INCLUDEPATH += ../src

CONFIG(debug, debug|release) {
    LIBS += -L../src/debug -lCuteGedcom0
    PRE_TARGETDEPS += ../src/debug/CuteGedcom0.dll
}
else {
    LIBS += -L../src/release -lCuteGedcom0
    PRE_TARGETDEPS += ../src/release/CuteGedcom0.dll
}
