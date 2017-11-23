QT       += core testlib
QT       -= gui

TARGET = TestCuteGedcom
CONFIG   += testcase 

TEMPLATE = app

SOURCES += testcutegedcom.cpp

HEADERS += testcutegedcom.h

INCLUDEPATH += ../src

CONFIG(debug, debug|release) {
    LIBS += -L./debug -lCuteGedcom0
    PRE_TARGETDEPS += ./debug/CuteGedcom0.dll
}
else {
    LIBS += -L./release -lCuteGedcom0
    PRE_TARGETDEPS += ./release/CuteGedcom0.dll
}
