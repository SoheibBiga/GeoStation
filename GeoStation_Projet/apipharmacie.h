#ifndef APIPHARMACIE_H
#define APIPHARMACIE_H

#include "abstractapi.h"

#include <QtNetwork>


class ApiPharmacie : public AbstractApi
{

public:
    ApiPharmacie(QObject *parent, int id);

    QNetworkRequest request;
    QNetworkReply *reply;

    QString latitude = "48.871671";
    QString longitude = "2.346106";
    QString rayon = "500";

private slots:
    void listePharmacie(QNetworkReply *reply);
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError);
    void slotSslErrors(QList<QSslError>);
};

#endif // APIPHARMACIE_H
