
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int** get_memory1(int n)
{
    int** array = new int*[n];
    for (int i = 0; i < n; i++)
    array[i] = new int[n];
    return array;
}


void free_memory (int **array, int n)
{ for (int i = 0; i < n; i++)
    
    delete[] array[i];
    delete[] array;
}

void input (int **array, int n)
{ for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    array[i][j] = rand() % 20;
    
}

void output (int **array, int n)
{
    for (int i = 0; i < n; i++)
    { for (int j = 0; j < n; j++)
        cout << setw(5) << array[i][j];
        cout << endl;
    }
}

int *sum(int **B,int **C,int size)
{
    int **Sum = new int *[size*size];
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            Sum[i][j] = B[i][j] + C[i][j];
        }
    }
    return *Sum;
}
int *multiPlay(int **BC,int **A,int size){
    int **D = new int* [size*size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k=0;k<size;k++){
                D[i][j] += A[i][k]*BC[k][j];
            }
        }
    }
    return *D;
}
int main()
{
    srand(time(nullptr));
    int n=0;
    cout<<"Input size of Matrix:"<<'\n';
    cin>>n;
    
    int **A=get_memory1(n);
    input(A, n);
    cout<<"Array A:"<<'\n';
    output(A,n);
    cout<<"-----------------------------"<<'\n';
    
    int **B=get_memory1(n);
    input(B, n);
    cout<<"Array B:"<<'\n';
    output(B, n);
    cout<<"-----------------------------"<<'\n';
    
    int **C=get_memory1(n);
    input(C, n);
    cout<<"Array C:"<<'\n';
    output(C,n);
    cout<<"------------------------------"<<'\n';
    
    int **BC=get_memory1(n);
    *BC=sum(B, C, n);
    cout<<"Array B+C:"<<'\n';
    output(BC, n);
    cout<<"------------------------------"<<'\n';
    
    int **D=get_memory1(n);
    *D=multiPlay(BC, A, n);
    cout<<"Result Array(A*(B+C)):"<<'\n';
    output(D, n);
    free_memory(A, n);
    free_memory(B, n);
    free_memory(C, n);
    free_memory(BC, n);
    free_memory(D, n);
    
    
}
