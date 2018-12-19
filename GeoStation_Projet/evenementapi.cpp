#include "evenementapi.h"


EvenementApi::EvenementApi(ordonnanceur *ord_,QObject *parent): AbstractApi(IdWidget(Evenement),ord_,parent)
{
  //manager
  manager = new QNetworkAccessManager (parent);
  QNetworkReply *m_reply;
  QNetworkRequest m_request;
  map_formulaire = new QMap<QString, QString>;


  latitude = 50.8550625;
  longitude = 4.3053505;
  radius = 5000;

  QString req("https://public.opendatasoft.com/api/records/1.0/search/?dataset=evenements-publics-cibul&sort=date_start&facet=tags&facet=placename&facet=department&facet=region&facet=city&facet=date_start&facet=date_end&facet=pricing_info&facet=updated_at&facet=city_district&geofilter.distance="+QString::number(latitude)+"%2C+"+QString::number(longitude)+"%2C+"+QString::number(radius));
  qDebug()<<req;
  m_request.setUrl(QUrl(req));
  m_reply = manager->get(m_request);

  m_request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
  connect(m_reply,SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
  connect(m_reply,SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
  connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseRecue(QNetworkReply *)));


}

EvenementApi::~EvenementApi()
{

}

void EvenementApi::reponseRecue(QNetworkReply *rep)
{

    QByteArray m_response = rep->readAll();

    QJsonDocument Myjson;
    Myjson = QJsonDocument::fromJson(m_response);

    QString strJson(Myjson.toJson(QJsonDocument::Compact)); // Indented or Compact

    int i;

    int count = Myjson.object().toVariantMap()["records"].toJsonArray().count();

    for (i = 0; i < count; i++)
      {

        //qDebug()<< "title de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["title"]<<endl;
        QString title = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["title"].toString();
        map_formulaire->insert("Title", title);

        //qDebug()<< "description de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["description"]<<endl;
        QString description = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["description"].toString();
        map_formulaire->insert("Description", description);

        //qDebug()<< "address de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["address"]<<endl;
        QString address = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["address"].toString();
        map_formulaire->insert("Adresse", address);

        //qDebug()<< "space time info de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["space_time_info"]<<endl;
        QString space_time_info = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["space_time_info"].toString();
        map_formulaire->insert("Lieu_Date_Heure", space_time_info);

        //qDebug()<< "tarif de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["pricing_info"]<<endl;
        QString pricing_info = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["princing_info"].toString();
        map_formulaire->insert("Tarif", pricing_info);



     }
}

//gérer les erreurs

void EvenementApi::slotError(QNetworkReply::NetworkError erreurtype)
{
    QString m_message;
    if (erreurtype == QNetworkReply::NoError) { return; }
    else { m_message = QString("Erreur"); }
    qDebug()<< "Erreur";
}

void EvenementApi::slotSslErrors(QList<QSslError>)
{
     qDebug()<< "slotSslErrors";
}


bool EvenementApi::isMap(){
    return true;
}
bool EvenementApi::hasBigLayout(){
    return true;
}
