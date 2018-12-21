#ifndef MUSEESAPI_H
#define MUSEESAPI_H

#include "abstractapi.h"


class MuseesApi : public AbstractApi
{
    Q_OBJECT

public:
    MuseesApi(ordonnanceur *ord_, QObject *parent = nullptr);
    bool isMap();

private:
    QNetworkAccessManager *networkManager;
};

#endif // MUSEESAPI_H
