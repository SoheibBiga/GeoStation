#include "pharmacieapi.h"


PharmacieApi::PharmacieApi(ordonnanceur *ord_, QObject *parent): AbstractApi(IdWidget(Pharmacie), ord_, parent)
{
    manager = new QNetworkAccessManager(parent);

    latitude = 48.871671;
    longitude = 2.346106;
    radius = 500;

    request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance="
                        + QString::number(latitude) + "%2C+" + QString::number(longitude) + "%2C+" + QString::number(radius)));



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
    QMap<QString,QVariant> element;

    QByteArray tab = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(tab);

    QJsonArray tableau = doc.object().value("records").toArray();


    for(int i= 0; i < tableau.count(); i++)
    {
    QString nom = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["rs"].toString();
    QString adresse = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["adresse"].toString();
    QString distance = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["dist"].toString();
    QString codePostal = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["ligneacheminement"].toString();

    element.insert("Nom",QVariant(nom));
    element.insert("Adresse",QVariant(adresse));
    element.insert("CodePostal",QVariant(codePostal));
    element.insert("Distance",QVariant(distance));
    add_list(element);

    //ui->textEdit->insertPlainText(nom + "\n" + adresse + "\n" + codePostal + "\nà " + distance + " mètres\n\n");
    //qDebug() << nom <<"\n" << adresse << "\n" << codePostal << "\nà " <<  distance << " mètres\n\n";
    }
    map_ameliore.insert("Tableau",QVariant(tableau));
    map_ameliore.insert("Titre",QVariant(parametre));

    emit pharmacie_send_info2(map_ameliore);
    finish(0);
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

//bool PharmacieApi::isMap()
//{
//    return true;
//}

//bool PharmacieApi::hasBigLayout()
//{
//    return false;
//}
