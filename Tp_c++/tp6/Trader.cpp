#include "Trader.hpp"

Trader::Trader(int cap):capital(cap){
  tab = new Asset *[20];
  pf =  new Asset *[20];
  for(int i=0;i<20;i++){
    tab[i] = new Asset("lil",currentValue());
    pf[i] = nullptr;
  }
}

boolean::buy(int i){
  if(tab[i]!=nullptr){
    if(tab[i]->price < tab[i]->currentValue()){
      pf[i]=tab[i];
      tab[i]=nullptr;
      return true;
    }  
  }
  return false;
}

boolean::sell(int i){

}




