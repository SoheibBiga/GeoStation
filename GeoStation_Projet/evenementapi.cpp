#include "evenementapi.h"

EvenementApi::EvenementApi(ordonnanceur *ord_,QObject *parent): AbstractApi(IdWidget(Evenement),ord_,parent)
{
    //manager
    manager = new QNetworkAccessManager (parent);
    QNetworkReply *m_reply;
    QNetworkRequest m_request;


    latitude = 50.8550625;
    longitude = 4.3053505;
    radius = 5000;

    QString req("https://public.opendatasoft.com/api/records/1.0/search/?dataset=evenements-publics-cibul&rows=20&sort=date_start&facet=tags&facet=placename&facet=department&facet=region&facet=city&facet=date_start&facet=date_end&facet=pricing_info&facet=updated_at&facet=city_district&geofilter.distance="+QString::number(latitude)+"%2C+"+QString::number(longitude)+"%2C+"+QString::number(radius));
    //qDebug()<<req;
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

    int total_event = Myjson.object().toVariantMap()["nhits"].toInt();
    qDebug()<< total_event;

    if(total_event == 0)
    {

    }

    else

    {

        QMap<QString,QVariant> element;
        //QString city = Myjson.object().toVariantMap()["records"].toJsonArray().["fields"]["date_start"].toString();
        QString city = Myjson.toVariant().toMap()["records"].toJsonArray().at(0).toVariant().toMap()["fields"].toMap()["city"].toString();

        //add_titre("Evenement " + city );
        //add_nb_entree(total_event);

        int i;
        int count = Myjson.object().toVariantMap()["records"].toJsonArray().count();
        for (i = 0; i < count; i++)
        {

            QDate MyDate = QDate::currentDate();
            QString date_start = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["date_start"].toString();
            QDate datestart = QDate::fromString(date_start, "yyyy'-'MM'-'dd");
            QDate datenew = MyDate.addDays(15);
            QString title;
            QString description;
            QString address;
            QString space_time_info;
            QString pricing_info;

            if (datestart >= MyDate && datestart <= datenew)
            {
                //qDebug()<< "title de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["title"]<<endl;
                title= Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["title"].toString();

                //qDebug()<< "description de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["description"]<<endl;
                description = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["description"].toString();

                //qDebug()<< "address de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["address"]<<endl;
                address = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["address"].toString();

                //qDebug()<< "space time info de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["space_time_info"]<<endl;
                space_time_info = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["space_time_info"].toString();

                //qDebug()<< "tarif de record: " << i << "=>" << Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["pricing_info"]<<endl;
                pricing_info = Myjson.object().toVariantMap()["records"].toJsonArray().at(i)["fields"]["princing_info"].toString();

            }

//            element.insert("Titre",QVariant(title));
//            element.insert("Description",QVariant(description));
//            element.insert("Adresse",QVariant(address));
//            element.insert("Date",QVariant(space_time_info));
//            element.insert("Tarif",QVariant(pricing_info));
//            add_list(element);

        }
//        map_ameliore.insert("Tableau",QVariant(tableau));
//        map_ameliore.insert("Titre",QVariant(parametre));
       // emit send_info2(map_ameliore);
        finish(0);
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
