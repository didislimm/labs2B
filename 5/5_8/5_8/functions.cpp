#include "functions.hpp"



void Fill_arr_strings_yourself(char** arr_strings, const int count_of_strings)
{
    for (int i = 0; i < count_of_strings; ++i)
    {
        cin.getline(arr_strings[i], length);
    }
}
void Fill_arr_strings_random(char** arr_strings, const int count_of_strings)
{
    for (int i = 0; i < count_of_strings; ++i)
    {
        int n = rand() % (length - 1 - minlength) + minlength;
        for (int j = 0; j < n; ++j)
        {
            arr_strings[i][j] = rand() % (ascii_finish - ascii_start) + ascii_start;
        }
        arr_strings[i][n] = '\0';
    }
}
void Show_arr_strings(char** arr_strings, const int count_of_strings)
{
    cout << "\narr_cstrings:" << endl;
    for (int i = 0; i < count_of_strings; ++i)
    {
        cout << arr_strings[i] << endl;
    }
}
void Menu(char** arr_strings, const int count_of_strings)
{
    cout << "\nChoice the filling method:" << endl <<
    "1. Yourself." << endl <<
    "2. Random." << endl;
    
    int solution = 0;
    bool flag = true;
    
    while (flag)
    {
        cout << "Your choice: ";
        cin >> solution;
        
        if (solution == 1 || solution == 2)
        {
            flag = false;
        }
        
        switch (solution)
        {
            case 1:
            {
                Fill_arr_strings_yourself(arr_strings, count_of_strings);
            }
                break;
            case 2:
            {
                Fill_arr_strings_random(arr_strings, count_of_strings);
            }
                break;
            default:
            {
                cout << "Error. Please try again..." << endl;
            }
                break;
        }
    }
}
void Delete(char** arr_strings, const int count_of_strings)
{
    for (int i = 0; i < count_of_strings; ++i)
    {
        delete[] arr_strings[i];
    }
    delete[] arr_strings;
}



bool Comparison(char** arr, int FirstPoze, int SecondPoze)
{
    return strcmp(arr[FirstPoze], arr[SecondPoze]) <= 0;
}


