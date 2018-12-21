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

private:
    //Vous ne pouvez pas utiliser ce constructeur
    AbstractApi(QObject *parent);

    ordonnanceur *ord;

public:
    //Lie l'objet à parent, initialise l'attribut id à myId
    //AbstractApi(QObject *parent, int myId, QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");
    explicit AbstractApi(int myId, ordonnanceur *ord_, QObject *parent = 0,QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");

    //explicit AbstractApi(int myId, QObject *parent = 0, QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");

    //Il faut initialiser Id lors de l'appel au constructeur en utilisant IdWidget
    int Id;

    //Permet d'attendre la réponse des requêtes
    QEventLoop *loop;

    //Correspond au formulaire que l'on veut afficher dans la widget
    //Par exemple si l'on veut afficher dans la widget le titre et l'adresse du musée Grevin à savoir 10 Boulevard Montmartre, 75009 Paris
    //On fera map_formulaire.insert("Nom","Musée Grevin") et map_formulaire.insert("Adresse","10 Boulevard Montmartre, 75009 Paris"
    QMap<QString, QString> map_formulaire;
    QMap<QString,QVariant> map_ameliore;


protected:

    double longitude;
    double latitude;
    double radius;

    QNetworkAccessManager *manager;

    QList<QVariant> tableau;
    QMap<QString, QVariant> parametre;

    //A utiliser lorsque l'ensemble des requêtes de notre api on été recuperer et enregistrer dans map_formulaire
    void finish(bool work);

    //Ajoute un element dans la liste de map_ameliore
    void add_list(QMap<QString,QVariant> element);
    //Ajoute un titre dans les parametres de map_ameliore
    void add_titre(QString titre);
    //Ajoute le nombre d'entrée dans les parametres de map_ameliore
    void add_nb_entree(int nb_entree);

signals:
    void send_info(QMap<QString, QString>);
    void send_info2(QMap<QString, QVariant>);
};
#endif // ABSTRACTAPI_H
