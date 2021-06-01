#include <iostream>
#include <ctime>
#include <ostream>
//#define value 1000;
using namespace std;

class Vector
{
    int count;
    short* vector;
public:
    Vector() //без параметров
    {
        count = 0;//размер
        vector = 0;
    }
    Vector(int count) // конструктор инициализации рандомными числами
    {
        this->count = count;
        vector = new short[count];
        for (int i = 0; i < count; i++)
        {
            vector[i] = rand() % 100;
        }
    }
    Vector(Vector& a) // конструктор копирования
    {
        count = a.count;
        vector = new short[count];
        for (int i = 0; i < count; i++)
        {
            vector[i] = a.vector[i];
        }
    }
    ~Vector() // деструктор
    {
        delete[] vector;
        cout << "Destructor complete!" << endl;
    }
    void Set_size() // задание размерности вектора
    {
        cout << "Input value of vectors \n";
        cin >> count;
    
        vector = new short[count];
        
        
   }
    
    void Set_size(int a, int b) //задание размерности вектора через размерность двух других векторов
    {
        count = a + b;
        vector = new short[count];
    }
   
    int Get_size() // определение кол-ва элементов заданного вектора
    {
        return count;
    }
    void Set_elements() //заполение элементов вектора рандомными числами
    {
        for (int i = 0; i < count; i++)
        {
            vector[i] = rand() % 100;
        }
    }
    friend ostream& operator <<(ostream& out, const Vector& arr) // перегрузка оператора вывода
    {
        for (int i = 0; i < arr.count; i++)
        {
            out << arr.vector[i] << " ";
        }
        cout << endl;
        return out;
    }
    friend istream& operator >>(istream& in, Vector& arr) // перегрузка оператора ввода
    {
        for (int i = 0; i < arr.count; i++)
        {
            in >> arr.vector[i];
        }
        cout << endl;
        return in;
    }
    short  & operator[] (int i) //перегрузка оператора []
    {
        if (i < 0)
            return vector[0];
        if (i >= count)
            return vector[count - 1];
        return vector[i];
    }
    
};

void combine_arrays(Vector& arr, Vector& arr2, Vector& arr3) //объединение двух массисов в один
{
    int k = 0;
    for (int i = 0; i < arr.Get_size(); i++)
    {
        arr3[k] = arr[i];
        k++;
    }
    for (int i = 0; i < arr2.Get_size(); i++)
    {
        arr3[k++] = arr2[i];
    }
}
int searchMax(Vector arr) //поиск максимального элемента
{
    int max = arr[0], pos1 = 0;
    for (int i = 1; i < arr.Get_size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            pos1 = i;
        }
    }
    return pos1;
}
int searchMin(Vector arr) //поиск минимального элемента
{
    int min = arr[0], pos2 = 0;
    for (int i = 1; i < arr.Get_size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            pos2 = i;
        }
    }
    return pos2;
}

