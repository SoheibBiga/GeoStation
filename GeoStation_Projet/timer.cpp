#include "timer.h"
#include "ordonnanceur.h"

Timer::Timer(int Id_,ordonnanceur *ord_) :
    Id(Id_),
    ord(ord_)
{
}

Timer::~Timer()
{}

void Timer::send_request()
{
    switch(Id){
    case IdWidget(Sncf):
        ord->api_index = new SncfApi(ord);
        this->start(180000);
        break;
    case IdWidget(Musee):
        ord->api_index = new MuseesApi(ord);
        this->start(10000);
        break;
    case IdWidget(Satellite):
        ord->api_index = new SatelliteApi(ord);
        this->start(300000);
        break;
    case IdWidget(Evenement):
        ord->api_index = new EvenementApi(ord);
        this->start(180000);
        break;
    case IdWidget(Pollution):
        ord->api_index = new PollutionApi(ord);
        this->start(7200000);
        break;
    case IdWidget(BorneElectrique):
        ord->api_index = new BorneElectriqueApi(ord);
        this->start(10000);
        break;
    case IdWidget(Pharmacie):
        ord->api_index = new PharmacieApi(ord);
        this->start(10000);
        break;
    case IdWidget(Meteo):
        ord->api_index = new MeteoApi(ord);
        this->start(10000);
        break;
    case IdWidget(Vigicrues):
        ord->api_index = new VigicruesApi(ord);
        this->start(600000);
        break;
    case IdWidget(Geolocalisation):
        ord->api_index = new GeolocalisationApi(ord);
        this->start(10000);
        break;
    case IdWidget(Avions):
        ord->api_index = new avionsapi(ord);
        this->start(600000);
        break;
    }
    ord->api_index->loop->exec();
}
