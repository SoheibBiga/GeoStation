#ifndef METEOAPI_H
#define METEOAPI_H
#include "abstractapi.h"
#include <QNetworkReply>
#include <QMainWindow>
#include <QList>
#include <QSslError>
#include <QDate>


class MeteoApi : public AbstractApi
{
    Q_OBJECT

public:
    MeteoApi(ordonnanceur *ord_, QObject* parent = 0);
    ~MeteoApi();

    void jour(QDate jour);

private:
    QNetworkReply *reply;

public slots:
    void Read(QNetworkReply *reply);

};

#endif // METEOAPI_H
