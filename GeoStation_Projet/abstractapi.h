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


//Associe chaque API à un id, evenement = 0; vegicrue = 1 ...
enum IdWidget {Evenement,Vigicrues,Avions,Meteo,Pollution,Musee,Pharmacie,BorneElectrique,Satellite,Geolocalisation,Sncf};

class AbstractApi : public QObject
{

private:
    //Vous ne pouvez pas utiliser ce constructeur
    AbstractApi(QObject *parent);

public:
    //Lie l'objet à parent, initialise l'attribut id à myId
    AbstractApi(QObject *parent, int myId, QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");
    explicit AbstractApi(int myId,QObject *parent = 0,QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");

    //explicit AbstractApi(int myId, QObject *parent = 0, QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");

    //Il faut initialiser Id lors de l'appel au constructeur en utilisant IdWidget
    int Id;

    //Permet d'attendre la réponse des requêtes
    QEventLoop *loop;

    //Correspond au formulaire que l'on veut afficher dans la widget
    //Par exemple si l'on veut afficher dans la widget le titre et l'adresse du musée Grevin à savoir 10 Boulevard Montmartre, 75009 Paris
    //On fera map_formulaire.insert("Nom","Musée Grevin") et map_formulaire.insert("Adresse","10 Boulevard Montmartre, 75009 Paris"
    QMap<QString, QString> *map_formulaire;

    //return s'il y a la présence d'une map ou non dans la widget
    virtual bool isMap() = 0;

    //return si votre classe possède en mode plein écran
    //Tout le monde posède un mode mosaique
    //bool hasBigLayout();


protected:

    double longitude;
    double latitude;
    double radius;

    QNetworkAccessManager *manager;

    //A utiliser lorsque l'ensemble des requêtes de notre api on été recuperer et enregistrer dans map_formulaire
    void finish(bool work);
};
#endif // ABSTRACTAPI_H
