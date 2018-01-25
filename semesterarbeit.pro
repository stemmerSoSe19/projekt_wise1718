TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parserlib.cpp \
    listlib.cpp

HEADERS += \
    clparser.h \
    cllist.h
