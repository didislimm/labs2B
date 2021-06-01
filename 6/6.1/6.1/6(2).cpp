/*Написать программу перевода вещественных чисел из шестнадцатеричной системы счисления в двоичную.*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


//void copy_str(string& a, string bin, int pos, int kol)
//{
//    for (int i = 0; i < kol; i++, pos++){
//        a+= bin[pos];
//    }
//}
string result(string &numb,string hex,string bin){
        string new_numb;
        for (int i = 0; i < numb.length(); i++)
    {
        int pos=numb.find('.',0);
        if (pos<numb.length())
            new_numb += numb[pos];
        else
        {
//copy_str(new_numb,bin, hex.find(numb[i], 0) * 5, 4);
            new_numb.append(&bin, hex.find(numb[i], 0) * 5, 4)
        }
    }
    return new_numb;
}
int main()
{
    
    string numb;
    
    string hex_string = "0123456789ABCDEF";
    string bin_string = "0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111";
    cout << "Input value in hex :";
    getline(cin,numb);
    string result_string = result(numb,hex_string,bin_string);
    cout << result_string << '\n';
}



