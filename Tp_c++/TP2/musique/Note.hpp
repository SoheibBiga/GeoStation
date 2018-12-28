#ifndef NOTE
#define NOTE
#include <iostream>

using namespace std;

enum class Note{Do,Re,Mi,Fa,Sol,La,Si};

ostream& operator<<(ostream& out,Note d);
#endif

    
