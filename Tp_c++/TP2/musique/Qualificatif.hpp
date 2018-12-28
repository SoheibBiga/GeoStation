#ifndef QUALIFICATIF
#define QUALIFICATIF
#include <iostream>

using namespace std;

enum class Qualificatif{majeur,mineur};
ostream& operator<<(ostream& out,Qualificatif d);
#endif
