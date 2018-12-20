#ifndef MUSEESAPI_H
#define MUSEESAPI_H

#include "abstractapi.h"


class MuseesApi : public AbstractApi
{
    Q_OBJECT

public:
    MuseesApi(ordonnanceur *ord_, QObject *parent = nullptr);
};

#endif // MUSEESAPI_H
