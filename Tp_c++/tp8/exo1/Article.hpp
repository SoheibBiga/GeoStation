#ifndef ARTICLE
#define ARTICLE

class Article{
public :
  Article(int p):prix(p){};
  virtual ~Article(){};
  virtual void affiche();
protected:
  int prix;
};
#endif
