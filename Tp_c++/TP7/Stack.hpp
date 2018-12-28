#ifndef STACK
#define STACK
#include <iostream>

using namespace std;

template <typename T> class Stack{

public :
  Stack():size(100),top(0){};
  Stack(int a):size(a),top(0){stacktab = new T[a];}
  T depile(){
    if(top != -1){
      T t = stacktab [top];
      top--;
      return t;
    }
    else
      return NULL;
  }

  bool add(T t){
    if(top != size-1){
      top++;
      stacktab[top] = t;
      return true;
    }
    return false;
  }

  int size;
  int top;
  T* stacktab;
};
template <class T> ostream& operator <<(ostream& out,Stack<T> s){
  for(int i=0;i<=s.top;i++){
    out << s.stacktab[i];
  }
  return out;
}

template <class T> ostream& operator <<(ostream& out,Stack<T*> s){
  for(int i=0;i<=s.top;i++){
    out << (*s.stacktab[i]);
  }
  return out;
}

#endif
