#ifndef SATELLITEAPI_H
#define SATELLITEAPI_H

#include "abstractapi.h"

class SatelliteApi : public AbstractApi
{
public:
    SatelliteApi(QObject *parent, int id);
};

#endif // SATELLITEAPI_H
