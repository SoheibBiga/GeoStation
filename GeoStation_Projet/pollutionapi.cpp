#include "pollutionapi.h"

PollutionApi::PollutionApi(ordonnanceur *ord_, QObject *parent) : AbstractApi(IdWidget(Pollution), ord_, parent)
{
    manager = new QNetworkAccessManager(parent);

    manager->get(QNetworkRequest(QUrl("https://api.waqi.info/feed/geo:48.866667;2.333333/?token=1427ed34fa11aff3521e1967be850e08e1df97cb")));

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
}


void PollutionApi::replyFinished(QNetworkReply *Reply)
{
    //    qDebug() << "Response ...";
    if(Reply->isOpen()){
        QJsonDocument jsonResponse = QJsonDocument::fromJson(Reply->readAll());
        qDebug() << jsonResponse.isObject();  //true
        /*1 aqi*/
        //        qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["aqi"].toString();

        //        /*2 city lati et lon*/
        //        //qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["city"].toJsonObject().toVariantMap()["geo"].toJsonArray().at(0).toDouble();
        //        //qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["city"].toJsonObject().toVariantMap()["geo"].toJsonArray().at(1).toDouble();

        //        /*3 place */
        //        qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["city"].toJsonObject().toVariantMap()["name"].toString();

        //        /*2 dominentpol*/
        //        qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["dominentpol"].toString();



        /*time*/
        //        qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["time"].toJsonObject().toVariantHash()["s"].toString();
        //        qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["time"].toJsonObject().toVariantHash()["tz"].toString();
        //        qDebug() << jsonResponse.object().toVariantMap()["data"].toMap()["time"].toJsonObject().toVariantHash()["v"].toInt();

        Reply->close();


        /*end of timer*/
        qiTimestamp2 =QDateTime::currentMSecsSinceEpoch();

        //int temps = qiTimestamp2 - qiTimestamp1;

        //        qDebug() << qiTimestamp1;
        //        qDebug() << qiTimestamp2;

        //        qDebug() << "Time takes to load :" << temps;

    }

}
