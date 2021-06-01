//#pragma once
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Object{
//protected:
//    int X;
//    int Y;
//public:
//    Object(int X,int Y){
//        this->X=X;
//        this->Y=Y;
//    }
//    Object(){
//        cout<<"Input X of people"<<endl;
//        enter(cin, X);
//
//        cout<<"Input Y of people"<<endl;
//        enter(cin, Y);
//    }
//    virtual void print() ;
//    ~Object()=default;
//    template <class T>
//    void enter(istream& in,T & a) {
//        while (true) {
//            in >> a;
//            
//            if (in.fail()) {
//                in.clear();
//                in.ignore(INT_MAX, '\n');
//                
//                cout << "An incorrect value. Please try again:" << endl;
//                
//                continue;
//            }
//            else {
//                break;
//            }
//        }
//    }
//};
//void Object::print(){
//    cout<<"Value of X: "<<X<<endl;
//    cout<<"Value of Y: "<<Y<<endl;
//}
