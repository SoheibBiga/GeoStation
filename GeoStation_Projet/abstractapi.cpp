#include "abstractapi.h"
#include "ordonnanceur.h"

/*AbstractApi::AbstractApi(QObject *parent) : QObject(parent)
{

}*/


AbstractApi::AbstractApi(int myId, ordonnanceur *ord_, QObject *parent, QString longitude_, QString latitude_, QString radius_)
    : QObject(parent),
      ord(ord_),
      Id(myId),
      longitude(longitude_.toDouble()),
      latitude(latitude_.toDouble()),
      radius(radius_.toDouble())
{
    manager = new QNetworkAccessManager(parent);

    connect(this,SIGNAL(send_info(QMap<QString,QString>)),ord,SIGNAL(send_info(QMap<QString,QString>)));
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),ord,SIGNAL(send_info2(QMap<QString,QVariant>)));

    loop = new QEventLoop(parent);
    QSettings settings_coord;
    if(settings_coord.value("Coord/Longitude")=="" || settings_coord.value("Coord/Latitude")=="" || settings_coord.value("Coord/Radius")=="")
    {
        settings_coord.setValue("Coord/Longitude",longitude_);
        settings_coord.setValue("Coord/Latitude",latitude_);
        settings_coord.setValue("Coord/Radius",radius_);
    }
}

void AbstractApi::finish(bool work)
{
    loop->exit(work);
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
