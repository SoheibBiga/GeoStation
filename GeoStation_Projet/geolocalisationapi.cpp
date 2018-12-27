#include "geolocalisationapi.h"

GeolocalisationApi::GeolocalisationApi(ordonnanceur *ord, QObject *parent) : AbstractApi(ord, parent)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &GeolocalisationApi::get_response, Qt::UniqueConnection);
    manager->get(QNetworkRequest(QUrl(QString(url + QString::number(latitude) + "," + QString::number(longitude) + "&outFormat=json&thumbMaps=false"))));
    url.clear();
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
        element.insert("region", base["adminArea3"].toString());
        add_list(element);
        map_ameliore.insert("Tableau",QVariant(tableau));
        map_ameliore.insert("Titre",QVariant(parametre));

        emit geolocalisation_send_info2(map_ameliore);
        disconnect(manager, &QNetworkAccessManager::finished, nullptr, nullptr);
        manager->get(QNetworkRequest(QUrl(QString(url_map + base["street"].toString().replace(" ", "+") + "," + base["adminArea5"].toString()+ "+" + base["postalCode"].toString()  + "|sm&locations=" + QString::number(latitude) + "," + QString::number(longitude) + "&zoom=18&size=800,800@2x&key=SokFIBhCH80wtXJaHxq1mVnmsdzKgkAQ"))));
        url_map.clear();
        connect(manager, &QNetworkAccessManager::finished, this, &GeolocalisationApi::get_map, Qt::UniqueConnection);
        //qDebug() << "Entry";
    }
    else {
        finish(0);
    }
}

void    GeolocalisationApi::get_map(QNetworkReply *rep)
{
    if (rep->error() == QNetworkReply::NoError)
    {
        QByteArray array = rep->readAll();

        map_ameliore.clear();
        element.clear();
        tableau.clear();
        parametre.clear();

        element.insert("map", QVariant(array));
        add_list(element);
        map_ameliore.insert("Tableau",QVariant(tableau));
        map_ameliore.insert("Titre",QVariant(parametre));
        emit geolocalisation_send_info2(map_ameliore);
        finish(0);

    }
    else {
        finish (0);
    }
}

GeolocalisationApi::~GeolocalisationApi()
{
    delete manager;
}
