#include "cherchephotos.h"

// Le mode d'emploi de la classe se trouve dans cherchephotos.h

CherchePhotos::CherchePhotos(QString texteRecherche, int combientieme/*, ordonnanceur *ord_, QObject *parent*/)
    : /*AbstractApi(IdWidget(Photo), ord_, parent)
    , */texteRecherche(texteRecherche)
    , combientieme(combientieme)
{
    manager_json = new QNetworkAccessManager(/*this*/);

    //url_json = QUrl("https://serpapi.com/search?q=" + texteRecherche + "&tbm=isch");
    //QString strURL = "https://api.qwant.com/egp/search/images?q=" + texteRecherche + "&start=" + QString::number(combientieme) ;
    url_json = QUrl("https://api.qwant.com/egp/search/images?q=" + texteRecherche + "&start=" + QString::number(combientieme - 1));

    do {
        reply_json = manager_json->get(QNetworkRequest(url_json)) ;
        connect(
                    reply_json,
                    &QIODevice::readyRead,
                    this,
                    &CherchePhotos::jsonRead
               );

        connect(
                    manager_json,
                    SIGNAL(finished(QNetworkReply*)),
                    this,
                    SLOT(jsonFinished(QNetworkReply*))
                );
        loop_json.exec() ;
    } while ( ! jsonOK ) ;

}

void CherchePhotos::jsonFinished(QNetworkReply* )
{
    trtReceptionJSON() ;
    images = (
                QJsonDocument::fromJson(data_json)
                    .object() ["data"]
             )
                    .toObject() ["result"]
                        .toObject() ["items"] ;

    manager_photo = new QNetworkAccessManager(/*this*/);
    //QString strUrl = images[0]["media"].toString() ;
    QString strUrl = images[combientieme-1]["media"].toString() ;
    loop_json.exit() ;

    if ( strUrl.isEmpty() ) {
        jsonOK = false ;
    }
    else {
        jsonOK = true ;
        nbrImages = images.toArray().count() ;
        int i = 0 ;

        do {
            url_photo = QUrl(strUrl);
            QNetworkRequest request_photo( url_photo) ;
            manager_photo->get(request_photo) ;

            connect(
                        manager_photo,
                        SIGNAL(finished(QNetworkReply*)),
                        this,
                        SLOT(photoFinished(QNetworkReply*))
                    );

            i++ ;
            strUrl = images[i]["media"].toString() ;

            loop_photo.exec() ;
        } while ( i < nbrImages && ! photoChargee ) ;

    }

}

void CherchePhotos::photoFinished(QNetworkReply* reply_photo)
{

    if (reply_photo->error() != QNetworkReply::NoError) {
        //qDebug() << "Error in" << reply_photo->url() << ":" << reply_photo->errorString();
        photoChargee = false ;
    } else {
        data_photo = reply_photo->readAll();
        photo = new QPixmap () ;
        photo ->loadFromData(data_photo);
        photoChargee = true ;
    }

    loop_photo.exit() ;

}


void CherchePhotos::jsonRead()
{
    trtReceptionJSON() ;
}



bool CherchePhotos::chargementPhotoFini()
{
    return photoChargee ;
}

void CherchePhotos::trtReceptionJSON()
{
    data_json . append (reply_json->readAll());
}

QPixmap* CherchePhotos::getPhoto()
{
    return photo ;
}



bool CherchePhotos::photoExiste()
{
    return ! photo->isNull() ;
}




/*bool CherchePhotos::isMap(){
    return true;
}*/
