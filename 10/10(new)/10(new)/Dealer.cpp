#include "Dealer.hpp"
Dealer::Dealer(int x,int y,string name,int Type):Human(x, y,name){
    this->Type=Type;
}
Dealer::Dealer():Human(){
    cout<<"Input value of Type"<<endl;
    enter(cin,Type);
}
Dealer:: ~Dealer()=default;
void Dealer::print(){
    Human::print();
    cout<<"Value of Type: "<<Type<<endl;
}
