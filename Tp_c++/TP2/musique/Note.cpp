#include "Note.hpp"




ostream& operator<<(ostream& out, Note d) {
  switch  (d){
  case Note::Fa: out << "Fa";break;
  case Note::Do: out << "Do"; break;
  case Note::Re: out << "Re";break;
  case Note::Mi: out << "Mi";break;
  case Note::Sol: out<<"Sol";break;
  case Note::La: out<<"La";break;
  case Note::Si: out<<"Si";break;
  }
  return out;
}
