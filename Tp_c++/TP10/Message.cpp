#include "Message.hpp"

void Message::ajout(string l){
  liste.push_back(l);
}


string Message::enleve(){
  if(!liste.empty()){
    string first = liste.front();
    liste.pop_front();
    return first;
  }
  else
    return NULL;
}
ostream& operator<<(ostream& out,Message & m){
   list<string>::iterator 
    lit (m.liste.begin()), 
    lend(m.liste.end()); 
  for(;lit!=lend;++lit) out << *lit ;
  out << "\n";
  return out;
}
