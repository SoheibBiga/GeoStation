#include <iostream>

using namespace std;

int& countDown1(int& n){
  cout << n << ",";
  return n;
}

int&  countDown2(int& n){
  cout << n << ",";
  n=n-1;
  return n;
}

 int * countDown3(int *n){
  cout << (*n) << ",";
  (*n)--;
  return n;
}

bool countDown4(int &n){

  cout << n << ",";
  n=n-1;
  if(n==0)
    return false;
  return true;
}

bool countDown5(int n){

  cout << n;
  int *x = &n;
  (*x)--;
  if(n==0){
    cout << " ," << (*x) << " ,";
    return false;
  }
  return true;
}
int main(){
  int n=5;
  while (countDown4(n)) cout <<  ", ";
  cout << " done !" << endl;
  return 0;
}


