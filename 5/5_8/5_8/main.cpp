#include "functions.hpp"
int main()
{
    srand(time(nullptr));
    
    int size = 0;
    cout << "Enter size: ";
    cin >> size;
    
    int* ArrInt = new int[size];
    cout << "ArrInt:"<< endl;
    
    FillArray(ArrInt, size);
    ShowArray(ArrInt, size);
    
    int begin = 0;
    int end = size - 1;
    
    MergSort(ArrInt, size, begin, end);
    ShowArray(ArrInt, size);
    
    double* ArrDoub = new double[size];
    cout << "\nArrDoub:" << endl;
    
    FillArray(ArrDoub, size);
    ShowArray(ArrDoub, size);
    
    MergSort(ArrDoub, size, begin, end);
    ShowArray(ArrDoub, size);
    
    char* ArrChar = new char[size];
    cout << "\nArrChar:" << endl;
    
    FillArray(ArrChar, size);
    ShowArray(ArrChar, size);
    
    MergSort(ArrChar, size, begin, end);
    ShowArray(ArrChar, size);
    
    int count_of_strings = 0;
    cout << "\nEnter count of strings: ";
    cin >> count_of_strings;
    
    char** arr_strings = new char* [count_of_strings];
    for (int i = 0; i < count_of_strings; ++i)
    {
        arr_strings[i] = new char[length];
    }
    
    Menu(arr_strings, count_of_strings);
    Show_arr_strings(arr_strings, count_of_strings);
    
    begin = 0;
    end = count_of_strings - 1;
    
    MergSort(arr_strings, count_of_strings, begin, end);
    Show_arr_strings(arr_strings, count_of_strings);
    
    Delete(arr_strings, count_of_strings);
    delete[] ArrChar;
    delete[] ArrDoub;
    delete[] ArrInt;
    
    return 0;
}
