#include "geolocalisationapi.h"

GeolocalisationApi::GeolocalisationApi(ordonnanceur *ord, QObject *parent) : AbstractApi(IdWidget(Geolocalisation), ord, parent)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &GeolocalisationApi::get_response, Qt::UniqueConnection);
    manager->get(QNetworkRequest(QUrl(QString("https://www.mapquestapi.com/geocoding/v1/reverse?key=iGT3ydQS7XPt0LAjtbfk2LBioZCiUbOB&location=" + QString::number(latitude) + "," + QString::number(longitude) + "&outFormat=json&thumbMaps=false"))));
}

void    GeolocalisationApi::get_response(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray val;
        QJsonDocument d;
        QJsonValue base;

        val = reply->readAll();
        d = QJsonDocument::fromJson(val);
        base = d.object().toVariantMap()["results"].toJsonArray().at(0)["locations"].toArray().at(0);
        manager->clearConnectionCache();
        manager->clearAccessCache();

        map_formulaire.insert("adresse", base["street"].toString());
        map_formulaire.insert("ville", base["adminArea5"].toString());
        map_formulaire.insert("codePostal", base["postalCode"].toString());

        emit send_info(map_formulaire);
        finish(true);
    }
}

GeolocalisationApi::~GeolocalisationApi()
{
    delete manager;
}
