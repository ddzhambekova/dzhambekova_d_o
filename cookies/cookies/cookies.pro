#-------------------------------------------------
#
# Project created by QtCreator 2017-12-23T22:44:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cookies
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        firstwindow.cpp \
    aboutwindow.cpp \
    celldraw.cpp \
    chooselevelwindow.cpp \
    level.cpp \
    level2.cpp \
    rik.cpp \
    toolswindow.cpp \
    youlosewindow.cpp \
    youwinwindow.cpp

HEADERS += \
        firstwindow.h \
    aboutwindow.h \
    celldraw.h \
    chooselevelwindow.h \
    level.h \
    level2.h \
    rik.h \
    toolswindow.h \
    youlosewindow.h \
    youwinwindow.h

FORMS += \
        firstwindow.ui \
    aboutwindow.ui \
    chooselevelwindow.ui \
    level.ui \
    level2.ui \
    toolswindow.ui \
    youlosewindow.ui \
    youwinwindow.ui

RESOURCES += \
    recources.qrc

SUBDIRS += \
    cookies.pro \
    cookies1.pro

DISTFILES +=
