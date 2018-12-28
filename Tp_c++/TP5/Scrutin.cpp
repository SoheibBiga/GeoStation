#include "Scrutin.hpp"

Scrutin::Scrutin(int nb,int nO):nbBur(nb),nbOpt(nO){
    tab  = new  Urne * [nb];
  for(int i=0;i<nb;i++){
    tab[i] = new Urne(*this,i);
  }
}

Scrutin::~Scrutin(){
  for(int i=0;i<nbBur;i++){
    delete tab[i];
  }
  delete[] tab;
}

int Scrutin::getRes(int choix) const{
  int res=0;
  for(int i=0;i<nbBur;i++){
    res= res+tab[i]->vote[choix];
  }
  return res;
}

void Scrutin::affiche() const{
  for(int i=0;i<nbOpt;i++){
    cout << "choix numero " << i << " : " << getRes(i) << "\n";
  }
}
