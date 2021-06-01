#include <iostream>
#include <string>
#include <ctime>

using namespace std;
template <class T>
class Node {
public:
    T Data;
    Node* NextPtr;
};
template <class T>
class List {
    Node<T> *Head;
    int Size;
public:
    List();
    List(int size, T defaultData);
    List( List& anotherList);
    ~List();
    
    T& operator[](int index) ;
    T& operator[](int index) const;

    void clear();
    void show() ;
    int getSize() ;

    void push_back(T data);
    void random();
};
template <class T>
T& List <T>::operator[](const int index) const{
    int size = getSize();
    if (index < 0 or index >= size) {
        cout << "Error with index"<<endl;
    }

    int counter = 0;
    Node<T>* ptrHead = Head;

    for (; ptrHead != index; ++counter) {
        ptrHead = ptrHead->NextPtr;
    }
    return ptrHead->Data;
}

template <class T>
T& List <T>::operator[](const int index) {
    int size = getSize();
    if (index < 0 or index >= size) {
        cout << "Error with index"<<endl;
    }

    int counter = 0;
    Node<T>* ptrHead = Head;

    for (; ptrHead != index; ++counter) {
        ptrHead = ptrHead->NextPtr;
    }
    return ptrHead->Data;
}

template<typename T>
List<T>::List()
{
    Size=0;
    Head=nullptr;
}
template <class T>
List <T>::List(int size, T defaultData) {
    if (size <= 0) {
        cout<<"Error";
    }
    
    Head = new Node<T>;
    Head->Data=defaultData;
    Size = size--;
    
    Node<T>* current = Head;
    
    for (; size > 0; --size) {
        current->NextPtr = new Node<T>;
        current->NextPtr->Data=defaultData;
        current = current->NextPtr;
    }
}

template <class T>
List<T>::List(List<T>& newList) {
    int newSize=newList.getSize();
    Size=newSize;
    
    int counter=0;
    Head=new Node<T>(newList[counter++]);
    Size--;
    Node<T>* ptrHead=Head;
    for(;newSize>0;--newSize){
        ptrHead->NextPtr=new Node<T>(newList[counter++]);
        ptrHead=ptrHead->NextPtr;
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
    Node<T>* next;
    while (Head) {
        next = Head;
        Head = next->NextPtr;
        delete next;
    }
    Size = 0;
}

template<class T>
int List<T>::getSize(){
    return Size;
}
template <class T>
void List <T>::show()  {
    if(Size==0){
        cout<<"List is empty"<<endl;
    }
    for(int i=0;i<Size;i++){
        cout<<(*this)[i]<<" ";
    }
}

template <class T>
void List<T>::push_back(T Data) {
    if (!Head) {
        Head = new Node<T>;
        Head->Data=Data;
    }
        Node<T>* current = Head;
        while (current->NextPtr) {
            current = current->NextPtr;
        }
        current->NextPtr = new Node<T>;
        current->NextPtr->Data=Data;
        Size++;
}

template <class T>
void List<T>::random(){
    for(int i=0;i<Size;i++){
        (*this)[i]=rand()%100;
    }
}


