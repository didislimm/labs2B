#include "Humans.hpp"
Human::Human(int x,int y,string name):Object(x,y){
        this->name=name;
    }
Human::Human():Object(){
        cout<<"Input name of people"<<endl;
        enter(cin, name);
    }
Human::~Human()=default;
void Human::print(){
    Object::print();
    cout<<"Name of people: "<<name<<endl;
}
