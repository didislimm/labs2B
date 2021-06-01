#include "Object.hpp"
class Human:public Object{
protected:
    string name;
public:
    Human(int x,int y,string name);
    Human();
    ~Human();
    void print() ;
};


