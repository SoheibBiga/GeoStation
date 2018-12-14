#ifndef SATELLITEAPI_H
#define SATELLITEAPI_H

#include <iostream>
#include <QMainWindow>
#include <QtNetwork>
#include <QDebug>
#include <QJsonArray>
#include "abstractapi.h"

class SatelliteApi : public AbstractApi
{
    Q_OBJECT

public:

    SatelliteApi(QObject *parent, int id);
    ~SatelliteApi();

    enum enum_function {tle=0,positions=1,visualpasses=2,radiopasses=3,above=4};
    /*enum enum_category {Amateur_radio=18,Beidou_Navigation_System=35,Brightest=1,Celestis=45,CubeSats=32,Disaster_monitoring=8,
                        Earth_resources=6,Education=29,Engineering=28,Experimental=19,Flock=48,Galileo=22,Geodetic=27,Geostationary=10,
                        Global_Positioning_System_GPS_Constellation=50,Global_Positioning_System_GPS_Operational=20,Globalstar=17,
                        Glonass_Operational=21,GOES=5,Gonets=40,Gorizont=12,Intelsat=11,Iridium=15,IRNSS=46,ISS=2,Lemur=49,Military=30,
                        Molniya=14,Navy_Navigation_Satellite_System=24,NOAA=4,O3B_Networks=43,Orbcomm=16,Parus=38,QZSS=47,Radar_Calibration=31,
                        Raduga=13,Russian_LEO_Navigation=25,Satellite_Based_Augmentation_System=23,Search_and_rescue=7,Space_and_Earth_Science=26,
                        Strela=39,Tracking_and_Data_Relay_Satellite_System=9,Tselina=44,Tsikada=42,Tsiklon=41,TV=34,Weather=3,Westford_Needles=37,
                        XM_and_Sirius=33,Yaogan=36};*/

    void Request_Url(int pos, int category);
    void RetrieveInfo(QString request, int NumSat);

public slots:

    void replyFinished(QNetworkReply *reply);
    void Refresh();


private:

    float Obs_Latitude, Obs_Longitude, Obs_Altitude;
    int Seconds,NORAD_ID,Days_Of_Predic,Minimun_Visibility,Minimim_Elevation,Search_Radius,satCount;
    QString APIKEY,BaseUrl;
    QStringList API_Function;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    enum_function fonction;
    QJsonDocument MyJsonDoc;
    QJsonArray Above_Array;
    QStringList MyList;
    qint64 CurrentSecSinceRequestStart;
    qint64 CurrentSecSinceRequestStop;

};

#endif // SATELLITEAPI_H
