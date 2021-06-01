#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;
struct student
{
    string fio;
    int age;
    string gender;
    int course;
    double mark;
    
};
int *SearchOlders(string txt,string bin);
void resultBin(string,string,int*);
int main(){
    int *maxAge;
    string txt="list.txt";
    string foutBin="listBin.bin";
    string result="resultBin.bin";
    maxAge=SearchOlders(txt, foutBin);
    resultBin(foutBin, result, maxAge);
}
int *SearchOlders(string txt,string BIN){
    ifstream fin(txt);
    ofstream foutBIN(BIN,ios::binary);
    int *age=new int [6];
    while (!fin.eof())
    {
        student stud;//бинарник ничем не отличается кроме того что нужно переписать из файла текстого в бинарник
        string var;
        for (int i = 0; i <= 2; i++)//этот цикл чтобы прочитать фио из файла без проблем
        {
            fin >>var;
            stud.fio+=var;//алгоритмы те же самые
            if(i!=2)
            stud.fio+=" ";
        }
        fin >> stud.age ;
        fin >> stud.gender;
        fin >> stud.course;
        fin >> stud.mark;
        if (stud.age >= age[stud.course])
        {
            age[stud.course] =stud.age;
        }
        foutBIN.write(reinterpret_cast<char*>(&stud), sizeof(student));
    }
    fin.close();
    foutBIN.close();
    return age;
}
void resultBin(string bin,string binRes,int *maxAge){
    ifstream finBIN(bin,ios::binary);
    ofstream foutRes(binRes,ios::binary);
    while(!finBIN.eof()){
        student stud;
        finBIN.read(reinterpret_cast<char*>(&stud), sizeof(student));
        if(maxAge[stud.course]==stud.age){
            foutRes.write(reinterpret_cast<char*>(&stud),sizeof(student));
        }
        else continue;
    }
    finBIN.close();
    foutRes.close();
}
