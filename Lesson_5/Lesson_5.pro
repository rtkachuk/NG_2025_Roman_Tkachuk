TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        exampleparent.cpp \
        main.cpp \
        publicchild.cpp

HEADERS += \
    exampleparent.h \
    publicchild.h
