#include "museesapi.h"

MuseesApi::MuseesApi(ordonnanceur *ord_, QObject *parent)
    : AbstractApi(IdWidget(Musee), ord_, parent)
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(parent);

    QString strURL =
            "https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&geofilter.distance="
            + QString::number(latitude)
            + "+%2C+"
            + QString::number(longitude)
            + "%2C+"
            + QString::number(radius)
            + "&rows=100" ;
    QUrl url = QUrl(strURL );

    reply = networkManager->get(QNetworkRequest(url)) ;

    connect(
                reply,
                &QIODevice::readyRead,
                this,
                &MuseesApi::onReadyRead
           );

    connect(
                networkManager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(onFinished(QNetworkReply*))
            );
}


/*MuseesApi::~MuseesApi()
{
}*/

void MuseesApi::onFinished(QNetworkReply* )
{
    if (reply->error() != QNetworkReply::NoError){
        finish(1);
        return;  // ...only in a blog post
    }

    trtReceptionDonnees() ;


    //QJsonParseError *error ;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data/*, error*/);

    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray musees = jsonObject["records"].toArray() ;
    QString labelAdresse ;

    QJsonValue musee = musees[0] ;
    // On ne traite que les musées dont le nom apparaît dans le JSON
    if ( ! musee["fields"]["nom_du_musee"].isNull()
    &&   ! musee["fields"]["nom_du_musee"].isUndefined()) {

        map_ameliore.insert("nom_du_musee",musee["fields"]["nom_du_musee"]. toString());


        if ( ! musee["fields"]["adr"].isNull()
        &&   ! musee["fields"]["adr"].isUndefined()
        &&   ! musee["fields"]["ville"].isNull()
        &&   ! musee["fields"]["ville"].isUndefined()  ) {
            labelAdresse =
                    musee["fields"]["adr"]. toString()
                    + "\n"
                    + musee["fields"]["ville"]. toString() ;
            map_ameliore.insert("adresse",labelAdresse);
        }
        if ( ! musee["fields"]["periode_ouverture"].isNull()
        &&   ! musee["fields"]["periode_ouverture"].isUndefined()) {
            map_ameliore.insert("horaires",musee["fields"]["periode_ouverture"].toString());
        }
        if ( ! musee["fields"]["fermeture_annuelle"].isNull()
        &&   ! musee["fields"]["fermeture_annuelle"].isUndefined()) {
            map_ameliore.insert("fermeture",musee["fields"]["fermeture_annuelle"].toString());
        }
        if ( ! musee["fields"]["jours_nocturnes"].isNull()
        &&   ! musee["fields"]["jours_nocturnes"].isUndefined()) {
            map_ameliore.insert("nocturnes",musee["fields"]["jours_nocturnes"].toString());
        }

        CherchePhotos* cherchePhotos = new CherchePhotos
                (
                    musee["fields"]["nom_du_musee"].toString() + " " + musee["fields"]["ville"].toString()
                    , 1
                ) ;
        QPixmap* photo = cherchePhotos->getPhoto() ;
        double doublePhoto =  * (double*) photo ;
        //map_ameliore.insert("photo",* (cherchePhotos->getPhoto()) );
        map_ameliore.insert("photo",  doublePhoto );
        emit musee_send_info2(map_ameliore);
        finish(0);

    }
}


void MuseesApi::onReadyRead()
{
    trtReceptionDonnees() ;
}


void MuseesApi::trtReceptionDonnees()
{

    response_data . append (reply->readAll());
}



