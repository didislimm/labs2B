/*Записать в новую строку слова, которые состоят из тех же букв, что и послед- нее слово заданной строки символов.*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int word_hl(string a, string& b, string razd, int& st);
bool wiw(string a, string b);
void result(string sent);
int main()
{
    int pos = 0;
    int pr;
    string sent;
    string dop_sent;
    string ans;
    string s;
    string razd = " ,?!;-.";
    
    cout << "input string ";
    getline(cin, sent);
    result(sent);
    cout << " result string " << ans;
}
void result(string sent){//разделители
do
    
    {
    pr = word_hl(sent,dop_sent,razd, pos);
    } while (pr!=0);
    int l = dop_sent.length();
    pos = 0;
    do
    {
        pr = word_hl(sent, s, razd, pos);
        bool flag = wiw(dop_sent,s);
        if (flag)
        {
            ans += s;
            ans += " ";
        }
    } while (pr != 0);
    
}

int word_hl(string a, string& b, string razd,int& st)
{
    int lng = a.length();
    int pos;
    for (int i = 0; i < lng; i++)
    {
        pos = a.find_first_of(razd, st);
        if (pos>0 && pos<lng)
        {
            if (pos - st > 1)
            {
                b = "";
                b.append(a, st, pos - st);
                st = pos + 1;
                return pos;
            }
            else
                st += 1;
        }
        else
        {
            b = "";
            b.append(a, st, lng - st);
            return 0;
        }
    }
    return false;
}
bool wiw(string a, string b)
{
    bool zn =true;
    int lng = b.length();
    int l = a.length();
    for (int i = 0; i < lng; i++)
    {
        zn = true;
        for (int k = 0; k < l; k++)
            if (b[i] == a[k])
            {
                zn = false;
                break;
            }
        if (zn)
        {
            return false;
        }
    }
    return true;
}


