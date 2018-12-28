#ifndef ARTICLEMESURABLE
#define ARTICLEMESURABLE
#include "ArticleEcoMesurable.hpp"
#include "ArticleCaloriMesurable.hpp"

class ArticleMesurable : public ArticleEcoMesurable,public ArticleCaloriMesurable{
public:
  ArticleMesurable(int p,int c,int e):Article(p),ArticleEcoMesurable(p,e),ArticleCaloriMesurable(p,c){};
  virtual void affiche();
};
#endif 
