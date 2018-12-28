#ifndef FRACTION
#define FRACTION
#include <iostream>

using namespace std;

class Fraction{
public:
  int den, num;
  Fraction(int a,int b);
  Fraction(int a);
  Fraction operator+(const Fraction f) const;
  Fraction operator-(const Fraction f) const;
  friend ostream& operator <<(ostream& out ,  const Fraction f);
private:
  static int pgcd(int a,int b);
    
};
#endif
