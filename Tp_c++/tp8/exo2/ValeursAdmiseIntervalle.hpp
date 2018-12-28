#ifndef VALEURADMISEINTERVALLE
#define VALEURADMISEINTERVALLE
#include "ValeursAdmise.hpp"

class ValeursAdmiseIntervalle : public ValeursAdmise{
public:
  ValeursAdmiseIntervalle(char ma,char mi):min(ma),max(mi){};
  virtual bool operator()(char val);
private:
  char max;
  char min;
};
#endif
