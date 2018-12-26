
#include "ordonnanceur.h"

ordonnanceur::ordonnanceur(QObject *parent) :
    QObject(parent),
    api_index(Q_NULLPTR)
{
    sncf_timer = new Timer(IdWidget(Sncf),this);
    satellite_timer = new Timer(IdWidget(Satellite),this);
    evenement_timer = new Timer(IdWidget(Evenement),this);
    vigicrues_timer = new Timer(IdWidget(Vigicrues),this);
    avions_timer = new Timer(IdWidget(Avions),this);
    meteo_timer = new Timer(IdWidget(Meteo),this);
    pollution_timer = new Timer(IdWidget(Pollution),this);
    musee_timer = new Timer(IdWidget(Musee),this);
    pharmacie_timer = new Timer(IdWidget(Pharmacie),this);
    borneelectrique_timer = new Timer(IdWidget(BorneElectrique),this);
    geolocalisation_timer = new Timer(IdWidget(Geolocalisation),this);
}


void ordonnanceur::run()
{
    connect(sncf_timer, SIGNAL(timeout()), sncf_timer, SLOT(send_request()));
    connect(satellite_timer, SIGNAL(timeout()), satellite_timer, SLOT(send_request()));
    connect(evenement_timer, SIGNAL(timeout()), evenement_timer, SLOT(send_request()));
    connect(geolocalisation_timer, SIGNAL(timeout()), geolocalisation_timer, SLOT(send_request()));
    connect(pharmacie_timer, SIGNAL(timeout()), pharmacie_timer, SLOT(send_request()));
    connect(geolocalisation_timer, SIGNAL(timeout()), geolocalisation_timer, SLOT(send_request()));
    connect(evenement_timer, SIGNAL(timeout()), evenement_timer, SLOT(send_request()));
    connect(vigicrues_timer, SIGNAL(timeout()), vigicrues_timer, SLOT(send_request()));
    connect(avions_timer, SIGNAL(timeout()), avions_timer, SLOT(send_request()));
    connect(meteo_timer, SIGNAL(timeout()), meteo_timer, SLOT(send_request()));
    connect(pollution_timer, SIGNAL(timeout()), pollution_timer, SLOT(send_request()));
    connect(musee_timer, SIGNAL(timeout()), musee_timer, SLOT(send_request()));
    connect(borneelectrique_timer, SIGNAL(timeout()), borneelectrique_timer, SLOT(send_request()));


    sncf_timer->start(1);
    evenement_timer->start(2);
    pharmacie_timer->start(3);
    geolocalisation_timer->start(1);
    evenement_timer->start(1);
    vigicrues_timer->start(1);
    avions_timer->start(1);
    meteo_timer->start(4);
    pollution_timer->start(5);
    musee_timer->start(1);
    borneelectrique_timer->start(6);
    satellite_timer->start(7);

}
