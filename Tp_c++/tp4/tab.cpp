#include <iostream>

using namespace std;

int main(){
  int t[2];
  t[0]=0;
  t[1]=1;

  int& x=t[0];
  int& y=t[1];
  x++;
  cout << t[0] << "\n" ;
}
