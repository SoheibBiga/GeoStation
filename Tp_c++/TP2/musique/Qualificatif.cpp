#include "Qualificatif.hpp"

ostream& operator<<(ostream& out,Qualificatif d){
  switch  (d){
  case Qualificatif::majeur: out << "majeur";break;
  case Qualificatif::mineur: out << "mineur"; break;
  }
  return out;
}
