#include "Urne.hpp"
#include "Scrutin.hpp"
#include <iostream>

using namespace std;

Urne::Urne(Scrutin& s,int n):scrut(s),nbv(n),vote(new int[scrut.nbOpt]){}

bool Urne::voter(int choix){
  if(choix >= scrut.nbOpt)
    return false;
  else{
    vote[choix]++;
    return true;
  }
}
Urne::~Urne(){
  if(vote)
    delete[] vote;
}

int Urne::getRes(int choix) const{
  return vote[choix-1];
}
void Urne::affiche() const{
  for(int i=0;i<scrut.nbOpt;i++){
    cout << "choix numero " << i << " : " << getRes(i) << "\n";
  }
}
