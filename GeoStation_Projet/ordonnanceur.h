# ifndef ORDONNANCEUR_H
# define ORDONNANCEUR_H

#include <QDebug>
#include "timer.h"
#include "abstractapi.h"

class ordonnanceur : public QObject
{
    Q_OBJECT

public:
    ordonnanceur(QObject* parent = 0);
    ordonnanceur(ordonnanceur const& other);

    void run();

    AbstractApi *api_index;
    Timer *sncf_timer;
    Timer *satellite_timer;
    Timer *evenement_timer;
    Timer *vigicrues_timer;
    Timer *meteo_timer;
    Timer *pollution_timer;
    Timer *pharmacie_timer;
    Timer *musee_timer;
    Timer *borneelectrique_timer;
    Timer *avions_timer;
    Timer *geolocalisation_timer;

signals:
    void send_info(QMap<QString, QString>);
    void send_info2(QMap<QString, QVariant>);
};

#endif // ORDONNANCEUR_H
