#include "Fraction.hpp"

int  Fraction::pgcd(int n, int p){
  int reste;
  //si un nombre est 0 on retourne 0
  if (n==0 || p == 0) 
    return 0;
  //on rend les entiers positifs
  if(n < 0) 
    n = -n;
  if(p < 0)
    p = -p;

  if (n >= p){
    reste = n%p;
    if ( reste == 0){
      return p;
    }
    else{
      n = p;
      p = reste;
      return pgcd(n,p);
    }
  }
  else
    return pgcd(p,n);
}

Fraction::Fraction(int a){
  num = a;
  den = 1;
}

Fraction::Fraction(int a,int b){
  if(b<0){
    b=-b;
    a=-a;
  }
  int p = pgcd(a,b);
  num = a/p;
  den = b/p;
}

ostream& operator <<(ostream& out, Fraction f ){
  out << f.num << "/" << f.den;
  return out;
}

Fraction Fraction::operator+(const Fraction f){
  return  Fraction((num*f.den)+(den*num),den*f.den);
}

Fraction Fraction::operator-(const Fraction f){
  return Fraction((num*f.den)-(den*num),den*f.den);
}
