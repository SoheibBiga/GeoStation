#ifndef ABSTRACTAPI_H
#define ABSTRACTAPI_H

#include <QMap>
#include <QNetworkAccessManager>

class AbstractApi
{

private:
     AbstractApi();

public:
     AbstractApi(int myId);

protected:
    //Correspond au formulaire que l'on veut afficher dans la widget
    //Par exemple si l'on veut afficher dans la widget le titre et l'adresse du musée Grevin à savoir 10 Boulevard Montmartre, 75009 Paris
    //On fera map_formulaire.add("Nom","Musée Grevin") et map_formulaire.add("Adresse","10 Boulevard Montmartre, 75009 Paris"
    QMap<QString, QString> map_formulaire;

    QNetworkAccessManager manager;

    //Associe chaque API à un id, evenement = 0; vegicrue = 1 ...
    enum IdWidget {Evenement,Vegicrue,Avions,Meteo,Pollution,Musee,Pharmacie,BorneElectrique,Satellite,Geolocalisation,Sncf};

    //Il faut initialiser Id lors de l'appel au constructeur en utilisant IdWidget
    int Id;



};
#endif // ABSTRACTAPI_H
