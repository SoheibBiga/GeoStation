#ifndef AVIONSAPI_H
#define AVIONSAPI_H

#include "abstractapi.h"

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

#include <QDir>

#include <QString>
#include <QStringRef>
#include <QValidator>
#include <QtMath>

#include <QByteArray>
//#include <QtScript>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QFile>

#include <QDateTime>

#include <QTextStream>



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

    QString lat_min = "48.8";
    QString lat_max = "49.1";
    QString longi_min = "2.4";
    QString longi_max = "2.8";
    QString construct_URL;
    QString URL_singleplane;
    QString ICAO24;
    QString write_Info_APi2;
    QString requete_singleplane;    // to be written as text file
    QString write_first_requete;
    QString write_APi1_info;    //info extracted from APi1

    QDateTime timeBegin= QDateTime::currentDateTime();
    QString time = timeBegin.toString();
    QString output_folder = ("output/"+time+"/");

    QDateTime timeEnd;
    QJsonArray list_planes_array;
    QJsonArray single_plane_array; //for APi1

    QString API_key;

    QString airport_code;
    QString plane_code;
    QString airport_name;
    QString plane_model_name;
    QString airline_code;
    QString airline_name;



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
