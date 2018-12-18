#include "nullapi.h"

nullapi::nullapi(ordonnanceur *ord_, QObject *parent): AbstractApi(IdWidget(Sncf), ord_, parent)
{

}

bool nullapi::isMap(){
    return false;
}

bool nullapi::hasBigLayout(){
    return false;
}
