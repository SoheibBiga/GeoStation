#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include "abstractapi.h"
#include "pollutionapi.h"
#include "pharmacieapi.h"
#include "evenementapi.h"
#include "sncfapi.h"
#include "museesapi.h"
#include "evenementapi.h"
#include "borneelectriqueapi.h"
#include "satelliteapi.h"
#include "nullapi.h"
#include "vigicruesapi.h"
#include "meteoapi.h"
#include "avionsapi.h"
#include "geolocalisationapi.h"
#include <QDebug>


class ordonnanceur : public QObject
{
    Q_OBJECT

public:
    ordonnanceur(QObject* parent = 0);
    AbstractApi *api_index;
    void run();
    QTimer *sncf_timer;
    QTimer *satellite_timer;
    QTimer *evenement_timer;
    QTimer *vigicrues_timer;
    QTimer *meteo_timer;
    QTimer *pollution_timer;
    QTimer *pharmacie_timer;
    QTimer *musee_timer;
    QTimer *borneelectrique_timer;
    QTimer *avions_timer;
    //QTimer geolocalisation_timer;

signals:
    void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString, QVariant>);

private slots:
    void send_request();
};

#endif // ORDONNANCEUR_H
