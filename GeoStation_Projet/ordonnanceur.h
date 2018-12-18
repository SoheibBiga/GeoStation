#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include "abstractapi.h"
#include "pollutionapi.h"
#include "pharmacieapi.h"
#include "evenementapi.h"
#include "sncfapi.h"
#include "evenementapi.h"
#include "borneelectriqueapi.h"
#include "satelliteapi.h"
#include "nullapi.h"
#include "vigicruesapi.h"
#include "meteoapi.h"


class ordonnanceur : public QObject
{
    Q_OBJECT

public:
    ordonnanceur(QObject* parent = 0);
    //AbstractApi *api_index;
    AbstractApi *api_index;
    void run();
signals:
    void send_info(QMap<QString,QString>);

};

#endif // ORDONNANCEUR_H
