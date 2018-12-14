#ifndef EVENTAPI_H
#define EVENTAPI_H

#include "abstractapi.h"

//181214 GB => create class EventApi

class EventApi : public AbstractApi
{
public:
    EventApi(QObject *parent, int id);

    QString latitude;
    QString longitude;
    QString radius;

    QNetworkAccessManager *m_event;
    QNetworkReply *m_reply;
    QNetworkRequest m_request;
    QJsonDocument Myjson;

    QDateTime dateTime1;
    QDateTime dateTime_fin;
    QDateTime dateTime_request;
    ~EventApi();

private slots:
    void display();
    void reponseRecue(QNetworkReply *reply);
};

#endif // EVENTAPI_H
