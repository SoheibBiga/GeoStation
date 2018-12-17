#ifndef EVENEMENTAPI_H
#define EVENEMENTAPI_H

#include "abstractapi.h"

//181214 GB => create class EventApi

class EvenementApi : public AbstractApi
{

    Q_OBJECT

public:
    EvenementApi(QObject *parent = 0);

    QNetworkReply *m_reply;
    QNetworkRequest m_request;
    QJsonDocument Myjson;

    QDateTime dateTime1;
    QDateTime dateTime_fin;
    QDateTime dateTime_request;
    ~EvenementApi();

private slots:
    void reponseRecue(QNetworkReply *rep);
    void slotError(QNetworkReply::NetworkError erreurtype);
    void slotSslErrors(QList<QSslError>);
};

#endif // EVENTAPI_H
