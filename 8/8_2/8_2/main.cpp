/*Определить класс для работы с объектом «строка символов». Реализовать:
 сравнение строк, удаление из строки указанного символа. Удалить из заданной
 строки все символы, встречающиеся во второй заданной строке.*/
#include <iostream>
#include <string>
using namespace std;

class Stroka
{
    string stroka;
public:
    Stroka() //без параметров
    {
        stroka = "";
    }
    Stroka(string word) //конструктор инициализации
    {
        stroka = word;
    }
    Stroka(Stroka& str) //конструктор копирования
    {
        stroka = str.stroka;
    }
    ~Stroka() //деструктор
    {
        cout << "Вызвался деструктор" << endl;
    }
    void Compare_str(Stroka str) //сравнение строк
    {
        if (stroka == str.stroka)
            cout << "Строки одинаковы" << endl;
        else
            cout << "Строки не одинаковы" << endl;
    }
    void Delete_symbol(char symbol) // удаление символа из строки если он там есть
    {
        for (int i = 0; i < stroka.size(); i++)
        {
            if (stroka[i] == symbol)
                stroka.erase(i, 1);
        }
    }
    void Delete_all_symbols(const Stroka str) // удаление из строки всех символов которые встречаются во второй строке
    {
        for (int i = 0; i < stroka.size(); i++)
        {
            for (int j = 0; j < str.stroka.size(); j++)
            {
                if (stroka[i] == str.stroka[j])
                {
                    stroka.erase(i, 1);
                    break;
                }
            }
        }
    }
    friend ostream& operator <<(ostream& out, const Stroka& str) //перегрузка вывода
    {
        out << str.stroka;
        cout << endl;
        return out;
    }
    friend istream& operator >>(istream& in, Stroka& str) //перегрузка ввода
    {
        in >> str.stroka;
        return in;
    }
    friend Stroka operator-(const Stroka str, char symbol) //перегрузка - для удаления символа из строки если он там есть
    {
        Stroka str2;
        for (int i = 0; i < str.stroka.size(); i++)
        {
            if (str.stroka[i] != symbol)
                str2.stroka.push_back(str.stroka[i]);
        }
        return str2;
    }
    friend Stroka operator-(const Stroka str, const Stroka str2) // перегрузка - для удаления из строки всех символов
    {   //  которые встречаются во второй строке
        Stroka str3;
        bool p = false;
        for (int i = 0; i < str.stroka.size(); i++)
        {
            for (int j = 0; j < str2.stroka.size(); j++)
            {
                if (str.stroka[i] == str2.stroka[j])
                {
                    p = false;
                    break;
                }
                else
                    p = true;
            }
            if (p)
                str3.stroka.push_back(str.stroka[i]);
        }
        return str3;
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    
    Stroka str1;
    cout << "Введите строку: ";
    cin >> str1;
    cout << "Первая строка: " << str1 << endl;
    
    Stroka str2;
    cout << "Введите строку: ";
    cin >> str2;
    cout << "Вторая Строка: " << str2 << endl;
    
    str1.Compare_str(str2);
    cout << endl;
    
    // str1.Delete_symbol('q');
     str2.Delete_symbol('z');
    char symbol1 = 'q';
    str1 = str1 - symbol1;
    char symbol2 = 'z';
    str2 = str2 - symbol2;
    cout << "Первая строка после 1-го удаления: " << str1 << endl;
    cout << "Вторая строка после 1-го удаления: " << str2 << endl;
    
    // str1.Delete_all_symbols(str2);
    //str2.Delete_all_symbols(str1);
    str1 = str1 - str2;
    cout << "Первая строка после 2-го удаления: " << str1 << endl;
    cout << "Вторая строка после 2-го удаления: " << str2 << endl;
    return 0;
}


