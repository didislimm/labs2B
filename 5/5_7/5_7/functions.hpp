#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
template <class T>
void Insert ( T *a,int size,int &compare,int &move)
{
    for(int i=0;i<size;++i){
        T x=a[i];
        int j=i-1;
        while(static_cast<void>(compare++),x<a[j]){
            a[j+1]=a[j];
            move++;
            j--;
            if(j<0){
                break;
            }
        }
        a[j+1]=x;
        move++;
    }
}
template <class B>
void Select ( B*a,int size,int &compare,int &move)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int iMin = i; //Поиск минимального элемента
        for (int j = i + 1; j < size; ++j)
        {
            compare++;
            if (a[j] < a[iMin])
            {
                move++;
                iMin = j;
            }
        }
        B temp = a[iMin]; //Обмен элементов местами
        a[iMin] = a[i];
        a[i] = temp;
    }
    


}
template <class C>
void Input(C*a,int size)
{
    for(int i=0;i<size;++i){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}

void arrUp(int *a,int size);
void arrUp(double *a, int size);

void arrDown(int*a,int size);
void arrDown(double *a, int size);

void arrRand(int*a,int size);
void arrRand(double *a,int size);

void draw_line();

