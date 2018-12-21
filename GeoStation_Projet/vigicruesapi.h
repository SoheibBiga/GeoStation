#ifndef VIGICRUESAPI_H
#define VIGICRUESAPI_H
#include "abstractapi.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class VigicruesApi  : public AbstractApi
{

        Q_OBJECT
public:
    VigicruesApi(ordonnanceur* ord_,QObject *parent = 0);

    QNetworkReply *m_reply;
    QNetworkReply *m_reply2;
    QNetworkRequest m_request;
    QNetworkRequest m_request2;
    QJsonDocument Myjson;
    QJsonDocument Myjson2;
    QString station_id;
    QString lb_station;
    double distance_station;
    QString elementsRequete[5];
    QString Nb_rows;
    QDateTime dateTimeDerniereMAJ;
    bool boolUnSeulAppelALafois;
    void definitionAppelRequete();

    ~VigicruesApi();
private :
    void traitementRequeteInitialisation(QNetworkReply *rep);
    void traitementRequeteEnregistrements(QNetworkReply *rep);

private slots:
    void reponseRecue(QNetworkReply *rep);
    void slotError(QNetworkReply::NetworkError erreurtype);
    void slotSslErrors(QList<QSslError>);
};

#endif // VIGICRUESAPI_H
