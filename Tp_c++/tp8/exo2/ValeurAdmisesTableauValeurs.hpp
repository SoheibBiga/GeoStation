#ifndef VALEURADMISESTABLEAUVALEURS
#define VALEURADMISESTABLEAUVALEURS
class ValeurAdmisesTableauValeurs{
public :
  ValeurAdmisesTableauValeurs(char * t,int i):tab(t),taille(i){
    
  };
  virtual bool operator()(char a);

private:
  char  * tab;
  int taille;
};

#endif
