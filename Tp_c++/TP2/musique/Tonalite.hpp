#ifndef TONALITE
#define TONALITE
#include "Note.hpp"
#include "Alteration.hpp"
#include "Qualificatif.hpp"


class Tonalite{
private:
  Note n;
  Alteration a;
  Qualificatif q;

public:
  Tonalite(Note d,Alteration b,Qualificatif c):n(d),a(b),q(c){}

  void print();
  
  };
#endif
