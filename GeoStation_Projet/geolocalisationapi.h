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
    QMap<QString,QVariant> element;
};

#endif // GEOLOCALISATIONAPI_H
