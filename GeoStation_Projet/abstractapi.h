#ifndef ABSTRACTAPI_H
#define ABSTRACTAPI_H

#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSettings>
#include <QDebug>
#include <QEventLoop>
#include <QList>

class ordonnanceur;


//Associe chaque API à un id, evenement = 0; vegicrue = 1 ...
enum IdWidget {Sncf,Satellite,Evenement,Vigicrues,Avions,Meteo,Pollution,Musee,Pharmacie,BorneElectrique,Geolocalisation,Photo};

class AbstractApi : public QObject
{

    Q_OBJECT


    AbstractApi();
    AbstractApi(AbstractApi const& other);
    AbstractApi& operator=(AbstractApi const& other);


    ordonnanceur *ord;

public:
    //Lie l'objet à parent, initialise l'attribut id à myId
    explicit AbstractApi(ordonnanceur *ord_, QObject *parent = 0,QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");
    virtual ~AbstractApi();


    //Permet d'attendre la réponse des requêtes
    QEventLoop *loop;

    //Voir SncfApi dans result_prochain_depart(QNetworkReply* reply)
    QMap<QString,QVariant> map_ameliore;


protected:

    double longitude;
    double latitude;
    // le rayon est en mètres
    double radius;

    QNetworkAccessManager *manager;

    QList<QVariant> tableau;
    QMap<QString, QVariant> parametre;

    //A utiliser lorsque l'ensemble des requêtes de notre api on été recuperer et enregistrer dans map_formulaire
    void finish(bool error);

    //Ajoute un element dans la liste de map_ameliore
    void add_list(QMap<QString,QVariant> element);
    //Ajoute un titre dans les parametres de map_ameliore
    void add_titre(QString titre);
    //Ajoute le nombre d'entrée dans les parametres de map_ameliore
    void add_nb_entree(int nb_entree);

signals:
    void send_info(QMap<QString, QString>);
    void sncf_send_info2(QMap<QString, QVariant>);
    void pollution_send_info2(QMap<QString, QVariant>);
    void meteo_send_info2(QMap<QString, QVariant>);
    void pharmacie_send_info2(QMap<QString, QVariant>);
    void musee_send_info2(QMap<QString, QVariant>);
    void vigicrues_send_info(QMap<QString, QString>);
    void geolocalisation_send_info2(QMap<QString, QVariant>);
    void borneelectrique_send_info2(QMap<QString, QVariant>);
    void avions_send_info2(QMap<QString, QVariant>);
    void evenement_send_info2(QMap<QString, QVariant>);
    void satellite_send_info2(QMap<QString, QVariant>);
};
#endif // ABSTRACTAPI_H
