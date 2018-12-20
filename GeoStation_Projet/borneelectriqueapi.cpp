#include "borneelectriqueapi.h"
#include <QNetworkReply>
#include <QFile>
#include <qdatetime.h>

BorneElectriqueApi::BorneElectriqueApi(ordonnanceur *ord_, QObject* parent) : AbstractApi(IdWidget(BorneElectrique), ord_, parent)
{

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    //+§connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Request()));

    //start since epoch
    t1= QDateTime::currentMSecsSinceEpoch();
    manager->get(QNetworkRequest(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=fichier-consolide-des-bornes-de-recharge-pour-vehicules-electriques-irve&sort=-date_maj")));
    finish(0);
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
    for (int i=0; i<10; ++i){

        QString type_charge = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["type_charge"].toString();
        map_formulaire.insert("type de charge: ",type_charge);
        QString commune = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["commune"].toString();
        map_formulaire.insert("commune: ",commune);
        QString type_connecteur = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["type_connecteur"].toString();
        map_formulaire.insert("type_connecteur: ",type_connecteur);
        QString adresse_station = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["adresse_station"].toString();
        map_formulaire.insert("adresse_station: ",adresse_station);
        QString source = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["source"].toString();
        map_formulaire.insert("source : ",source);
        QString observations = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["observations"].toString();
        map_formulaire.insert("observations: ",observations);
        QString id_station = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["id_station"].toString();
        map_formulaire.insert("id_station: ",id_station);
        QString Xlongitude = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["Xlongitude"].toString();
        map_formulaire.insert("Xlongitude: ",Xlongitude);
        QString Ylatitude = doc.toVariant().toMap()["records"].toJsonArray().at(i).toVariant().toMap()["fields"].toMap()["Ylatitude"].toString();
        map_formulaire.insert("Ylatitude: ",Ylatitude);
    }

    //stop since epoch
    t2= QDateTime::currentMSecsSinceEpoch();
    //différence puis saffiche en qDebug
    qDebug() << t2-t1;
}





