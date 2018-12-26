#include "pollutionapi.h"

PollutionApi::PollutionApi(ordonnanceur *ord_, QObject *parent) : AbstractApi(ord_, parent)
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
        //qDebug() << jsonResponse.isObject();  //true

        add_titre("Pollution du jour");


        QString aqi = jsonResponse.object().toVariantMap()["data"].toMap()["aqi"].toString();
        int n = aqi.toInt();

        QMap<QString,QVariant> element;
        element.insert("AQI",QVariant(n));
        add_list(element);
        map_ameliore.insert("Tableau",QVariant(tableau));
        map_ameliore.insert("Parametre",QVariant(parametre));

        emit pollution_send_info2(map_ameliore);
        finish(0);

        Reply->close();

    }

}
