#include "museesapi.h"

int MuseesApi::rangMusee = -1 ;

MuseesApi::MuseesApi(ordonnanceur *ord_, QObject *parent)
    : AbstractApi(ord_, parent)
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(parent);

    QString strURL =
            "https://data.culture.gouv.fr/api/records/1.0/search/?dataset=liste-et-localisation-des-musees-de-france&facet=new_regions&facet=nomdep&geofilter.distance="
            + QString::number(latitude)
            + "+%2C+"
            + QString::number(longitude)
            + "%2C+"
            //+ QString::number(radius)
            + "5000"
            + "&rows=100" ;
    QUrl url = QUrl(strURL );

    reply = networkManager->get(QNetworkRequest(url)) ;

    rangMusee ++ ;

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

    if (rangMusee >= musees.size()){
        rangMusee = 0 ;
    }
    QJsonValue musee = musees[rangMusee] ;
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

        CherchePhotos* cherchePhotos1 = new CherchePhotos
                (
                    musee["fields"]["nom_du_musee"].toString() + " " + musee["fields"]["ville"].toString()
                    , 1
                ) ;
        if ( cherchePhotos1->photoExiste() ) {
            QPixmap* photo1 = cherchePhotos1->getPhoto() ;
            double* doublePhoto1 =  reinterpret_cast < double* > (photo1) ;
            QVariant ptr1 =  reinterpret_cast < qint64> (doublePhoto1);
            map_ameliore.insert("photo1",  ptr1 );
        }

        CherchePhotos* cherchePhotos2 = new CherchePhotos
                (
                    musee["fields"]["nom_du_musee"].toString() + " " + musee["fields"]["ville"].toString()
                    , 2
                ) ;
        if ( cherchePhotos2->photoExiste() ) {
            QPixmap* photo2 = cherchePhotos2->getPhoto() ;
            double* doublePhoto2 =  reinterpret_cast < double* > (photo2) ;
            QVariant ptr2 =  reinterpret_cast < qint64> (doublePhoto2);
            map_ameliore.insert("photo2",  ptr2 );
        }

        CherchePhotos* cherchePhotos3 = new CherchePhotos
                (
                    musee["fields"]["nom_du_musee"].toString() + " " + musee["fields"]["ville"].toString()
                    , 3
                ) ;
        if ( cherchePhotos3->photoExiste() ) {
            QPixmap* photo3 = cherchePhotos3->getPhoto() ;
            double* doublePhoto3 =  reinterpret_cast < double* > (photo3) ;
            QVariant ptr3 =  reinterpret_cast < qint64> (doublePhoto3);
            map_ameliore.insert("photo3",  ptr3 );
        }

        CherchePhotos* cherchePhotos4 = new CherchePhotos
                (
                    musee["fields"]["nom_du_musee"].toString() + " " + musee["fields"]["ville"].toString()
                    , 4
                ) ;
        if ( cherchePhotos4->photoExiste() ) {
            QPixmap* photo4 = cherchePhotos4->getPhoto() ;
            double* doublePhoto4 =  reinterpret_cast < double* > (photo4) ;
            QVariant ptr4 =  reinterpret_cast < qint64> (doublePhoto4);
            map_ameliore.insert("photo4",  ptr4 );
        }


        PokeMap *carte = new PokeMap(PokeMap::CINQ_CENT_M);
        //Ajoute les différents points sur la carte
        carte->addPoint("48.871554", "2.346300");
        //Ajoute du texte sur la carte au coordonnées x, y de la pixmap
        //carte->addText(100, 200, "Documentation PokeMap");
        QPixmap photoMap = carte->pixmap() ;
        if ( photoMap.isNull() ) {
            double* doublePhotoMap =  reinterpret_cast < double* > (&photoMap) ;
            QVariant ptrMap =  reinterpret_cast < qint64> (doublePhotoMap);
            map_ameliore.insert("photoMap",  ptrMap );
        }

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



