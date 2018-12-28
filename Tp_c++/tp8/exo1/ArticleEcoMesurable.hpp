#ifndef ARTICLEECOMESURABLE
#define ARTICLEECOMESURABLE
#include "Article.hpp"
class ArticleEcoMesurable:virtual public Article{
public:
  ArticleEcoMesurable(int p,int e):Article(p),eco(e){};
  ~ArticleEcoMesurable(){};
  virtual void affiche();
protected:
  int eco;
};
#endif
