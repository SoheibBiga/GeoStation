#ifndef ARTICLECALORIMESURABLE
#define ARTICLECALORIMESURABLE
#include "Article.hpp"
class ArticleCaloriMesurable: virtual public Article{
public :
  ArticleCaloriMesurable(int p,int c):Article(p),calorie(c){};
  ~ArticleCaloriMesurable();
  virtual void affiche();
protected:
  int calorie;
};

#endif
