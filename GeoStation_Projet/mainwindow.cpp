#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pharmacieapi.h"
#include "sncfapi.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SncfApi *apisncf;
    /*ApiSatellite *api_satellite;
    ApiBorneElectrique *api_borne_electrique;
    ApiMusee *api_musee;
    ApiAvion *api_avion;
    ApiGeolocalisation *api_geolocalisation;*/
    ApiPharmacie *api_pharmacie;
    api_pharmacie = new ApiPharmacie(this,api_pharmacie->Id);
    /*ApiMeteo *api_meteo;
    ApiPollution *api_pollution;
    ApiEvenement *api_evenement;
    Api_Vegicrue *api_vegicrue;*/
    QList<QObject*> liste_api;
    liste_api.append(apisncf);
    /*liste_api.append(api_satellite);
    liste_api.append(api_borne_electrique);
    liste_api.append(api_musee);
    liste_api.append(api_avion);
    liste_api.append(api_geolocalisation);
    liste_api.append(api_pharmacie);
    liste_api.append(api_meteo);
    liste_api.append(api_pollution);
    liste_api.append(api_evenement);
    liste_api.append(api_vegicrue);*/

    //apisncf = new ApiSncf()
}

MainWindow::~MainWindow()
{
    delete ui;
}
