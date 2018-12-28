#include "Intref.hpp"

#include <iostream>

using namespace std;

int main(){
  int x=0,y=1, z=8;
  IntRef rx(x), ry(y) , rz(z);
  IntRef t[]={rx,ry};
  x++;
  cout << t[0];
  t[0]=z;
  cout << t[0];
  int x1=0;
  int x2=2;
  IntRef r1(x1), r2(x2);
  IntRef tab[][2] =  {{x1,x2},{x1,x2}};
   
}
