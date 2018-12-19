#ifndef GEOLOCALISATIONAPI_H
#define GEOLOCALISATIONAPI_H

#include "abstractapi.h"

class GeolocalisationApi : public AbstractApi
{
public:
    GeolocalisationApi(ordonnanceur *ord, QObject *parent);
    ~GeolocalisationApi();
private slots:
    void    get_response(QNetworkReply *reply);
};

#endif // GEOLOCALISATIONAPI_H
