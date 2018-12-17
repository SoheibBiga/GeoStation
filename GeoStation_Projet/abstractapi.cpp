#include "abstractapi.h"

/*AbstractApi::AbstractApi(QObject *parent) : QObject(parent)
{

}*/

AbstractApi::AbstractApi(QObject *parent,int myId,QString longitude_,QString latitude_, QString radius_)
    : QObject(parent), Id(myId),
      longitude(longitude_.toDouble()),
      latitude(latitude_.toDouble()),
      radius(radius_.toDouble())
{
    loop = new QEventLoop(parent);
    QSettings settings_coord;
    if(settings_coord.value("Coord/Longitude")=="" || settings_coord.value("Coord/Latitude")=="" || settings_coord.value("Coord/Radius")=="")
    {
        settings_coord.setValue("Coord/Longitude",longitude_);
        settings_coord.setValue("Coord/Latitude",latitude_);
        settings_coord.setValue("Coord/Radius",radius_);
    }

}

AbstractApi::AbstractApi(int myId, QObject *parent, QString longitude_, QString latitude_, QString radius_)
    : QObject(parent),
      Id(myId),
      longitude(longitude_.toDouble()),
      latitude(latitude_.toDouble()),
      radius(radius_.toDouble())
{
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
