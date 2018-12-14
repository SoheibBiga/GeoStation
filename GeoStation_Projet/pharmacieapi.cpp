#include "pharmacieapi.h"

#include <QNetworkAccessManager>

ApiPharmacie::ApiPharmacie(QObject *parent,int id):AbstractApi(parent, id)
{
    manager = new QNetworkAccessManager(parent);

    latitude = 48.871671;
    longitude = 2.346106;

    request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance=" + QString::number(latitude) + "%2C+" + QString::number(longitude) + "%2C+" + rayon));
    reply = manager->get(request);

    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(listePharmacie(QNetworkReply*)));

}


void ApiPharmacie::listePharmacie(QNetworkReply *reply)
{

    QByteArray tab = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(tab);

    qDebug() <<"alors"<< doc.object().toVariantMap().keys();

    QJsonArray tableau = doc.object().value("records").toArray();

    for(int i= 0; i < tableau.count(); i++)
    {
    QString nom = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["rs"].toString();
    QString adresse = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["adresse"].toString();
    QString distance = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["dist"].toString();
    QString codePostal = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["ligneacheminement"].toString();

    //ui->textEdit->insertPlainText(nom + "\n" + adresse + "\n" + codePostal + "\nà " + distance + " mètres\n\n");
    qDebug() << nom << "\n" << adresse << "\n" << codePostal << "\nà" << distance << " mètres\n\n";
    }
}

void ApiPharmacie::slotReadyRead()
{
    qDebug() << "SlotReadyRead";
}

void ApiPharmacie::slotError(QNetworkReply::NetworkError)
{
    qDebug() <<"slotError" ;
}

void ApiPharmacie::slotSslErrors(QList<QSslError>)
{
    qDebug() << "slotSslError";
}
