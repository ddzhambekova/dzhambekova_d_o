#-------------------------------------------------
#
# Project created by QtCreator 2017-12-02T12:03:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cookies1
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
    toolswindow.cpp \
    aboutwindow.cpp \
    chooselevelwindow.cpp \
    level1.cpp \
    cookie.cpp \
    rikki.cpp \
    blackcell.cpp \
    youlosewindow.cpp \
    q.cpp

HEADERS += \
    firstwindow.h \
    toolswindow.h \
    aboutwindow.h \
    chooselevelwindow.h \
    level1.h \
    cookie.h \
    rikki.h \
    blackcell.h \
    youlosewindow.h \
    q.h

FORMS += \
    firstwindow.ui \
    toolswindow.ui \
    aboutwindow.ui \
    chooselevelwindow.ui \
    level1.ui \
    youlosewindow.ui \
    q.ui

RESOURCES += \
    ../../images/resource.qrc
