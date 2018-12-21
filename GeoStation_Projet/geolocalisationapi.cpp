#include "geolocalisationapi.h"

GeolocalisationApi::GeolocalisationApi(ordonnanceur *ord, QObject *parent) : AbstractApi(IdWidget(Geolocalisation), ord, parent)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &GeolocalisationApi::get_response, Qt::UniqueConnection);
    manager->get(QNetworkRequest(QUrl(QString("https://www.mapquestapi.com/geocoding/v1/reverse?key=iGT3ydQS7XPt0LAjtbfk2LBioZCiUbOB&location=" + QString::number(latitude) + "," + QString::number(longitude) + "&outFormat=json&thumbMaps=false"))));

    add_titre("Informations de Geolocalisation");
    add_nb_entree(1);
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


        element.insert("adresse", base["street"].toString());
        element.insert("ville", base["adminArea5"].toString());
        element.insert("codePostal", base["postalCode"].toString());

        manager->get(QNetworkRequest(QUrl(QString("https://www.mapquestapi.com/staticmap/v5/map?banner=" + base["street"].toString().replace(" ", "+") + "," + base["adminArea5"].toString()+ "+" + base["postalCode"].toString()  + "|sm&locations=" + base["street"].toString().replace(" ", "+") + "," + base["adminArea5"].toString() + "+" + base["postalCode"].toString().mid(0,2) + "&size=800,800@2x&key=iGT3ydQS7XPt0LAjtbfk2LBioZCiUbOB"))));
        connect(manager, &QNetworkAccessManager::finished, this, &GeolocalisationApi::get_map, Qt::UniqueConnection);

    }
}

void    GeolocalisationApi::get_map(QNetworkReply *rep)
{
    if (rep->error() == QNetworkReply::NoError)
    {
        QByteArray array = rep->readAll();

        element.insert("Map", array);
        add_list(element);
        map_ameliore.insert("Tableau",QVariant(tableau));
        map_ameliore.insert("Titre",QVariant(parametre));
        emit send_info(map_formulaire);
        finish(0);
    }
}

GeolocalisationApi::~GeolocalisationApi()
{
    delete manager;
}
