#ifndef URNE
#define URNE

class Scrutin;
class Urne{
public :
  friend class Scrutin;
  const Scrutin& scrut;
  const int nbv;
  int  * const vote;
  bool voter(int choix);
  int getRes(int choix) const;
  void affiche() const;
  
private:
   Urne(Scrutin & s, int n);
  ~Urne();
};

#endif
