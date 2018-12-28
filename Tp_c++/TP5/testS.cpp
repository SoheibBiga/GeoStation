#include "Single.hpp"
#include <iostream>
using namespace std;

int main(){
  Single* s1 = Single::getInstance();
 s1->setInt(3);
s2.setInt(4);
cout << s1->getInt() << "s2 " << s2.getInt();
  
}
