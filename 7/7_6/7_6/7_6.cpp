#include "7_6.hpp"
void add(Node *&top, Node *&end)
{
    
    Node* nv = new Node; // образуем новый элемент списка
    nv->d = rand()%10;
    nv->next = NULL;
    nv->pred = NULL;
    if (!top)
    { top = nv; // первый элемент списка
        end = nv;
    }
    else
    {
        nv->next = top;
        top->pred = nv;
        top = nv;
        }
}

void output(Node *top){
    while(top){
        cout<<top->d<<" ";
        top=top->next;
    }
    cout<<'\n';
}
void output1(Node* end)
{
    while (end)
    {
        cout << end->d << ' ';
        end = end->pred;
    }
    cout << "\n";
}
int Input()
{
    int test = 0;
    bool flag = true;
    bool invite = false;
    cout << "Input value of digits (value must be even) \n";
    cin >> test;
    
    while (flag)
    {
        if (invite)
        {
            cout << "Input value of digits (value must be even) \n";
            cin >> test;
        }
        
        if (test%2==0)
        {
            flag = false;
        }
        else
        {
            flag = true;
            invite = true;
            cout << "Your enter is not correct. Please try again..." << endl;
        }
    }
    return test;
}
double result(Node *top,Node *end){
    double a=1;
    while(top){
        a*=top->d+end->d;
        top=top->next;
        end=end->pred;
    }
    return a;
}
