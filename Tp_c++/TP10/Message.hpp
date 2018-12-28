#ifndef MESSAGE
#define MESSAGE

#include <list>
#include <iostream>
#include <string>
using namespace std;
class Message{
public :
  void ajout(string l);
  string enleve();
  friend ostream& operator<<(ostream& out,Message& m);
  list<string> liste;
};
#endif
