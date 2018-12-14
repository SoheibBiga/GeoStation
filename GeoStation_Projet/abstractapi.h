#ifndef ABSTRACTAPI_H
#define ABSTRACTAPI_H

#include <QMap>
#include <QNetworkAccessManager>

class AbstractApi
{

private:
     AbstractApi();
protected:
    //Correspond au formulaire que l'on veut afficher dans la widget
    //Par exemple si l'on veut afficher dans la widget le titre et l'adresse du musée Grevin à savoir 10 Boulevard Montmartre, 75009 Paris
    //On fera map_formulaire.add("Nom","Musée Grevin") et map_formulaire.add("Adresse","10 Boulevard Montmartre, 75009 Paris"
    QMap<QString, QString> map_formulaire;
    QNetworkAccessManager manager;
    enum IdWidget {Evenement,Vegicrue,Avions,Meteo,Pollution,Musee,Pharmacie,BorneElectrique,Satellite,Geolocalisation,Sncf};

    //Doit retourner votre IdWidget
    //Par
    virtual IdWidget getIdWidget() = 0;



};
#endif // ABSTRACTAPI_H
