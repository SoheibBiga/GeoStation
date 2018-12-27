#-------------------------------------------------
#
# Project created by QtCreator 2018-12-14T11:16:31
#
#-------------------------------------------------

QT       += core gui network widgets

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
    avionsapi.cpp \
    avionswidget.cpp \
    avionsmozaicwidget.cpp \
    sncfapi.cpp \
    pharmacieapi.cpp \
    pollutionapi.cpp \
    satelliteapi.cpp \
    borneelectriqueapi.cpp \
    borneelectriquewidget.cpp \
    ordonnanceur.cpp \
    vigicruesapi.cpp \
    meteoapi.cpp \
    awidget.cpp \
    cherchephotos.cpp \
    mozaic.cpp \
    tableauwidget.cpp \
    pharmaciewidget.cpp\
    geolocalisationapi.cpp \
    pokemap.cpp \
    sncfwidget.cpp \
    sncfmozaicwidget.cpp \
    mainwindow.cpp \
    museesapi.cpp \
    museesmozaicwidget.cpp \
    museesmainwidget.cpp \
    museeswidget.cpp \
    evenementmozaicwidget.cpp \
    evenementwidget.cpp \
    evenementmainwidget.cpp \
    satellitewidget.cpp \
    linechartwidget.cpp \
    vigicruesmosaicwidget.cpp \
    vigicrueswidget.cpp \
    pharmaciemozaicwidget.cpp\
    labeldyn.cpp \
    geolocalisationwidget.cpp \
    geolocmozaicwidget.cpp \
    borneelectriquemozaicwidget.cpp \
    pollutionwidget.cpp \
    pollutionmozaicwidget.cpp \
    timer.cpp \
    satellitemozaicwidget.cpp \
    satellitemainwidget.cpp \
    sncfmainwidget.cpp \
    customlabels.cpp \
    meteowidget.cpp \
    meteomozaicwidget.cpp \
    meteomainwidget.cpp \
    widgetstylesheet.cpp






HEADERS += \
    abstractapi.h \
    avionsapi.h \
    avionsmozaicwidget.h \
    avionswidget.h \
    evenementapi.h \
    sncfapi.h \
    pharmacieapi.h \
    pollutionapi.h \
    satelliteapi.h \
    borneelectriqueapi.h \
    borneelectriquewidget.h \
    ordonnanceur.h \
    vigicruesapi.h \
    meteoapi.h \
    awidget.h \
    cherchephotos.h \
    mozaic.h \
    tableauwidget.h \
    pharmaciewidget.h\
    geolocalisationapi.h \
    pokemap.h \
    sncfwidget.h \
    sncfmozaicwidget.h \
    mainwindow.h \
    museesapi.h \
    museesmozaicwidget.h \
    museesmainwidget.h \
    museeswidget.h \
    evenementmozaicwidget.h \
    evenementwidget.h \
    evenementmainwidget.h \
    satellitewidget.h \
    linechartwidget.h \
    vigicruesmosaicwidget.h \
    vigicrueswidget.h \
    pharmaciemozaicwidget.h\
    labeldyn.h \
    geolocalisationwidget.h \
    geolocmozaicwidget.h \
    borneelectriquemozaicwidget.h \
    pollutionwidget.h \
    pollutionmozaicwidget.h \
    timer.h \
    satellitemozaicwidget.h \
    satellitemainwidget.h \
    sncfmainwidget.h \
    customlabels.h \
    meteowidget.h \
    meteomozaicwidget.h \
    meteomainwidget.h \
    widgetstylesheet.h




FORMS += \
    mainwindow.ui \
    tableauwidget.ui \
    avionsmozaicwidget.ui \
    sncfmozaicwidget.ui \
    museesmozaicwidget.ui \
    museesmainwidget.ui \
    evenementmozaicwidget.ui \
    evenementmainwidget.ui \
    linechartwidget.ui \
    vigicruesmosaicwidget.ui \
    pharmaciemozaicwidget.ui\
    geolocmozaicwidget.ui \
    borneelectriquemozaicwidget.ui \
    pollutionmozaicwidget.ui \
    satellitemozaicwidget.ui \
    satellitemainwidget.ui \
    sncfmainwidget.ui \
    meteomozaicwidget.ui \
    meteomainwidget.ui




RESOURCES += \
    resources.qrc

target.path = /home/root
INSTALLS += target
