#include <iostream>
#include <ctime>
using namespace std;


class Node {
public:
    int Data;
    Node *left;
    Node *right;
    
};

class Tree{
    
    
    void copy(Node *,Node*);
    void del(Node*);
    Node* find(int key);
public:
    Node *Head;
    Tree();
    Tree(int );
    Tree(Tree &anotherTree);
    ~Tree();
    void outL(Node*);
    void outR(Node* top);
    int countL(Node*);
    void add(int key);
    void delList(int key);//удаление элемента с соответсвующим листом
    void outputLeft();
    void outputRight();
    int count();//cчитает количество листьев
    
    
};

Tree::Tree(){
    Head=NULL;
    
}
void Tree::outL(Node* top)
{
    if (top)
    {
        outL(top->left);
        cout << top->Data << " ";
        outL(top->right);
    }
}

Tree::Tree(int z)
{
    for (int i = 1; i <= z; i++)
    {
        int key = rand() % 60;
        Node* pv = new Node;
        pv->Data = key;
        pv->left = nullptr;
        pv->right =nullptr;
        if (!Head)
            Head = pv;
        else
        {
            Node* ppv;
            ppv = find(key);
            if (key < ppv->Data){
                ppv->left = pv;
            }
            else
                ppv->right = pv;
        }
    }
}

Tree::Tree(Tree&anotherTree){//*
    Node* second = new Node;
    Node* first = anotherTree.Head;
    if (first == NULL)
    {
        Head = NULL;
    }
    else
    {
        Head = second;
        second->Data = first->Data;
        second->left = NULL;
        second->right = NULL;
        copy(second->left, first->left);
        copy(second->right, first->right);
    }
}

Tree::~Tree(){
    if(Head){
        del(Head->left);
        del(Head->right);
    }
    delete Head;
    cout<<"distructor completed"<<endl;
    
}

Node* Tree::find(int key){
    Node *pv=Head,*ppv=Head;
    while(pv){
        ppv=pv;
        if(key<pv->Data){
            pv=pv->left;
        }
        else{
            pv=pv->right;
        }
    }
    return ppv;
}

void Tree::copy(Node* second, Node *first){//first-начало копирования
    if(first==NULL){
        second=NULL;
    }
    else
    {
        Node* second_1 = new Node;
        second = second_1;
        second_1->Data = Head->Data;
        copy(second_1->left, Head->left);
        copy(second_1->right, Head->right);
    }
}

int Tree::count(){
    int count=0;
    if (Head)
    {
      count=countL(Head->left);
        count+=countL(Head->right);
    }
    return count;
}
int Tree::countL(Node *top){
    int count=0;
    if(top)
    {
        if (top->left==nullptr && top->right==nullptr) {
            count++;
        }
        else{
            count+=countL(top->left);
            count+=countL(top->right);
            
        }
    }
    return count;
}



void Tree::outputLeft()
{
    cout << "Your tree: " << endl;
    if (Head)
    {
        outL(Head->left);
        cout << Head->Data << " ";
        outL(Head->right);
    }
    cout << endl;
}


void Tree::outR(Node* top)
{
    if (top)
    {
        outR(top->right);
        cout << top->Data << " ";
        outR(top->left);
    }
}

void Tree::outputRight()
{
    cout << "Your tree: " << endl;
    if (Head)
    {
        outR(Head->right);
        cout << Head->Data << " ";
        outR(Head->left);
    }
    cout << endl;
}


void Tree::delList(int key){
    Node *pv=nullptr;
    pv=find(key);
    if(pv==nullptr){
        cout<<"Element with this key are not found";
    }
    else {
        pv->left=nullptr;
        pv->right=nullptr;
        
    }
}

void Tree::del(Node*next){
    if(next)
    {
        del(next->left);
        del(next->right);
    }
    delete next;
    next = NULL;
}


void Tree::add(int key){
    Node *nv= new Node ;
    nv->Data=key;
    nv->left=nullptr;
    nv->right=nullptr;
    if(!Head){
        Head=nv;
    }
    else{
        Node *pv=nullptr;
        pv=find(key);
        if (key<pv->Data){
            pv->left=nv;
        }
        else{
            pv->right=nv;
        }
    }
}



int main(){
    srand(time(NULL));
    int count=0;
    int n=0;
    cout<<"Input value of integers"<<'\n';
    cin>>n;
    Tree first(n);
    Tree test;
    test.add(20);
    test.add(10);
    test.add(8);
    test.add(12);
    test.add(30);
    test.add(25);
    test.add(34);
    test.add(22);
    cout<<test.countL(test.Head)<<endl;
    first.outputLeft();
    first.outL(first.Head);
    count=first.countL(first.Head);

    cout<<"value of  leaves "<<count<<endl;
}
