#include "Single.hpp"

Single * Single::elem = nullptr;

Single * Single::getInstance(){
  if(elem !=nullptr)
    return elem;
  
  else{
    elem = new Single(0);
    return elem;
  }
}

int Single::getInt(){
  return x;
}

void Single::setInt(int a){
  x=a;
}
