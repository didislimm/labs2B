/*Компоненты файла f – целые числа. Получить файл g из чисел исходного
 
 файла, в котором записаны сначала все положительные числа, затем все отрица-
 тельные.*/
#include "6.2.hpp"

int main(){
    int a=0;
    string path="MyFile.txt";
    string nextPath="RewriteFile.txt";
    string bin="bin.bin";
    string newBin="Rewritebin.bin";
    cout<<"Input amount of numbers"<<endl;
    cin>>a;
    createFileWithIntegers(path,a);
    rewrite(path,nextPath);
    createBinWithIntegers(bin,a);
    rewriteBin(newBin,bin);
    return 0;
}
