#include "sncfapi.h"

SncfApi::SncfApi(ordonnanceur *ord_, QObject *parent): AbstractApi(ord_, parent)
{
    //Crée les network acces managers
    manager_prochain_depart = new QNetworkAccessManager(parent);

    //Attend la réponse des managers
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(result_liste_gare(QNetworkReply*)));
    connect(manager_prochain_depart, SIGNAL(finished(QNetworkReply*)), this, SLOT(result_prochain_depart(QNetworkReply*)));

    //Lance la requete
    QString position = "geofilter.distance="+QString::number(latitude)+"%2C"+QString::number(longitude)+"%2C"+"10000"; // mettre le radian en parametre
    QString ul_liste_gare = "https://data.sncf.com/api/records/1.0/search/?dataset=liste-des-gares&"+position;
    QUrl url(ul_liste_gare);
    manager->get(QNetworkRequest(url));
}

void SncfApi::result_liste_gare(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError){
        finish(1);
        return;
    }

    QJsonDocument jsdoc;
    jsdoc = QJsonDocument::fromJson(reply->readAll());
    libelle_gare = jsdoc.toVariant().toMap()["records"].toJsonArray().at(0).toVariant().toMap()["fields"].toMap()["libelle_gare"].toString();
    code_uic_gare = jsdoc.toVariant().toMap()["records"].toJsonArray().at(0).toVariant().toMap()["fields"].toMap()["code_uic"].toString();
    QString token_sncf = "b9b428ee-3f1c-4c4e-82c0-6448e4c99ed7";
    QString ul_prochain_depart = "https://"+token_sncf+"@api.sncf.com/v1/coverage/sncf/stop_areas/stop_area:OCE:SA:"+code_uic_gare+"/departures?datetime=20181212T174530";
    QUrl url(ul_prochain_depart);
    manager_prochain_depart->get(QNetworkRequest(url));
}


void SncfApi::result_prochain_depart(QNetworkReply* reply)
{
    QJsonDocument jsdoc;
    jsdoc = QJsonDocument::fromJson(reply->readAll());
    int total_result = jsdoc.toVariant().toMap()["pagination"].toMap()["total_result"].toInt();
    if(total_result == 0){
        finish(0);
    }
    else{
        int i = 0;
        QString direction;
        QString commercial_mode;
        QString code;
        QString ligne;
        QString affiche;
        QString date;
        QString lat_gare;
        QString long_gare;
        lat_gare = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(0).toObject().toVariantMap()["stop_point"].toMap()["coord"].toMap()["lat"].toString();
        long_gare = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(0).toObject().toVariantMap()["stop_point"].toMap()["coord"].toMap()["lon"].toString();
        //QString heure, minute;
        //QString string_color;
        add_coord(lat_gare,long_gare);
        QMap<QString,QVariant> element;

        //Rajoute un titre dans parametre
        add_titre("Prochains Train au depart de " + libelle_gare );
        //Rajoute le nombre d'element dans parametre
        add_nb_entree(total_result);

        for(i = 0; i < total_result ; i++){
            direction = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(i).toObject().toVariantMap()["display_informations"].toMap()["direction"].toString();
            commercial_mode = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(i).toObject().toVariantMap()["display_informations"].toMap()["commercial_mode"].toString();
            code = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(i).toObject().toVariantMap()["display_informations"].toMap()["code"].toString();
            if(code == "" ) code = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(i).toObject().toVariantMap()["display_informations"].toMap()["headsign"].toString();
            ligne = commercial_mode+ " " + code;
            date = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(i).toObject().toVariantMap()["stop_date_time"].toMap()["departure_date_time"].toString();
            affiche = ligne+" "+date[9]+date[10]+"H"+date[11]+date[12]+" Direction "+direction+"\n";
            date = ""+date[9]+date[10]+"H"+date[11]+date[12];

            //Insert dans element une cle/valeur
            element.insert("Direction",QVariant(direction));
            element.insert("Ligne",QVariant(ligne));
            element.insert("Date",QVariant(date));
            //element.insert()
            //Ajoute l'element dans tableau (correspond au i-eme element)
            add_list(element);
            //QString string_color = jsdoc.toVariant().toMap()["departures"].toJsonArray().at(i).toObject().toVariantMap()["display_informations"].toMap()["color"].toString();
            //QColor color_ligne("#"+string_color);
        }
        //Insert tableau dans map_ameliore
        map_ameliore.insert("Tableau",QVariant(tableau));
        //Insert parametre map_amelioe
        map_ameliore.insert("Parametre",QVariant(parametre));
        //Envoi l'information vers l'ordonnancer
        emit sncf_send_info2(map_ameliore);
        //Fin des requêtes (=perte de la main)
        finish(0);
    }
}

SncfApi::~SncfApi()
{
    delete manager_prochain_depart;
}
