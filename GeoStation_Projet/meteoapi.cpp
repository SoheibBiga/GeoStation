#include "meteoapi.h"

MeteoApi::MeteoApi(ordonnanceur *ord_, QObject* parent) : AbstractApi(IdWidget(Meteo), ord_, parent)
{

    manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    // QString token = "APPID=dc9739f0114abf26141e6d2606005cc8";

    QString adresse = "https://samples.openweathermap.org/data/2.5/weather?lat=35&lon=139&APPID=dc9739f0114abf26141e6d2606005cc8";
    request.setUrl(QUrl(adresse));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    //request.setRawHeader("User-Agent:Accept", "JSON");
    qDebug() << request.url();

    reply = manager->get(request);

    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(Read(QNetworkReply *)));
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(error(QNetworkReply *)));
}


void MeteoApi::Read(QNetworkReply *reply)
{
    QByteArray ba=reply->readAll();
    //ui->textEdit->setPlainText(ba);
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    //foreach ( QString key, doc.object().toVariantMap().keys())

    //qDebug()<<key<<doc.object().toVariantMap()[key]<<"\n\n";


    // double getlon = doc.toVariant().toHash()["coord"].toHash()["lon"].toDouble();
    //  double getlat = doc.toVariant().toHash()["coord"].toHash()["lat"].toDouble();

    qDebug()<<"RESULTAT weatherid: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["id"];
    qDebug()<<"RESULTAT main : "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["main"];
    qDebug()<<"RESULTAT description: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["description"];
    qDebug()<<"RESULTAT icon: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["icon"];
    qDebug()<<"RESULTAT  Base: "<<doc.toVariant().toHash()["weather"].toList().at(0).toMap()["base"];

    qDebug()<<"RESULTAT humidity: "<<doc.toVariant().toHash()["main"].toHash()["humidity"];
    qDebug()<<"RESULTAT temp_min: "<<doc.toVariant().toHash()["main"].toHash()["temp_min"];
    qDebug()<<"RESULTAT temp_max: "<<doc.toVariant().toHash()["main"].toHash()["temp_max"];


    double tempmax=doc.toVariant().toHash()["main"].toHash()["temp_max"].toDouble();
    QString tempmax2=doc.toVariant().toHash()["main"].toHash()["temp_max"].toString();
    qDebug()<<tempmax<<tempmax2;

//    double weatherid=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["id"].toDouble();
//    QString weathermain=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["main"].toString();
//    QString weatherdescription=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["description"].toString();
//    QString weathericon=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["icon"].toString();

//    QString weatherbase=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["base"].toString();
//    double mainhum=doc.toVariant().toHash()["main"].toHash()["humidity"].toDouble();

//    double maintempmin=doc.toVariant().toHash()["main"].toHash()["temp_min"].toDouble();
//    double maintempmax=doc.toVariant().toHash()["main"].toHash()["temp_max"].toDouble();


//      map_formulaire.insert("Temperature",QString::number(maintempmin));
//      map_formulaire.insert("Temperature",QString::number(maintempmax));


    // ui->textEdit->insertPlainText(QString("%1"));


//    ui->textEdit->append(QString("id:%1\n").arg(weatherid));
//    ui->textEdit->insertPlainText(QString("main: %1\n" ).arg(weathermain ));
//    ui->textEdit->insertPlainText(QString("Description: %1\n").arg(weatherdescription));
//    ui->textEdit->insertPlainText(QString("icon : %1\n").arg( weathericon));
//    ui->textEdit->insertPlainText(QString("base : %1\n").arg(weatherbase));

//    ui->textEdit->insertPlainText(QString("humidite: %1\n").arg(mainhum));
//    ui->textEdit->insertPla->inText(QString("tempmin: %1\n").arg(maintempmin));
//    ui->textEdit->insertPlainText(QString("tempmax: %1\n").arg(maintempmax));
}
