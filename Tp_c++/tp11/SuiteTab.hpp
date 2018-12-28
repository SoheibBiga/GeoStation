#ifndef SUITETAB
#define SUITETAB
#include "Suite.hpp"
#include <string>
#include <iostream>
using namespace std;

template <class T> class SuiteTab : public  Suite<T> {
public :
  SuiteTab(int taille): max(taille),length(0){
    tab = new T[taille];
  }
  int taille();
  void ajoute(T t);
  void affiche();
  T *tab;
  int max;
  int length;
};
#endif
