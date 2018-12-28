#include "SuiteTab.hpp"

template<class T>
void SuiteTab<T>::ajoute(T t){
  if( length == max){
    throw string("t'es ouf");
  }
  else{
    t[length] = t;
    length++;
  }
}
