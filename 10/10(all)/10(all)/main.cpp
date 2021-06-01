#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
#include "Vector.h"
#include "ObjectFactory.h"
#include "Header.hpp"
//В ФАЙЛЕ HEADER.HPP хранятся все классы наследования
using namespace std;
int main(){
    //10.2-----------------------
    //    Vector vect;
    //    int n=0;
    //    cout<<"How much objects u want to see in Array"<<endl;
    //    cin>>n;
    //    while(n){
    //        vect.push_Back();
    //        n--;
    //    }
    //    vect.print();
    //    Vector newVect(vect);
    //    newVect.print();
    //    //  10.4  ---------------------
//        List<class T> list;
//        cout<<"How much objects u want to see in Array"<<endl;
//        int a;
//        cin>>a;
//        while(a){
//            list.pushBack();
//            a--;
//        }
//        list.show();
//        cout<<"Which object you want to delete?"<<endl;
//        int forDelete;
//        cin>>forDelete;
//        list.deleteAT(forDelete);
//        list.show();
    //10.3 -------------------
    const string file="Object.txt";
    int size=0;
    cout<<"How much object u want to see"<<endl;
    cin>>size;
    
    Vector Objects(size);
    Objects.input(size);
 
    ofstream fout(file);
    fout<<Objects<<endl;
    fout.close();
    
    ifstream fin(file);//записываем из файла в массив 
    Objects.clear();
    Objects.read(fin);
    cout<<endl<<Objects<<endl;
    fin.close();
    
    
}

