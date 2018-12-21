#ifndef APISNCF_H
#define APISNCF_H

#include "abstractapi.h"

class SncfApi : public AbstractApi
{
    Q_OBJECT

public:
    SncfApi(ordonnanceur *ord_, QObject *parent = 0);
    ~SncfApi();

private:
    QNetworkAccessManager *manager_prochain_depart;
    QString code_uic_gare;
    qint64 t1;
    qint64 t2;
    QString libelle_gare;

private slots:
    void result_liste_gare(QNetworkReply *reply);
    void result_prochain_depart(QNetworkReply* reply);

};

#endif // APISNCF_H


//Taille de la mainwindow quand elle s'ouvre
//Tout le monde doit faire au moins sa mozaic
//Mourad carte ?
//Gary base de donnée ?
//Charles graphs ?
// geolocalisation timer ? appelé combien de fois dans une vie ?
