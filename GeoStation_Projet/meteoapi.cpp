#include "meteoapi.h"
#include <QDate>

MeteoApi::MeteoApi(ordonnanceur *ord_, QObject* parent) : AbstractApi( ord_, parent)
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

}

MeteoApi::~MeteoApi()
{

}



void MeteoApi::Read(QNetworkReply *reply)

{
    QByteArray ba=reply->readAll();
    //ui->textEdit->setPlainText(ba);
    QJsonDocument doc = QJsonDocument::fromJson(ba);


   // double weatherid=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["id"].toDouble();
   // QString weathermain=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["main"].toString();
    QString weatherdescription=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["description"].toString();
   // QString weathericon=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["icon"].toString();


  //  QString weatherbase=doc.toVariant().toHash()["weather"].toList().at(0).toMap()["base"].toString();
    double mainhum=doc.toVariant().toHash()["main"].toHash()["humidity"].toDouble();
    double maintempmin=doc.toVariant().toHash()["main"].toHash()["temp_min"].toDouble();
    double maintempmax=doc.toVariant().toHash()["main"].toHash()["temp_max"].toDouble();
    double pressure=doc.toVariant().toHash()["main"].toHash()["pressure"].toDouble();

    add_titre("Meteo du jour");
    QMap<QString,QVariant> element;
    element.insert("Temperature Maximale",QVariant(maintempmax));
    element.insert("Temperature Minimale", QVariant(maintempmin));
    element.insert("Temps", QVariant(weatherdescription));
    element.insert("Humidite", QVariant(mainhum));
    element.insert("Pression", QVariant(pressure));


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

}




