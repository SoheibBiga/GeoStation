#include <iostream>
#include "Intref.hpp"

using namespace std;

IntRef& IntRef::operator=(const IntRef& y){
  r = y.r;
  return *this;
  
}
IntRef& IntRef::operator=(const int y){
  r= y;
  return *this;
}
ostream& operator<<(ostream& out,IntRef & n) {
  out << n.r << "\n" ;return out;
}
