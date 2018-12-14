#include "abstractapi.h"

AbstractApi::AbstractApi(QObject *parent) : QObject(parent)
{

}

AbstractApi::AbstractApi(QObject *parent,int myId,QString longitude_,QString latitude_, QString radius_) : QObject(parent), Id(myId)
{
    QSettings settings_coord;
    if(settings_coord.value("Coord/Longitude")=="" || settings_coord.value("Coord/Latitude")=="" || settings_coord.value("Coord/Radius")=="")
    {
        settings_coord.setValue("Coord/Longitude",longitude_);
        settings_coord.setValue("Coord/Latitude",latitude_);
        settings_coord.setValue("Coord/Radius",radius_);
    }

}
