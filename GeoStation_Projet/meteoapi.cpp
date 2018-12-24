#include "meteoapi.h"

MeteoApi::MeteoApi(ordonnanceur *ord_, QObject* parent) : AbstractApi(IdWidget(Meteo), ord_, parent)
{
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request;

    QString adresse = "http://api.openweathermap.org/data/2.5/weather?lat=48.866667&lon=2.333333&APPID=dc9739f0114abf26141e6d2606005cc8";


    request.setUrl(QUrl(adresse));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

   // qDebug() << request.url();

    reply = manager->get(request);

    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(Read(QNetworkReply *)));
    //connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(error(QNetworkReply *)));

    //Date

    //jour(QDate::fromString("24MM12car2018", "d'MM'MMcaryyyy"));
}

MeteoApi::~MeteoApi()
{}

void MeteoApi::Read(QNetworkReply *reply)

{
    QByteArray ba=reply->readAll();
    //ui->textEdit->setPlainText(ba);
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    //foreach ( QString key, doc.object().toVariantMap().keys())

    //qDebug()<<key<<doc.object().toVariantMap()[key]<<"\n\n";


    // double getlon = doc.toVariant().toHash()["coord"].toHash()["lon"].toDouble();
    //  double getlat = doc.toVariant().toHash()["coord"].toHash()["lat"].toDouble();

    //    qDebug()<<"RESULTAT weatherid: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["id"];
    //    qDebug()<<"RESULTAT main : "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["main"];
    //    qDebug()<<"RESULTAT description: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["description"];
    //    qDebug()<<"RESULTAT icon: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["icon"];
    //    qDebug()<<"RESULTAT  Base: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["base"];

    //    qDebug()<<"RESULTAT humidity: "<<doc.toVariant().toHash()["main"].toHash()["humidity"];
    //    qDebug()<<"RESULTAT temp_min: "<<doc.toVariant().toHash()["main"].toHash()["temp_min"];
    //    qDebug()<<"RESULTAT temp_max: "<<doc.toVariant().toHash()["main"].toHash()["temp_max"];



    double tempmax=doc.toVariant().toHash()["main"].toHash()["temp_max"].toDouble();
    QString tempmax2=doc.toVariant().toHash()["main"].toHash()["temp_max"].toString();
    //qDebug()<<tempmax<<tempmax2;

    double weatherid=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["id"].toDouble();
    QString weathermain=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["main"].toString();
    QString weatherdescription=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["description"].toString();
    QString weathericon=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["icon"].toString();

    QString weatherbase=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["base"].toString();
    double mainhum=doc.toVariant().toHash()["main"].toHash()["humidity"].toDouble();

    double maintempmin=doc.toVariant().toHash()["main"].toHash()["temp_min"].toDouble();
    double maintempmax=doc.toVariant().toHash()["main"].toHash()["temp_max"].toDouble();

    add_titre("Meteo du jour");
    QMap<QString,QVariant> element;
    element.insert("Temperature Maximale",QVariant(maintempmax));


    add_list(element);
    map_ameliore.insert("Tableau",QVariant(tableau));
    map_ameliore.insert("Parametre",QVariant(parametre));
    emit meteo_send_info2(map_ameliore);
    finish(0);

    // Temperaturemin Temperaturemax
    maintempmin=maintempmin-273.15;
    //ui->lineEdit_4->setText(QString("%1").arg(maintempmin));
    maintempmax=maintempmax-273.15;
    //    ui->lineEdit_5->setText(QString("%1").arg(maintempmax));
    //    ui->label_4->setAlignment(Qt::AlignHCenter);

}/*fin*/
