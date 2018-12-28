#ifndef SINGLE
#define SINGLE
class Single{
public :
  int getInt();
  void setInt(int a);
  static Single *getInstance();
private :
  int x;
  Single(int a):x(a){}
  static Single * elem;
  ~Single(){}
  Single(Single&){}
  
};
#endif
