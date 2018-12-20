#include "museesapi.h"

MuseesApi::MuseesApi(ordonnanceur *ord_, QObject *parent)
    : AbstractApi(IdWidget(Musee), ord_, parent)
{
    //Crée le network acces manager
    networkManager = new QNetworkAccessManager(parent);

}

bool MuseesApi::isMap(){
    return true;
}
