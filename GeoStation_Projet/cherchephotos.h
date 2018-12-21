#ifndef CHERCHEPHOTOS_H
#define CHERCHEPHOTOS_H

/*
 * La classe CherchePhotos permet de récupérer des photos à partir d'un thème de recherche
 *
 * Par exemple, si on souhaite récupérer la 3ème photo renvoyée par Qwant (moteur de recherches)
 * sur le thème "Musée du Louvre", on écrit le code suivant :
 *
 * CherchePhotos* cherchePhotos = new CherchePhotos("Musée du Louvre", 3) ;
 * QPixmap photoPixmap = * ( cherchePhotos->getPhoto() );
 *  ... Vous faites ce que vous voulez de photoPixmap
 *  ... Quand vous n'en avez plus besoin, pensez à effacer l'objet pour éviter les fuites mémoire :
 * delete cherchePhotos ;
 *
 * Contacter Marc pour tout renseignement
 */

#include <QString>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPixmap>
#include <QEventLoop>
#include <QDebug>

#include "abstractapi.h"

class CherchePhotos : public AbstractApi
{
    Q_OBJECT

public:
    CherchePhotos(QString, int, ordonnanceur *ord_, QObject *parent = 0);
    QPixmap* getPhoto() ;
    bool chargementPhotoFini() ;

private:
    QString texteRecherche ;
    int combientieme ;
    QNetworkAccessManager* manager_json ;
    QNetworkAccessManager* manager_photo ;
    QUrl url_json ;
    QUrl url_photo ;
    QNetworkReply* reply_json ;
    QNetworkReply* reply_photo ;
    QNetworkRequest* request_photo ;
    QByteArray data_json ;
    QByteArray data_photo ;
    QJsonValue images ;
    void trtReceptionJSON () ;
    void trtReceptionPhoto () ;
    QPixmap* photo ;
    QEventLoop loop_json;
    QEventLoop loop_photo;
    bool photoChargee = false ;
    bool jsonOK ;
    int nbrImages ;

private slots:
    void jsonFinished(QNetworkReply*);
    void jsonRead();
    void photoFinished(QNetworkReply*);
};

#endif // CHERCHEPHOTOS_H
