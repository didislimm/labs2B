#include "functions.hpp"

int main(){
    int move=0;
    int compare=0;
    srand( (unsigned)time( NULL ));
    const int n=100;
    int array[n];
    double arrayD[n];
    int selection=0;
    cout<<"Input 1 if you want fill array-Ascending,2-descending or 3-random \n";
    cin>>selection;
    int sort=0;
    cout<<"Input 1 if you want to sort the array by inserts or 2 select \n";
    cin>>sort;
    switch (selection) {
        case 1:arrUp(arrayD, n);break;
        case 2:arrDown(arrayD, n);break;
        case 3:arrRand(arrayD, n);break;
            
    }
    Input(arrayD,n);
    draw_line();
    switch(sort){
        case 1:Insert(arrayD, n,compare,move);break;
        case 2:Select(arrayD, n,compare,move);break;
    }
    cout<<"Sorted array:\n";
    Input(arrayD, n);
    cout<<"Moved elements "<<move<<'\n';
    cout<<"Kolichestvo cravnenii "<<compare<<'\n';
}

