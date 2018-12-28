#include <iostream>

using namespace std;

int main(){
  int a = 2;
  int b = 4;
  int & ref1 = a;
  int & ref2 = b;
  ref1 -= ref2;
  ref2 += ref1;
  cout << "ref1 = " << ref1 << ", ref2 = "<< ref2 << endl;
  a -=b;
  b +=a;
  cout << "a = " << a << ", b = "<< b << endl;
}
