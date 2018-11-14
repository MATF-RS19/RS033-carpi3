QT       += core gui multimedia multimediawidgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=gnu++11

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter -Wunused-variable

TARGET = CarPI3

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INSTALLS += target
