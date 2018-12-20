#ifndef BORNEELECTRIQUEAPI_H
#define BORNEELECTRIQUEAPI_H


#include "abstractapi.h"

class BorneElectriqueApi : public AbstractApi
{

    Q_OBJECT

public:
    BorneElectriqueApi(QObject *parent = 0);
    ~BorneElectriqueApi();

public slots:
    void replyFinished(QNetworkReply *reply);

private:
    QJsonDocument doc;
    qint64 t1,t2;
};

#endif // BORNEELECTRIQUEAPI_H

