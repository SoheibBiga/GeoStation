#ifndef BORNEELECTRIQUEAPI_H
#define BORNEELECTRIQUEAPI_H


#include "abstractapi.h"

class BorneElectriqueAPI : public AbstractApi
{
public:
    BorneElectriqueAPI(QObject *parent, int id);
    ~BorneElectriqueAPI();

public slots:
    void replyFinished(QNetworkReply *reply);
    void Request();
private:
    QJsonDocument doc;
    qint64 t1,t2;
};

#endif // BORNEELECTRIQUEAPI_H
