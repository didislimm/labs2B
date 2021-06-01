
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Object{
protected:
    int X;
    int Y;
public:
    Object(int X,int Y);
    Object();
    void print();
    ~Object();
};
template <class T>
void enter(istream& in,T & a) {
    while (true) {
        in >> a;
        
        if (in.fail()) {
            in.clear();
            in.ignore(INT_MAX, '\n');
            
            cout << "An incorrect value. Please try again:" << endl;
            
            continue;
        }
        else {
            break;
        }
    }
}
