#ifndef APIPHARMACIE_H
#define APIPHARMACIE_H

#include "abstractapi.h"

#include <QtNetwork>


class ApiPharmacie : public AbstractApi
{

public:
    ApiPharmacie(QObject *parent, int id);

private slots:
    void listePharmacie(QNetworkReply *reply);
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError);
    void slotSslErrors(QList<QSslError>);
};

#endif // APIPHARMACIE_H
