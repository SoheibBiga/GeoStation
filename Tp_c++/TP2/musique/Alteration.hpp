#ifndef ALTERATION
#define ALTERATION

#include <iostream>

using namespace std;

enum class Alteration{Diese,Bemol,aucune};
ostream& operator<<(ostream& out,Alteration d);

#endif
