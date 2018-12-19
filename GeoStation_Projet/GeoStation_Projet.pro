#-------------------------------------------------
#
# Project created by QtCreator 2018-12-14T11:16:31
#
#-------------------------------------------------

QT       += core gui network webenginewidgets widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeoStation_Projet
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
    abstractapi.cpp \
    evenementapi.cpp \
    apiavions.cpp \
    sncfapi.cpp \
    pharmacieapi.cpp \
    pollutionapi.cpp \
    satelliteapi.cpp \
    borneelectriqueapi.cpp \
    ordonnanceur.cpp \
    vigicruesapi.cpp \
    meteoapi.cpp \
    awidget.cpp \
    nullapi.cpp \
    sncfwidget.cpp \
    cherchephotos.cpp \
    mmainwindow.cpp \
    mozaic.cpp \
    tableauwidget.cpp \
    geolocalisationapi.cpp \
    pokemap.cpp \
    evenementwidget.cpp


HEADERS += \
    abstractapi.h \    
    evenementapi.h \
    apiavions.h \
    sncfapi.h \
    pharmacieapi.h \
    pollutionapi.h \
    satelliteapi.h \
    borneelectriqueapi.h \
    ordonnanceur.h \
    vigicruesapi.h \
    meteoapi.h \
    awidget.h \
    nullapi.h \
    sncfwidget.h \
    cherchephotos.h \
    mmainwindow.h \
    mozaic.h \
    tableauwidget.h \
    geolocalisationapi.h \
    pokemap.h \
    evenementwidget.h


FORMS += \
        mainwindow.ui \
    sncfwidget.ui \
    tableauwidget.ui \
    evenementwidget.ui


RESOURCES += \
    resources.qrc
