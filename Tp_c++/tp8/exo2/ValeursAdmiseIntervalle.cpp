#include "ValeursAdmiseIntervalle.hpp"

bool ValeursAdmiseIntervalle::operator()(char c){
  if(c<=max && c>=min)
    return true;
  else return false;
}
