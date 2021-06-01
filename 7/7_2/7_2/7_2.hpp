
/*Выполнить задание, используя динамическое выделение памяти для двумер-
 ного массива, двумя способами:
 
 • описывая двумерный массив как одномерный, с расчетом смещения эле-
 мента массива по линейной формуле;
 
 • описывая двумерный массив как указатель на массив указателей.
 D=A*(B+C)
 */


#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int f(int i, int j, int n) // функция для определения номера
{ // элемента [i][j] в одномерном
    return (i * n + j); // массиве
}

int* get_memory(int size)//выделение памяти
{
    int* array = new int[size*size];
    return array;
}


void free_memory (int *array, int size)//освобождение
{
    delete[] array ;
}

void input (int *array,int size)//ввод
{
    for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j ++)
    array[f(i, j, size)] = rand() % 20;
}

void output (int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        cout << setw(5) << array[f(i, j, size)];
        cout << endl;
    }
}

int *sum(int *B,int *C,int size)
{
    int *Sum = new int [size*size];
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            int index = f(i, j, size);
            Sum[index] = B[index] + C[index];
        }
    }
    return (Sum);
}
int *multiPlay(int *BC,int *A,int size){
    int *D = new int [size*size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k=0;k<size;k++){
           D[f(i,j,size)] += A[f(i, k, size)]*BC[f(k, j, size)];
            }
        }
    }
    return D;
}
int main()
{
    srand(time(nullptr));
    int n=0;
    cout<<"Input size of Matrix:"<<'\n';
    cin>>n;
    
    int *A=get_memory(n);
    input(A, n);
    cout<<"Array A:"<<'\n';
    output(A,n);
    cout<<"-----------------------------"<<'\n';
    
    int *B=get_memory(n);
    input(B, n);
    cout<<"Array B:"<<'\n';
    output(B, n);
    cout<<"-----------------------------"<<'\n';
    
    int *C=get_memory(n);
    input(C, n);
    cout<<"Array C:"<<'\n';
    output(C,n);
    cout<<"------------------------------"<<'\n';
    
    int *BC=get_memory(n);
    BC=sum(B, C, n);
    cout<<"Array B+C:"<<'\n';
    output(BC, n);
    cout<<"------------------------------"<<'\n';
    
    int *D=get_memory(n);
    D=multiPlay(BC, A, n);
    cout<<"Result Array(A*(B+C)):"<<'\n';
    output(D, n);
    free_memory(A, n);
    free_memory(B, n);
    free_memory(C, n);
    free_memory(BC, n);
    free_memory(D, n);

    
}

