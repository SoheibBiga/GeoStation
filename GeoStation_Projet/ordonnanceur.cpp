#include "ordonnanceur.h"

ordonnanceur::ordonnanceur(QObject *parent) : QObject(parent)
{
    AbstractApi *api_index;
   // api_index = new SncfApi(parent);
    switch(api_index->Id){
    case IdWidget(Sncf):
        api_index = new SncfApi(parent);
    /*case IdWidget(Evenement):
        api_index = new EvenementApi(parent);
    case IdWidget(Pollution):
        api_index = new PollutionApi(parent);
    case IdWidget(BorneElectrique):
        api_index = new BorneElectriqueApi(parent);
    case IdWidget(Pharmacie):
        api_index = new PharmacieApi(parent);
    case IdWidget(Satellite):
        api_index = new SatelliteApi(parent);*/
    /*case IdWidget(Meteo):
        api_index = new MeteoApi(parent);
    case IdWidget(Vigicrues):
        api_index = new VigicruesApi(parent);
    case IdWidget(Musee):
        api_index = new MuseeApi();
    case IdWidget(Geolocalisation):
        api_index = new GeolocalisationApi();
    case IdWidget():
        api_index = new Evenement();*/
    }
    api_index->loop->exec();

    //SncfApi *soh = new SncfApi();
    //SncfApi *soh = new SncfApi();
    //soh->loop->exec();
    //
    //QList<AbstractApi*> liste_api;
    //switch(i)
    //SncfApi *sncf_api = new SncfApi(api_index->Sncf);
    /*QList<AbstractApi*> liste_api;
        SncfApi *ev;
        liste_api <<ev;
        AbstractApi *ptr=new lliste_api[0];*/
    //api_index =1
    /*SatelliteApi *satellite_api;
        BorneElectriqueApi *borne_electrique_api;
        MuseeApi *musee_api;
        AvionApi *avion_api;
        GeolocalisationApi *geolocalisation_api;
        PharmacieApi *pharmacie_api;
        pharmacie_api = new PharmacieApi(this,pharmacie_api->Id);
        MeteoApi *meteo_api;
        PollutionApi *pollution_api;
        EvenementApi *evenement_api;
        evenement_api = new EvenementApi(this,evenement_api->Id);
        VegicrueApi *vegicrue_api;
        pollution_api=new PollutionApi(this,pollution_api->Id);
        liste_api.append(sncf_api);
        liste_api.append(satellite_api);
        liste_api.append(borne_electrique_api);
        liste_api.append(musee_api);
        liste_api.append(avion_api);
        liste_api.append(geolocalisation_api);
        liste_api.append(pharmacie_api);*/

    //liste_api.append(meteo_api);

    //liste_api.append(meteo_api);

    //liste_api.append(pollution_api);
    //liste_api.append(evenement_api);
    //liste_api.append(vegicrue_api);
}
