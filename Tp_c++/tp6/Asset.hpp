#ifndef ASSET
#define ASSET

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Asset{

public:
  Asset(string no,int n):name(no),price(n){}
  int getPrice();
  string getName();
  int currentValue();

private:
  string name;
  int price;
 
};

#endif
