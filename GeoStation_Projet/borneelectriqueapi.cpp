#include "borneelectriqueapi.h"
#include <QNetworkReply>
#include <QFile>
#include <qdatetime.h>


BorneElectriqueApi::BorneElectriqueApi(ordonnanceur *ord_, QObject* parent) : AbstractApi(ord_, parent)
{

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    //+§connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Request()));

    //start since epoch
    QString Latitude = QString::number(latitude)+"%2C";
    QString Longitude = QString::number(longitude)+"%2C";

    manager->get(QNetworkRequest(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=fichier-consolide-des-bornes-de-recharge-pour-vehicules-electriques-irve&sort=-date_maj&geofilter.distance="+Latitude+"+"+Longitude+"+"+QString::number(radius))));
}

BorneElectriqueApi::~BorneElectriqueApi()
{

}

void BorneElectriqueApi::replyFinished(QNetworkReply* reply)
{
    QString reply_string;
    reply_string=reply->readAll();
    //ui->textEdit->setText(reply_string);

    doc ={QJsonDocument::fromJson(reply_string.toUtf8())};
    QMap<QString,QVariant> element;
    add_titre("Borne Electriques A Proximité");
    //add_nb_entree(total_result);
    for (int i=0; i<10; ++i){

        QString type_charge = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["type_charge"].toString();
        element.insert("type de charge: ",type_charge);
        QString commune = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["commune"].toString();
        element.insert("commune: ",commune);
        QString type_connecteur = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["type_connecteur"].toString();
        element.insert("type_connecteur: ",type_connecteur);
        QString adresse_station = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["adresse_station"].toString();
        element.insert("adresse_station: ",adresse_station);
        QString source = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["source"].toString();
        element.insert("source : ",source);
        QString observations = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["observations"].toString();
        element.insert("observations: ",observations);
        QString id_station = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["id_station"].toString();
        element.insert("id_station: ",id_station);
        add_list(element);
    }

    map_ameliore.insert("Tableau",QVariant(tableau));
    map_ameliore.insert("Parametre",QVariant(parametre));
    emit borneelectrique_send_info2(map_ameliore);
    finish(0);
}





