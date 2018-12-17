#ifndef APIAVIONS_H
#define APIAVIONS_H



#include "abstractapi.h"

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

#include <QDir>

#include <QString>
#include <QValidator>

#include <QByteArray>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QFile>

#include <QDateTime>

#include <QMainWindow>


class apiavions : public AbstractApi
{


public:
    apiavions(QObject *parent, int id);
       QNetworkReply* reply;
       QNetworkReply* reply_singleplane;

    ~apiavions();

private:

    QNetworkAccessManager *manager;
    QNetworkAccessManager *manager_singleplane;
    QList<QSslError> list;

    QString lat_min = "44";
    QString lat_max = "45";
    QString longi_min = "1";
    QString longi_max = "2";

    QString construct_URL;
    QString URL_singleplane;
    QString ICAO24;
    QString writesingleplanes;

    QDateTime timeBegin;
    QDateTime timeEnd;

 private slots:

    void delay(int);

    void change_coordinates();

    void query_singleplane();

    void replyFinished(QNetworkReply*);

    void affiche_erreurs( QNetworkReply*,QList<QSslError>  );

    void view_airlinecompanies();

    void getsingleplaneinfo(QNetworkReply*);



};




#endif // APIAVIONS_H
