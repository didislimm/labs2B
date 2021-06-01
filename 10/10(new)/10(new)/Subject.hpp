#include "Object.hpp"
class Subjects:public Object{
protected:
    int Height;
    int Width;
public:
    Subjects(int x,int y,int Height,int Width);
    Subjects();
    virtual ~Subjects();
     void print() ;
};

