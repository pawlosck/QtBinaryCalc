#-------------------------------------------------
#
# Project created by QtCreator 2013-07-13T10:56:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBinaryCalc
TEMPLATE = app


SOURCES += main.cpp\
    asciispinbox.cpp \
    pushbuttonbit.cpp \
    spinboxhex.cpp \
    byte.cpp \
    numbers.cpp \
    asciibutton.cpp \
    asciiwidget.cpp \
    qtbinarycalc.cpp \
    chooser.cpp \
    chooserbutton.cpp

HEADERS  += \
    qtbinarycalc.h \
    pushbuttonbit.h \
    byte.h \
    numbers.h \
    spinboxhex.h \
    asciispinbox.h \
    asciiwidget.h \
    asciibutton.h \
    chooser.h \
    chooserbutton.h \
    debug.h

FORMS    += \
    asciiwidget.ui \
    byte.ui \
    numbers.ui \
    qtbinarycalc.ui \
    chooser.ui





CONFIG += console \

#QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS += -std=c++11
