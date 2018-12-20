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
    map_formulaire = new QMap<QString, QString>;
    //map_ameliore = new QMap

    connect(this,SIGNAL(send_info(QMap<QString,QString>)),ord,SIGNAL(send_info(QMap<QString,QString>)));
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

/*bool isMap(){
    qDebug() << "WARNING : La fonction isMap() va bientôt passer virtuelle pure, veuillez l'implementer dans votre classe fille";
    return false;
}

bool hasBigLayout(){
    qDebug() << "WARNING : La fonction hasBigLayout() va bientôt passer virtuelle pure, veuillez l'implementer dans votre classe fille";
    return false;
}*/

void AbstractApi::add_list(QMap<QString, QString> element)
{

}

void AbstractApi::add_titre(QString titre)
{

}
