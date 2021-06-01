#include "Object.hpp"
Object::Object(){
    cout<<"Input X of people"<<endl;
    enter(cin, X);

    cout<<"Input Y of people"<<endl;
    enter(cin, Y);
}
Object::Object(int X,int Y){
    this->X=X;
    this->Y=Y;
}
void Object::print(){
    cout<<"Value of X: "<<X<<endl;
    cout<<"Value of Y: "<<Y<<endl;
}
Object::~Object()=default;

