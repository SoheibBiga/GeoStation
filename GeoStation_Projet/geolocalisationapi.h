#ifndef GEOLOCALISATIONAPI_H
#define GEOLOCALISATIONAPI_H

#include "abstractapi.h"

class GeolocalisationApi : public AbstractApi
{
public:
    GeolocalisationApi(ordonnanceur *ord, QObject *parent = nullptr);
    ~GeolocalisationApi();
private slots:
    void    get_response(QNetworkReply *reply);
    void    get_map(QNetworkReply *rep);
private:
    QString url = "https://www.mapquestapi.com/geocoding/v1/reverse?key=SokFIBhCH80wtXJaHxq1mVnmsdzKgkAQ&location=";
    QString url_map = "https://www.mapquestapi.com/staticmap/v5/map?banner=";
    QMap<QString,QVariant> element;
};

#endif // GEOLOCALISATIONAPI_H
