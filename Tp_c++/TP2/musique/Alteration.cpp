#include "Alteration.hpp"

ostream& operator<<(ostream& out,Alteration d){
  switch  (d){
  case Alteration::Diese: out << "dièse";break;
  case Alteration::Bemol: out << "bémol"; break;
  case Alteration::aucune: out<<"";break;
  }
  return out;
}
