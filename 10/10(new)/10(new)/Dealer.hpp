#include "Humans.hpp"
class Dealer:public Human{
protected:
    int Type;
public:
    Dealer(int x,int y,string name,int Type);
    Dealer();
   ~Dealer()=default;
     void print() ;
};

