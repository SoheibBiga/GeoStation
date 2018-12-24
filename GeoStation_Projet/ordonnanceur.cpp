
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
<<<<<<< HEAD
<<<<<<< HEAD
    connect(satellite_timer, SIGNAL(timeout()), satellite_timer, SLOT(send_request()));
    connect(evenement_timer, SIGNAL(timeout()), evenement_timer, SLOT(send_request()));
    connect(pharmacie_timer, SIGNAL(timeout()), this, SLOT(send_request()));
    connect(geolocalisation_timer, SIGNAL(timeout()), geolocalisation_timer, SLOT(send_request()));
    connect(evenement_timer, SIGNAL(timeout()), this, SLOT(send_request(2)));
    connect(vigicrues_timer, SIGNAL(timeout()), this, SLOT(send_request(3)));
    connect(avions_timer, SIGNAL(timeout()), this, SLOT(send_request(4)));
    connect(meteo_timer, SIGNAL(timeout()), this, SLOT(send_request(5)));
    connect(pollution_timer, SIGNAL(timeout()), this, SLOT(send_request(6)));
    connect(musee_timer, SIGNAL(timeout()), this, SLOT(send_request(7)));
    connect(borneelectrique_timer, SIGNAL(timeout()), this, SLOT(send_request(9)));
=======
   connect(satellite_timer, SIGNAL(timeout()), satellite_timer, SLOT(send_request()));
=======
    connect(satellite_timer, SIGNAL(timeout()), satellite_timer, SLOT(send_request()));
>>>>>>> aee1ae8f348dce8a307781c44b3e0accd8461c54
    connect(evenement_timer, SIGNAL(timeout()), evenement_timer, SLOT(send_request()));
    connect(geolocalisation_timer, SIGNAL(timeout()), geolocalisation_timer, SLOT(send_request()));
<<<<<<< HEAD
    //connect(evenement_timer, SIGNAL(timeout()), this, SLOT(send_request(2)));
    //connect(vigicrues_timer, SIGNAL(timeout()), this, SLOT(send_request(3)));
    //connect(avions_timer, SIGNAL(timeout()), this, SLOT(send_request(4)));
    //connect(meteo_timer, SIGNAL(timeout()), this, SLOT(send_request(5)));
    //connect(pollution_timer, SIGNAL(timeout()), this, SLOT(send_request(6)));
    //connect(musee_timer, SIGNAL(timeout()), this, SLOT(send_request(7)));
    //connect(borneelectrique_timer, SIGNAL(timeout()), this, SLOT(send_request(9)));
>>>>>>> b0aa0b4e5fdb139a37e57e2d596c0bef7f736ba0

    //connect(pharmacie_timer, SIGNAL(timeout()), pharmacie_timer, SLOT(send_request()));
    //connect(geolocalisation_timer, SIGNAL(timeout()), geolocalisation_timer, SLOT(send_request()));
=======
    connect(pharmacie_timer, SIGNAL(timeout()), pharmacie_timer, SLOT(send_request()));
    connect(geolocalisation_timer, SIGNAL(timeout()), geolocalisation_timer, SLOT(send_request()));
>>>>>>> aee1ae8f348dce8a307781c44b3e0accd8461c54
    connect(evenement_timer, SIGNAL(timeout()), evenement_timer, SLOT(send_request()));
    connect(vigicrues_timer, SIGNAL(timeout()), vigicrues_timer, SLOT(send_request()));
    connect(avions_timer, SIGNAL(timeout()), avions_timer, SLOT(send_request()));
    connect(meteo_timer, SIGNAL(timeout()), meteo_timer, SLOT(send_request()));
    connect(pollution_timer, SIGNAL(timeout()), pollution_timer, SLOT(send_request()));
    connect(musee_timer, SIGNAL(timeout()), musee_timer, SLOT(send_request()));
    connect(borneelectrique_timer, SIGNAL(timeout()), borneelectrique_timer, SLOT(send_request()));


    sncf_timer->start(1);
    evenement_timer->start(1);
    satellite_timer->start(1);
<<<<<<< HEAD
    pharmacie_timer->start(1);
    geolocalisation_timer->start(1);
    evenement_timer->start(1);
    vigicrues_timer->start(1);
    avions_timer->start(1);
    meteo_timer->start(1);
    pollution_timer->start(1);
    musee_timer->start(1);
=======
    //pharmacie_timer->start(1);
    geolocalisation_timer->start(1);
    //evenement_timer->start(1);
    //vigicrues_timer->start(1);
    //avions_timer->start(1);
    //meteo_timer->start(1);
    //pollution_timer->start(1);
    //musee_timer->start(1);
>>>>>>> b0aa0b4e5fdb139a37e57e2d596c0bef7f736ba0
    borneelectrique_timer->start(1);
}
