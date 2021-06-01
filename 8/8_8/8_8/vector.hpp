#include <iostream>
#include <ctime>
#include <ostream>
using namespace std;

template <class T>
class Vector{
    
    int Size;
    T* vector;
public:
    Vector& resize(int newSize, T filler);
    Vector& operator=(const Vector& anotherVector);
    Vector() //без параметров
    {
        Size = 0;//размер
        vector = 0;
    }
    Vector(int count) // конструктор инициализации рандомными числами
    {
        this->count = count;
        vector = new T[count];
        for (int i = 0; i < count; i++)
        {
            vector[i] = rand() % 100;
        }
    }
    Vector(Vector& a) // конструктор копирования
    {
        Size = a.Size;
        vector = new T[Size];
        for (int i = 0; i < Size; i++)
        {
            vector[i] = a.vector[i];
        }
    }
    ~Vector() // деструктор
    {
        clear();
       
    }
    void clear(){
        delete []vector;
        vector=nullptr;
        Size=0;
    }
    
    void Set_size() // задание размерности вектора
    {
        cout << "Input value of vectors \n";
        cin >> Size;
        
        vector = new T[Size];
        
        
    }
    
    void Set_size(int n) //задание размерности вектора через размерность двух других векторов
    {
        Vector newVect = new T[n];
        if(Size<n){
            for(int i=0;i<Size;i++){
                newVect[i]=vector[i];
            }
            for(int i=Size;i<n;i++){
                newVect[i]=rand()%10;
            }
        }
        else{
            for(int i=0;i<n;i++){
                newVect[i]=vector[i];
            }
        }
    }
   
    int Get_size() // определение кол-ва элементов заданного вектора
    {
        return Size;
    }
    void Set_elements() //заполение элементов вектора рандомными числами
    {
        for (int i = 0; i < Size; i++)
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
    T & operator[] (int i) //перегрузка оператора []
    {
        if (i < 0)
            return vector[0];
        if (i >= Size)
            return vector[Size - 1];
        return vector[i];
    }
    
    T & operator[] (int i)const //перегрузка оператора []
    {
        if (i < 0)
            return vector[0];
        if (i >= Size)
            return vector[Size - 1];
        return vector[i];
    }
};


template <class T>
Vector<T>& Vector <T>::operator=(const Vector& anotherVector) {
    if (&anotherVector == this) {
        return *this;
    }
    Size = anotherVector.Size;
    delete [] vector;
    vector = new T[Size];
    for (int i = 0; i < Size; ++i) {
        vector[i] = anotherVector.vector[i];
    }
    return *this;
}

template <class T>
Vector<T>&Vector<T>:: resize( int newSize, T filler)
{
    if (newSize == Size)
    {
        return *this;
    }
    if (newSize == 0)
    {
        delete vector;
        vector = nullptr;
        Size = 0;
        return *this;
    }
    T* newVector = new T[newSize];
    int index = 0;
    for (; index < newSize; ++index)
    {
        if (index <Size)
        {
            newVector[index] = vector[index];
        }
        else
        {
            newVector[index] = filler;
        }
    }
    delete[] vector;
    vector = newVector;
    Size = newSize;
    return *this;
}

