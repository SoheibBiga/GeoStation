#ifndef EVENTAPI_H
#define EVENTAPI_H

#include "abstractapi.h"

//1. GB: 181214 => create class EventApi

class EventApi : public AbstractApi
{
public:
    EventApi(QObject *parent, int id);

    // code => methodes + attribues

    ~EventApi();
};

#endif // EVENTAPI_H
