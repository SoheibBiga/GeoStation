#include "Asset.hpp"

int Asset::getPrice(){
  return price;
}

string Asset::getName(){
  return name;
}

int Asset::currentValue(){
  int nb = rand()%30;
  return nb;
}


