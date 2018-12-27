#include "abstractapi.h"
#include "ordonnanceur.h"


AbstractApi::AbstractApi()
    : QObject(),
      ord(Q_NULLPTR),
      loop(Q_NULLPTR),
      manager(Q_NULLPTR)
{}

AbstractApi::AbstractApi(AbstractApi const& other)
    : QObject(),
      ord(other.ord),
      loop(other.loop),
      longitude(other.longitude),
      latitude(other.latitude),
      radius(other.radius),
      manager(other.manager)
{}

AbstractApi& AbstractApi::operator=(AbstractApi const& other)
{
    ord = other.ord;
    loop = other.loop;
    longitude = other.longitude;
    latitude = other.latitude;
    radius = other.radius;
    manager = other.manager;
    return (*this);
}

AbstractApi::AbstractApi(ordonnanceur *ord_, QObject *parent, QString longitude_, QString latitude_, QString radius_)
    : QObject(parent),
      ord(ord_),
      loop(Q_NULLPTR),
      manager(Q_NULLPTR)
{
    manager = new QNetworkAccessManager(parent);
    connect(this,SIGNAL(evenement_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(evenement_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(vigicrues_send_info(QMap<QString,QString>)),ord,SIGNAL(vigicrues_send_info(QMap<QString,QString>)));
    connect(this,SIGNAL(avions_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(avions_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(geolocalisation_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(geolocalisation_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(pharmacie_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(pharmacie_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(meteo_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(meteo_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(pollution_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(pollution_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(musee_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(musee_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(satellite_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(satellite_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(borneelectrique_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(borneelectrique_send_info2(QMap<QString,QVariant>)));
    connect(this,SIGNAL(sncf_send_info2(QMap<QString,QVariant>)),ord,SIGNAL(sncf_send_info2(QMap<QString,QVariant>)));

    loop = new QEventLoop(parent);
    QSettings settings_coord ("Geostation", "Geostation");
    if(settings_coord.value("coordonnee/longitude").toString().isEmpty())
    {
        longitude = longitude_.toDouble();
        latitude = latitude_.toDouble();
        radius = radius_.toDouble();
    }
    else {
        longitude = settings_coord.value("coordonnee/longitude").toDouble();
        latitude = settings_coord.value("coordonnee/latitude").toDouble();
        radius = settings_coord.value("coordonnee/rayon").toDouble();
    }
}

AbstractApi::~AbstractApi()
{
    delete loop;
    delete manager;
    delete ord;
}

void AbstractApi::finish(bool error)
{
    loop->exit(error);
}

void AbstractApi::add_list(QMap<QString, QVariant> element)
{
    tableau.append(QVariant(element));
}

void AbstractApi::add_titre(QString titre_value)
{
    parametre.insert("Titre",titre_value);
}

void AbstractApi::add_nb_entree(int nb_entree)
{
    parametre.insert("Nb entree",nb_entree);
}

void AbstractApi::add_coord(QString lat,QString lon){
    parametre.insert("long",lon);
    parametre.insert("lat",lat);
}
