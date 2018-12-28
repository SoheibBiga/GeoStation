#include "ValeurAdmisesTableauValeurs.hpp"

bool ValeurAdmisesTableauValeurs::operator()(char a){
  for(int i=0;i<taille;i++){
    if(tab[i]==a)
      return true;
  }
  return false;
}
