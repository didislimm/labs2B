#include "7(1).hpp"
#include<iostream>
int main(){
    srand(time(nullptr));
    const short kol=10;
    const short size=20;
    
    short *array=new short[size];
    for(int i = 0; i < size; ++i) {
        array[i] = 0;
    }
    
    string file="billionFile.txt";
    createFile(file,kol,size);
    
    short k=0;
    k=fill(array,file,size);
    
    short *result=new short[k];
    getArr(array,result,k,size);
    
    output(result,k);
    
    delete []array;
    delete []result;
}
