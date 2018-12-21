#ifndef PHARMACIEAPI_H
#define PHARMACIEAPI_H

#include "abstractapi.h"


class PharmacieApi : public AbstractApi
{
    Q_OBJECT

public:
    PharmacieApi(ordonnanceur *ord_, QObject *parent = 0);
    ~PharmacieApi();

    QNetworkRequest request;
    QNetworkReply *reply;

    bool isMap();
    bool hasBigLayout();

private slots:
    void listePharmacie(QNetworkReply *reply);
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError);
    void slotSslErrors(QList<QSslError>);
};

#endif // PHARMACIEAPI_H
