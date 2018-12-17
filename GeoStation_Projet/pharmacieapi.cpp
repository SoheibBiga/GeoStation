#include "pharmacieapi.h"

#include <QNetworkAccessManager>

PharmacieApi::PharmacieApi(int id, QObject *parent):AbstractApi(parent, id)
{
    manager = new QNetworkAccessManager(parent);

    request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance="
                        + QString::number(latitude) + "%2C+" + QString::number(longitude) + "%2C+" + radius));

    reply = manager->get(request);

    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(listePharmacie(QNetworkReply*)));

}

PharmacieApi::~PharmacieApi()
{

}


void PharmacieApi::listePharmacie(QNetworkReply *reply)
{
    QByteArray tab = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(tab);

    QJsonArray tableau = doc.object().value("records").toArray();

    for(int i= 0; i < tableau.count(); i++)
    {
    QString nom = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["rs"].toString();
    QString adresse = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["adresse"].toString();
    QString distance = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["dist"].toString();
    QString codePostal = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["ligneacheminement"].toString();

    //ui->textEdit->insertPlainText(nom + "\n" + adresse + "\n" + codePostal + "\nà " + distance + " mètres\n\n");

    }
}

void PharmacieApi::slotReadyRead()
{

}

void PharmacieApi::slotError(QNetworkReply::NetworkError)
{

}

void PharmacieApi::slotSslErrors(QList<QSslError>)
{

}
