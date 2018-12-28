#include "Tonalite.hpp"

int main(){
  Note n {Note::Mi};
  Alteration a{Alteration::Diese};
  Qualificatif q{Qualificatif::majeur};
  Tonalite t(n,a,q);
  t.print();
}
