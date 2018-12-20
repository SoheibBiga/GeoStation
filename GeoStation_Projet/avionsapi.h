#ifndef AVIONSAPI_H
#define AVIONSAPI_H

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
//#include <QSqlDatabase>
//#include <QSqlQuery>


#include <QMainWindow>


class avionsapi : public AbstractApi
{

    Q_OBJECT
public:
    avionsapi(ordonnanceur *ord_, QObject *parent = 0);
    QNetworkReply* reply;
    QNetworkReply* reply_singleplane;

    ~avionsapi();

private:

    QNetworkAccessManager *manager_singleplane;
    QList<QSslError> list;

    QString lat_min = "43.5";
    QString lat_max = "44";
    QString longi_min = "1";
    QString longi_max = "2";
    QString construct_URL;
    QString URL_singleplane;
    QString ICAO24;
    QString writesingleplanes;
    //QString path_file_airports = (QDir::homePath() +  "/Documents/WILLIAM/Embarque/project/icao_world.xls");

    QDateTime timeBegin;
    QDateTime timeEnd;
    QJsonArray list_planes_array;

    QString API_key;


    QString airport_code;
    QString plane_code;
    QString airport_name;
    QString plane_model_name;



private slots:

    void delay(int);

    void change_coordinates();

    void query_singleplane();

    void replyFinished(QNetworkReply*);

    void affiche_erreurs( QNetworkReply*,QList<QSslError>  );

    void view_airlinecompanies();

    void getsingleplaneinfo(QNetworkReply*);

    void parseplanelist();

    void readairports();
    void readplane_type();


};




#endif // AVIONSAPI_H
