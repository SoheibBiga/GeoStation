#ifndef EVENEMENTAPI_H
#define EVENEMENTAPI_H

#include "abstractapi.h"

//181214 GB => create class EventApi

class EvenementApi : public AbstractApi
{

    Q_OBJECT

public:
    EvenementApi(ordonnanceur *ord_, QObject *parent = 0);
    ~EvenementApi();

private slots:
    void reponseRecue(QNetworkReply *rep);
    void slotError(QNetworkReply::NetworkError erreurtype);
    void slotSslErrors(QList<QSslError>);
};

#endif // EVENTAPI_H
