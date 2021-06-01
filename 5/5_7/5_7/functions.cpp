
#include "functions.hpp"
void draw_line() {
    for (int i = 0; i < 50; ++i) {
        cout << "-";
    }
    cout <<'\n';
}
void arrUp(int *a, int size)
{
    for (int i=0;i<size;i++){
        a[i] = i;
    }
cout<<"Array filled up\n\n";
}

void arrUp(double *a, int size)
{
    for (int i=0;i<size;i++){
        a[i] = i*0.1;
    }
cout<<"Array filled up\n\n";
}

void arrDown(int *a, int size)
{
for (int i=0;i<size;i++) a[i] = size - i;
cout<<"Array filled down\n\n";
}

void arrDown(double *a, int size)
{
    for (int i=0;i<size;i++) {
        a[i] = (size - i)*11.1;
    }
cout<<"Array filled down\n\n";
}

void arrRand(int *a, int size)
{
    for (int i=0;i<size;i++){
    a[i]= (rand()%100)*1.31;
    }
}

void arrRand(double *a, int size)
{
    for (int i=0;i<size;i++){
    a[i]= rand()%100*0.5;
    }
}


