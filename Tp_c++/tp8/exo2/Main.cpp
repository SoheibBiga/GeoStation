#include "ValeurAdmisesTableauValeurs.hpp"
#include "ValeursAdmiseIntervalle.hpp"
#include <iostream>

using namespace std;

int main(){
  ValeursAdmiseIntervalle inter('a', 'd');
  if(inter('e'))
    cout<< " la valeur ’e’ est ok"<< endl;
  else
    cout<< " la valeur ’e’ n’est pas ok"<< endl;
  if(inter('c'))
    cout<< " la valeur ’c’ est ok"<< endl;
  else
    cout<< " la valeur ’c’ n’est pas ok"<< endl;
  char tab[] = {'b', 'o', 'n', 'j', 'u', 'r'};
  ValeurAdmisesTableauValeurs tableau(tab, 6);
  if(tableau('j'))
    cout<< " la valeur ’j’ est ok"<< endl;
  else
    cout<< " la valeur ’j’ n’est pas ok"<< endl;
  if(tableau('c'))
    cout<< " la valeur ’c’ est ok"<< endl;
  else
    cout<< " la valeur ’c’ n’est pas ok"<< endl;
}   
