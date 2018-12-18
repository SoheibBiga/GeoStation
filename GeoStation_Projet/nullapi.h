#ifndef NULLAPI_H
#define NULLAPI_H

#include "abstractapi.h"

class nullapi : public AbstractApi
{
    Q_OBJECT
public:
    nullapi(ordonnanceur *ord_, QObject *parent = 0);

    bool isMap();
    bool hasBigLayout();

signals:
    void send_info(QMap<QString, QString>);
};

#endif // NULLAPI_H
