#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include<string>
using namespace::std;

template <class T>
class Vect{
    T * pArr;
    int size;
public:
    Vect();
    Vect(int );
    Vect(int size, T symbol);//констуктор заполнения каким-то элементом
    Vect(Vect& a);//копирования
    ~Vect();
    
    T& operator [](const int i);
    T operator [](const int i) const;
    void setSize();
//    short fill();
    void pushBack(const T addElem);//это функции удаления/добавления элементов
    void popBack();//
    void createFile(int size);
    void getArr(Vect<T> &a);//
    
    
    friend ostream& operator <<(ostream& out, const Vect& arr) // перегрузка оператора вывода
    {
        for (int i = 0; i < arr.size; i++)
        {
            out << arr.pArr[i] << " ";
        }
        cout << endl;
        return out;
    }
    friend istream& operator >>(istream& in, Vect& arr) // перегрузка оператора ввода
    {
        for (int i = 0; i < arr.size; i++)
        {
            in >> arr.pArr[i];
        }
        cout << endl;
        return in;
    }
    
    short fill()
    {
        ifstream read_file("TxtFile.txt");
        if (!read_file.is_open())
        {
            cout<<"Error 2";
        }
        cout << endl;
        while(!read_file.eof())
        {
            short value = 0;
            read_file>>value;
            
            pArr[value]++;
        }
        
        for(int i = 0; i < size; ++i)
        {
            cout << pArr[i] << " ";
        }
        cout << endl;
        short numb=0;
        for(short i=0;i<size;i++)
        {
            if(pArr[i]!=0)
            {
                numb++;
            }
        }
        cout<<numb<<"size"<<endl;
        return numb;
    }

    
};

template <class T>
 T& Vect<T>:: operator [](const int i){
    if (i<size && i>=0)
        return pArr[i];
    else {
        cout<<"Out of bounce "<<endl;
        exit(0);
    }
};

template <class T>
T Vect<T>::operator [](const int i) const{//не изменяем текущий объект
    if (i<size && i>=0)
        return pArr[i];
    else {
        cout<<"Out of bounce "<<endl;
        exit(0);
    }
};

template<class T>
Vect<T>::Vect(){
    pArr=nullptr;
    size=0;
}

template<class T>
Vect<T>::Vect(int size){
        
        this->size = size;
        pArr = new T[size];
        for (int i = 0; i < size; i++)
        pArr[i] = rand()%10;
    }
    
template<class T>
Vect<T>::Vect(int size, T symbol) {
    this->size = size;
    pArr = new T[size];
    for (int i = 0; i < size; i++){
        pArr[i] = symbol;
    }
}

template<class T>
Vect<T>::Vect(Vect& a){
    a.size=size;
    for (int i=0;i<size;i++){
        a[i]=pArr[i];
    }
}

template<class T>
Vect<T>::~Vect(){
    delete [] pArr;
    cout<<"Destructor compled!"<<endl;
}

template <class T>
void Vect <T>::createFile(int a){//заполнение файла числами
    ofstream fout;
    fout.open("TxtFile.txt");
    if(!fout.is_open())
    {
        cout<<"Error 1";
    }
    else{
        cout<<"Reading is succesfully"<<'\n';
        for(short i=0;i<a;++i){
            fout<<rand()%100<<endl;//TODO: пересмотреть этот кусок
        }
    }
    fout.close();
}

template <class T>
void Vect<T>::pushBack(const T addElem){
    ++size;
    T *arr=new T[size];
    for(int i=0;i<size-1;i++){
        arr[i]=pArr[i];
    }
    arr[size-1]=addElem;
    delete[]pArr;
    pArr=arr;
}

template <class T>
void Vect<T>::popBack(){
    if(size>1){
        --size;
        T*arr=new T[size];
        for(int i=0;i<size;i++){
            arr[i]=pArr[i];
        }
        delete []pArr;
        pArr=arr;
    }
    else if (size==1) {
        size=0;
        delete[]pArr;
        pArr=nullptr;
    }
    
}

template <class T>
    void Vect<T>::getArr(Vect<T> &result)//*pArr[],*pArr1[], short size
    {
    short a = 0;
    for(short i=0;i<size;i++)
    {
        if(pArr[i]!=0)
        {
            result[a++]=i;
        }

    }
}


