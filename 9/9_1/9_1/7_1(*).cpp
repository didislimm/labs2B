///*
// Выполнить задание, используя динамическое выделение памяти для одно-
// мерного массива. Дано (в текстовом файле) n>109 натуральных чисел (каждое
// число 104). Ограничение на объем используемой памяти 1 Мб. Получить массив
// за один просмотр элементов файла:
// 2. в котором все числа исходного файла расположены по убыванию значений (без
// повторений);
// */
//#include <vector>
//#include <iostream>
//#include <fstream>
//#include <ctime>
//#include <stdlib.h>
//#include<string>
//using namespace std;
//void createFile(string rd,short kol,short size);
//short fill(vector<bool> &arr,string rd,short size);
//void getArr(vector<bool> &arr,vector<short> &result, short size);
//int main(){
//    srand(time(nullptr));
//    const short kol=10;
//    const short size=20;
//    vector<bool> vect;
//    vect.resize(size);
//    string file="billionFile.txt";
//    createFile(file,kol,size);
//    
//    short k=0;
//    k=fill(vect,file,size);
//    
//    vector<short> result;
//    result.resize(k);//выделяем для результирующего конкретное число так как его знаем
//    getArr(vect, result, size);
//    for(short i=0;i<=k;i++){
//        cout<<result[i]<<" ";
//    }
//}
//
//void createFile(string rd,short kol,short size){
//    ofstream fout;
//    //kol- количество чисел
//    //size-интервал от 0 до size
//    fout.open(rd);
//    if(!fout.is_open())
//    {
//        cout<<"Error 1";
//    }
//    else{
//        cout<<"Reading is succesfully"<<'\n';
//        for(short i=0;i<kol;++i){
//            fout<<rand()%size<<endl;
//        }
//    }
//    fout.close();
//}
//short fill(vector<bool>& arr,string rd,short size)
//{
//    ifstream read_file(rd);
//    if (!read_file.is_open())
//    {
//        cout<<"Error 2";
//    }
//    cout << endl;
//    while(!read_file.eof())
//    {
//        short value = 0;
//        read_file>>value;
//        cout<<value<<" ";
//        arr[value]=true;
//    }
//    cout<<endl;
//    for(int i = 0; i < size; ++i)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    short numb=0;
//    for(short i=0;i<size;i++)
//    {
//        if(arr[i]==true)
//        {
//            numb++;
//        }
//    }
//    cout<<numb<<" size"<<endl;
//    return numb;
//    
//}
//void getArr(vector<bool>& arr,vector<short> &result, short size)
//{
//    short a = 0;
//    for(short i=0;i<size;i++)
//    {
//        if(arr[i]==true)
//        {
//            result[a++]=i;
//        }
//        else continue;
//    }
//}
