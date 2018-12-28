#ifndef PARCOURS
#define PARCOURS

template <class T> class Parcours
{
public:
  virtual bool estFini()= 0;
//avance d’une case, op ́erateur pr ́efix ́e, renvoie une lvalue virtual Parcours<T> &operator++()=0;
//avance d’une case, op ́erateur postfix ́e, renvoie une rvalue virtual Parcours<T> & operator++(int)=0;
//d ́er ́ef ́erencement
virtual T& operator*()=0; //d ́er ́ef ́erencement
//recommence le parcours `a partir du d ́ebut virtual void retourneDebut()=0;
// doit permettre d’ ́ecrire *(it+2)= elem virtual Parcours<T> &operator+(int n)=0;
};

#endif
