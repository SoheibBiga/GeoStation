#ifndef OPTION
#define OPTION
#include <iostream>
#include <string>
#include "Asset.hpp"
class Option : public Asset {
public:
  Asset act;
  Option(string no,int n,int j, Asset a);
  int nbJour;
  
};

#endif
