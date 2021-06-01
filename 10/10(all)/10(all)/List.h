#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include "Stone.h"
#include "Chest.h"
#include "Player.h"
#include "Dealer.h"
#include "Header.hpp"
using namespace std;

template <class T>
class Node {
public:
    T* Data;
    Node<T>* NextPtr;
    Node(T * Data=nullptr,Node<T>* NextPtr=nullptr){
        this->Data=Data;
        this->NextPtr=NextPtr;
    }
};
template <class T>
class List {
    Node<Object> *Head;
    int Size;
    
    void pushBack(T* Data);//Добавляем конкретный элемент Data
    void clear();//очищение
public:
    List();//*
    List( List<T>& anotherList);//*
    ~List();//*
    // методы точно такие же как и для списка
    
    void pushBack();//Добавляет сам пользователь новый элемент
    
    void deleteAT(int index);//удалить элемент с index
    void popFront();//удалить первый
    void popBack();//удалить последний
    
    void show() ;//вывод
};
template<typename T>
List<T>::List()
{
    Size=0;
    Head=nullptr;
}

template <class T>
List<T>::List(List<T>& List) {
    Node<T>* ptrHead = List.Head;
    while (ptrHead) {
        push_back(ptrHead->Data);
        ptrHead = ptrHead->NextPtr;
    }
}

template<typename T>
List<T>::~List()
{
    clear();
}

template <class T>
void List<T>::clear()
{
    
    while (Size) {
        popBack();//метод удаления с конца
    }
}
template <class T>
void List <T>::show()  {
    Node<Object> *ptrHead=Head;
    cout<<"List: "<<endl;
    while (ptrHead!=nullptr)
    {
        ptrHead->Data->print();
        ptrHead=ptrHead->NextPtr;
    }
    cout << endl;
}

template <class T>
void List<T>::pushBack(){
    cout<<"Input 1,if you want create Dealer"<<endl;
    cout<<"Input 2,if you want create Player"<<endl;
    cout<<"Input 3,if you want create Citizen"<<endl;
    cout<<"Input 4,if you want create Stone"<<endl;
    cout<<"Input 5,if you want create Chest"<<endl;
    bool flag = true;
    int n=0;
    Node<Object> *newNode=new Node<Object>;
    while (flag) {
        cin>>n;
        if (n >= 1 && n <= 5)
        {
            flag = false;
        }
        
        switch (n)
        {
            case 1:
            {
                cout << "\nDealer!" << endl;
                Dealer *dealer=new Dealer;
                *newNode= dealer;
            }
                break;
            case 2:
            {
                cout << "\nPlayer!" << endl;
                Player *player=new Player;
                *newNode = player;
            }
                break;
            case 3:
            {
                cout << "\nCitizen!" << endl;
                Citizen *citizen=new Citizen;
                *newNode = citizen;
            }
                break;
            case 4:
            {
                cout << "\nStone!" << endl;
                Stone *stone=new Stone;
                *newNode = stone;
            }
                break;
            case 5:
            {
                cout << "\nChest!" << endl;
                Chest *chest=new Chest;
                *newNode = chest;
            }
                break;
        }
    }
    if(Head == nullptr)
    {
        Head=newNode;
    }
    else
    {
        Node<Object>* ptrHead=Head;
        while(ptrHead->NextPtr!=nullptr){//нашли место для добавления
            ptrHead=ptrHead->NextPtr;
        }
        ptrHead->NextPtr=newNode;//добавили
    }
    Size++;
}

template <class T>
void List<T>::pushBack(T *Data) {
    
    if (!Head) {
        Head = new Node<T>;
        Head->Data=Data;
    }
    else {
        Node<T>* ptrHead = Head;
        while (ptrHead->NextPtr) {
            ptrHead = ptrHead->NextPtr;
        }
        ptrHead->NextPtr = new Node<T>;
        ptrHead->NextPtr->Data=Data;
    }
    Size++;
}

template <class T>
void List<T>::popFront(){//удаление из начала списка
    Node<Object>* ptrHead=Head;
    Head=Head->NextPtr;
    delete ptrHead;
    Size--;
}

template <class T>
void List<T>::popBack(){//удаление из конца
    Node<Object>* ptrHead=Head;
    Node<Object>* copy=Head;
    while(ptrHead->NextPtr!=nullptr){
        copy=ptrHead;
        ptrHead=ptrHead->NextPtr;
    }
    copy->NextPtr=nullptr;
    delete ptrHead;
    Size--;
}
template <class T>
void List<T>::deleteAT(int index){
    if (index == 0){
        popFront();
    }
    else
    {
        Node<Object>* ptrHead=Head;
        for (int i=0;i<index-1;i++){
            ptrHead=ptrHead->NextPtr;//доходим до элемента который указвает на нужный нам
        }
        Node<Object> *forDelete=ptrHead->NextPtr;
        ptrHead->NextPtr=forDelete->NextPtr;//связали 2 элемента
        delete forDelete;
        Size--;
    }
}
