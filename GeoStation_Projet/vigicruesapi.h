#ifndef VIGICRUESAPI_H
#define VIGICRUESAPI_H
#include "abstractapi.h"

class VigicruesApi  : public AbstractApi
{

        Q_OBJECT
public:
    VigicruesApi(QObject *parent, int id);

    QNetworkReply *m_reply;
    QNetworkRequest m_request;
    QJsonDocument Myjson;

    QDateTime dateTime1;
    QDateTime dateTime_fin;
    QDateTime dateTime_request;
    ~VigicruesApi();

private slots:
    void reponseRecue(QNetworkReply *rep);
    void slotError(QNetworkReply::NetworkError erreurtype);
    void slotSslErrors(QList<QSslError>);
};

#endif // VIGICRUESAPI_H
