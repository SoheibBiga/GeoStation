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

class ordonnanceur : public QObject
{
    Q_OBJECT

public:
    ordonnanceur(QObject* parent = 0);

private:

};

#endif // ORDONNANCEUR_H
