#include "7(4).hpp"
// функция нахождения элемента c ключом =key
// top - адрес начала списка
// ppv - адрес элемента списка, указывающего на найденный

void find_eq(Node *top, char key, Node *&ppv)
{
    Node *pv = top;
    ppv = top;
    //поиск элемента c ключом = key
    while (pv && pv->d != key)
    {
        ppv = pv; // запоминаем адрес предыдущего элемента
        pv = pv->p;
    }
}
// функция нахождения элемента c ключом >key
// top - адрес начала списка
// ppv - адрес элемента списка, указывающего на найденный
void find_gt(Node *top, char key, Node *&ppv)
{
    Node *pv = top;
    ppv = top;
    //поиск элемента c ключом > key
    while (pv && pv->d <= key)
    {
        ppv = pv; // запоминаем адрес предыдущего элемента
        pv = pv->p;
    }
}
//функция занесения элемента c ключом key в список
// по возрастанию ключей
// top - указатель начала списка
void add(Node*& top, char key)
{
    Node* ppv = NULL;
    Node* nv = new Node; // образуем новый элемент списка
    
    nv->count = 1;
    nv->d = key;
    nv->p = NULL;
    
    if (!top) // если список пуст
    {
        top = nv; // первый элемент списка
    }
    else
    {
        if (top->d >= key) // вставляем в начало списка
        {
            if (top->d > key)
            {
                nv->p = top;
                top = nv;
            }
            else
            {
                top->count++;
            }
        }
        else
        {
            find_eq(top, key, ppv);
            
            if (ppv->p!= NULL)
            {
                ppv->p->count++;
            }
            else
            {
                find_gt(top, key, ppv);
                // поиск по ключу места для нового элемента
                nv->p = ppv->p;
                
                // вставляем между элементами с адресами ppv и pv
                ppv->p = nv;
            }
        }
    }
}
int Input(int max)
{
    int test = 0;
    bool flag = true;
    bool invite = false;
    cout << "Enter n: ";
    cin >> test;
    
    while (flag)
    {
        if (invite)
        {
            cout << "Enter n: ";
            cin >> test;
        }
        
        if (test >= 1 && test <= max)
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
char Generation_of_simbol()
{
    char simbol;
    bool selector = false;
    
    selector = rand() % 2;
    
    if (selector == false)
    {
        simbol = rand() % ('z' - 'a') + 'a';
    }
    else
    {
        simbol = rand() % ('Z' - 'A') + 'A';
    }
    
    return simbol;
}
void show(Node* top)
{
    while (top)
    {
        cout << top->d<< '-' << top->count << " ";
        top = top->p;
    }
    cout << endl;
}
void Result(Node* top, Node*& top_result)
{
    while (top)
    {
        if (top->count > 1)
        {
            add(top_result, top->d);
        }
        top = top->p;
    }
    
    cout << endl;
}
