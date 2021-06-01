#include <iostream>
#include <string>
#include <ctime>

using namespace std;
template <class T>
class Node {
public:
    T Data;
    Node* NextPtr;
    Node* PrevPtr;
};
template <class T>
class List {
    Node<T> *Head;
    Node<T> *End;
    int Size;
    
//    void find_eq(T key,Node<T>*&ppv);
//    void find_gt(T key,Node<T>*&ppv);
public:
    List();
    List(int size, T defaultData);
    List( List& anotherList);
    ~List();

    void show() ;
    void show1();
    int getSize() ;
    void Add();//    void add(Node *&top, Node *&end);
    void clear();
    void pushBack(T data);
    int find(int data);
    void del(int);//*
    //T& operator[](int index) ;
    double result();
    void print();
};
template<typename T>
List<T>::List()
{
    Size=0;
    Head=nullptr;
    End=nullptr;
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
List<T>::List(List<T>& List) {
    Node<T>* current = List.Head;
    while (current) {
        pushBack(current->Data);
        current = current->NextPtr;
    }
}
template <class T>
void List <T>::pushBack(T data) { //Добавление в конец элементов
    if (Size==0)
    {
        Head=new Node<T>(data);
        End=Head;
        Size++;
        return;
    }
    
    Node<T>*current = End;
    current->NextPtr = new Node <T>(data, nullptr, current);
    End = current->NextPtr;
    Size++;
}
template<typename T>
List<T>::~List()
{
    clear();
}

template<class T>
void List<T>::del(int data){
    Node<T> *ptr=Head;
    while(ptr){
        if(ptr->Data==data){
            ptr->PrevPtr=ptr->NextPtr;
            
        }
    }
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
int List<T>::getSize()
{
    return Size;
}
template <class T>
void List <T>::show()  {
    Node<T> *pv= Head;
    while (pv)
    {
        cout << pv->Data << " ";
        pv = pv->NextPtr;
    }
    cout << endl;
}
template <class T>
void List <T>::show1()  {
    Node<T> *pv= End;
    while (pv)
    {
        cout << pv->Data << " ";
        pv = pv->PrevPtr;
    }
    cout << endl;
}
template <class T>
int List<T>::find(int data){
    Node <T>*ptr=Head;
    Node <T>*pos=nullptr;
    while (ptr) {
        if (ptr->Data== data){
            pos=ptr;
            return pos;
            break;
        }
        else
            ptr=ptr->NextPtr;
    }
    cout<<"No one elemets with writting Data"<<endl;
}

template <class T>
double List<T>::result(){
    Node<T>*ptrHead=Head;
    Node<T>*ptrEnd=End;
    double a=1;
    while(ptrHead){
        a*=ptrHead->Data+ptrEnd->Data;
        ptrHead=ptrHead->NextPtr;
        ptrEnd=ptrEnd->PrevPtr;
    }
    return a;
}

template<typename T>
void List<T>::Add()
{
    Node<T>* nv = new Node<T>; // образуем новый элемент списка
    nv->Data = rand()%10;
    nv->NextPtr = NULL;
    nv->PrevPtr = NULL;
    if (!Head)
    { Head = nv; // первый элемент списка
        End= nv;
    }
    else
    {
        nv->NextPtr = Head;
        Head->PrevPtr = nv;
        Head = nv;
    }
}

int main(){
    srand(time(nullptr));
    List<int> L1;
    cout<<"Input value of digits"<<endl;
    int n=0;
    cin>>n;
    double result=0;
    for(int i=0;i<n;i++){
        L1.Add();
    }
    L1.show();
    L1.show1();
    result=L1.result();
    cout<<"Result multiplay "<<result<<endl;
}
