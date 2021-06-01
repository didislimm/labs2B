#include "Subject.hpp"
Subjects::Subjects(int x,int y,int Height,int Width):Object(x,y){
    this->Height=Height;
    this->Width=Width;
}
Subjects::Subjects():Object(){
    cout<<"Input value of Height"<<endl;
    enter(cin,Height);
    
    cout<<"Input value of Width"<<endl;
    enter(cin,Width);
    
}

void Subjects::print(){
    Object::print();
    cout<<"Value of Height: "<<Height<<endl;
    cout<<"Value of Width: "<<Width<<endl;
}
Subjects::~Subjects()=default;
