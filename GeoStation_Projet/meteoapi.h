#ifndef METEOAPI_H
#define METEOAPI_H
#include "abstractapi.h"
#include <QNetworkReply>
#include <QMainWindow>
#include <QList>
#include <QSslError>

class MeteoApi : public AbstractApi
{
    Q_OBJECT

public:
    MeteoApi(ordonnanceur *ord_, QObject* parent = 0);

private:
    QNetworkReply *reply;

public slots:
    void Read(QNetworkReply *reply);
    //void update();
    //void error();
};

#endif // METEOAPI_H
