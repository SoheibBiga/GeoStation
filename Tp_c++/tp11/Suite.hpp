#ifndef SUITE
#define SUITE
template <class T> class Suite
{
public:
virtual T &operator[] (const unsigned int)=0; //doit permettre de modifier la valeur virtual int taille() = 0; //nombre d’ ́el ́ements "r ́eels"
virtual void affiche()=0;//affiche les  ́el ́ements
virtual void ajoute(T)=0;// ajoute `a la fin
};
#endif
