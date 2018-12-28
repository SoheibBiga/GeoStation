#include <iostream>
#ifndef INTREF
#define INTREF

using namespace std;
class IntRef{
public :
  IntRef(int &a):r(a){
  }
  IntRef& operator=(const IntRef& y);
  IntRef& operator=(const int y);
  int& r;
private :
  friend  ostream& operator <<(ostream& out ,  IntRef  &);
};
#endif
