/*2. По исходному списку определить ФИО самого старшего студента на каж-
 дом курсе. Сформировать список из этих студентов, удалив их из исходного спис-
 ка.*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Person
{
    string name;
    string surname;
    int age;
    int course;
    int score;
};


struct List
{
    Person Info;
    List* next;
};

void delete_List (List* begin,int course,int maxAge)
{
    
    
    List *ppv=begin;
    
    while(ppv)
    {
        if(ppv->Info.age!=maxAge &&ppv->Info.course==course)
        {
            List* rez = ppv->next;
            ppv = rez->next;
            delete rez;
        }
        ppv =ppv->next;
    }
}
int maxAge(int course,List* begin){
    int maxAge=0;
    List *pv=begin;
    while(pv){
        
        if(pv->Info.course==course && pv->Info.age>maxAge){
            maxAge=pv->Info.age;
        }
        pv=pv->next;
    }
    return maxAge;
}
void create_new(List* begin,List*& start,int age,int course)
{
    while(begin)
    {
        if(begin->Info.age == age && begin->Info.course == course )
        {
            List* pv = new List;
            pv->Info.name = begin->Info.name;
            pv->Info.surname = begin->Info.surname;
            pv->Info.age = begin->Info.age;
            pv->Info.course = begin->Info.course;
            pv->Info.score = begin->Info.score;
            pv->next = start;
            start = pv;
        }
        begin = begin->next;
    }
}


void find(List* begin,Person one, List *&ppv)
{
    List* pv = begin;
    ppv = begin;
    while(pv && pv->Info.surname > one.surname)
    {
        ppv = pv;
        pv = pv->next;
    }
}


void output(List* begin)
{
    while(begin)
    {
        cout << begin->Info.name << setw(7);
        cout << begin->Info.surname << setw(7);
        cout << begin->Info.age << setw(3);
        cout << begin->Info.course << setw(3);
        cout << begin->Info.score << setw(3);
        begin = begin->next;
        cout << endl;
    }
}



void input1(Person& nv)
{
    string name, surname;
    int age, course, score;
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;
    cout << "Course: ";
    cin >> course;
    cout << "Score: ";
    cin >> score;
    nv.name =  name;
    nv.surname =  surname;
    nv.age = age;
    nv.course = course;
    nv.score = score;
    
}


void input(List*& begin,Person& no)
{
    
    List* nv = new List;
    nv->Info = no;
    nv->next = NULL;
    if(!begin)
    {
        begin = nv;
    }
    else
    {
        if(begin->Info.surname > no.surname)
        {
            nv->next = begin;
            begin = nv;
        }
        else
        {
            List* ppv = NULL;
            find(begin, no, ppv);
            nv->next = ppv->next;
            ppv->next = nv;
            
        }
    }
}





int main()
{
    int N;
    cout << "How students:" << endl;
    cin >> N;
    List* begin = NULL;
    List* result = NULL;
    for (int i = 0; i < N; ++i)
    {
        Person per;
        input1(per);
        input(begin, per);
    }
    output(begin);
    cout << "Result List: \n";
    for(int i=1;i<5;i++){//передаем номер курса и удаляем не подходящих
        int age=0;//i-номер курса
        age=maxAge(i,begin);//поиск макс возраста на курсе
        create_new(begin, result, age,i);//заносим в новый
        delete_List(begin,i,age);//удаляем из старого
        
    }
    output(begin);
    cout<<endl;
    output(result);
}

