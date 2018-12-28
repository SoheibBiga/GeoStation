#include <iostream>
#include "Urne.hpp"
#ifndef SCRUTIN
#define SCRUTIN
using namespace std;

class Scrutin{
public :
  Scrutin(int nb,int nO);
  const int nbBur;
  const int nbOpt;
  Urne ** tab;
  int getRes(int choix) const;
  void affiche() const;
  ~Scrutin();
};
#endif
