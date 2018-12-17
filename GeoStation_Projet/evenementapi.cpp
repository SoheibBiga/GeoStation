#include "evenementapi.h"


EvenementApi::EvenementApi(QObject *parent): AbstractApi(IdWidget(Sncf),parent)
{
  //manager
  manager = new QNetworkAccessManager (parent);


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
    qDebug()<< "reponseRecue";
    m_reply={rep};

    QByteArray m_response = rep->readAll();
    qDebug()<< "bytearry" << m_response.isEmpty() <<endl;

    Myjson = QJsonDocument::fromJson(m_response);
    qDebug() << "mon json" << Myjson.isEmpty() <<endl;

    QString strJson(Myjson.toJson(QJsonDocument::Compact)); // Indented or Compact
    qDebug() << "strJson" << strJson.isEmpty() <<endl;

    //ui->textEdit->append(strJson);

    int i;

    int count = Myjson.object().toVariantMap()["records"].toJsonArray().count();

    //ui->textEdit->clear();

    for (i = 0; i < count; i++)
        {

           QString nhits = Myjson.object().toVariantMap()["nhits"].toString();
           qDebug()<< "afficher nhits : nbr d'événement" << nhits <<endl;

           qDebug()<< "title de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["title"]<<endl;
           QString Titre = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["title"].toString();

           qDebug()<< "address de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["address"]<<endl;
           QString Address = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["address"].toString();

           qDebug()<< "space time info de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["space_time_info"]<<endl;
           QString Space_time_info = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["space_time_info"].toString();

           qDebug()<< "tarif de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["pricing_info"]<<endl;
           QString Tarif = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["princing_info"].toString();

           qDebug()<< "image de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["image"]<<endl;
           QString Image = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["image"].toString();

           //ui->textEdit->append ("énvénement => \n" + nhits + "\n" + "Titre => \n"+  title + "\n" + "Addresse => \n"+ address + " \n" + "Date => \n" + space_time_info + " \n" + "Tarif => \n" + pricing_info + "\n " + "Image => \n" + image + "\n");
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
