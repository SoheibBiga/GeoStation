
#include "ordonnanceur.h"

ordonnanceur::ordonnanceur(QObject *parent) : QObject(parent)
{
    api_index = new nullapi(this);
    sncf_timer = new QTimer();
    satellite_timer = new QTimer();
    evenement_timer = new QTimer();
    vigicrues_timer = new QTimer();
    meteo_timer = new QTimer();
    pollution_timer = new QTimer();
    pharmacie_timer = new QTimer();
    musee_timer = new QTimer();
    borneelectrique_timer = new QTimer();
    avions_timer = new QTimer();
}

void ordonnanceur::send_request()
{
    int id =0;
    switch(id){
    case IdWidget(Sncf):
        api_index = new SncfApi(this);
        sncf_timer->start(10000);
        break;
    case IdWidget(Musee):
        api_index = new MuseesApi(this);
        break;
    case IdWidget(Satellite):
        api_index = new SatelliteApi(this);
        break;
    case IdWidget(Evenement):
        api_index = new EvenementApi(this);
        break;
    case IdWidget(Pollution):
        api_index = new PollutionApi(this);
        break;
    case IdWidget(BorneElectrique):
        api_index = new BorneElectriqueApi(this);
        break;
    case IdWidget(Pharmacie):
        api_index = new PharmacieApi(this);
        break;
    case IdWidget(Meteo):
        api_index = new MeteoApi(this);
        break;
    case IdWidget(Vigicrues):
        api_index = new VigicruesApi(this);
        break;
    case IdWidget(Geolocalisation):
        api_index = new GeolocalisationApi(this);
        break;
    case IdWidget(Avions):
        api_index = new avionsapi(this);
        break;
    }
    api_index->loop->exec();
}

void ordonnanceur::run(){
    connect(sncf_timer, SIGNAL(timeout()), this, SLOT(send_request()));
    connect(satellite_timer, SIGNAL(timeout()), this, SLOT(send_request()));
//    connect(evenement_timer, SIGNAL(timeout()), this, SLOT(send_request(2)));
//    connect(vigicrues_timer, SIGNAL(timeout()), this, SLOT(send_request(3)));
//    connect(avions_timer, SIGNAL(timeout()), this, SLOT(send_request(4)));
//    connect(meteo_timer, SIGNAL(timeout()), this, SLOT(send_request(5)));
//    connect(pollution_timer, SIGNAL(timeout()), this, SLOT(send_request(6)));
//    connect(musee_timer, SIGNAL(timeout()), this, SLOT(send_request(7)));
//    connect(pharmacie_timer, SIGNAL(timeout()), this, SLOT(send_request(8)));
//    connect(borneelectrique_timer, SIGNAL(timeout()), this, SLOT(send_request(9)));

    sncf_timer->start(1);
    satellite_timer->start(1000);
//    evenement_timer->start(1000000);
//    vigicrues_timer->start(1000000);
//    avions_timer->start(1000000);
//    meteo_timer->start(1000000);
//    pollution_timer->start(1000000);
//    musee_timer->start(100000);
//    pharmacie_timer->start(1000000);
//    borneelectrique_timer->start(1000000);
}
