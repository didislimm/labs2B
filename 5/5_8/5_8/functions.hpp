#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#define RAND 1.156
#define length 30
#define minlength 5
#define ascii_start 65
#define ascii_finish 90

using namespace std;

void Null(char** arr_strings, const int count_of_strings, const int len);
void Fill_arr_strings_yourself(char** arr_strings, const int count_of_strings, const int len);
void Fill_arr_strings_random(char** arr_strings, const int count_of_strings, const int len);
void Show_arr_strings(char** arr_strings, const int count_of_strings);
void Menu(char** arr_strings, const int count_of_strings);
void Delete(char** arr_strings, const int count_of_strings);

bool Comparison(char** arr, int firstpoze, int secondpoze);

template <class T>
void FillArray(T* Arr, const int size)
{
    int min = 0;
    int max = 0;
    
    bool flag = true;
    
    while (flag)
    {
        cout << "\nEnter the MAX value for generation: ";
        cin >> max;
        cout << "Enter the MIN value for generation: ";
        cin >> min;
        
        if (max >= min)
        {
            flag = false;
        }
        else
        {
            cout << "Your enter is not correct. Please try again..." << endl;
        }
    }
    
    
    for (int i = 0; i < size; ++i)
    {
        Arr[i] = RAND * ((rand() % (max - 1 - min)) + min);
    }
}

template <class T>
void ShowArray(T* Arr, const int size)
{
    cout << "\nYour array: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << Arr[i] << "\t";
    }
}

template <class T>
bool Comparison(T* arr, int FirstPoze, int SecondPoze)
{
    return arr[FirstPoze] < arr[SecondPoze];
}

template <class T>
void Merg(T arr[], const int size, int begin, int end)
{
    int i = begin;
    int mid = begin + (end - begin) / 2;
    int j = mid + 1;
    int k = 0;
    T* d = new T[size];
    
    while (i <= mid && j <= end)
    {
        bool flag = Comparison(arr, i, j);
        
        if (flag)
        {
            d[k] = arr[i];
            ++i;
        }
        else
        {
            d[k] = arr[j];
            ++j;
        }
        ++k;
    }
    
    while (i <= mid)
    {
        d[k] = arr[i];
        ++i;
        ++k;
    }
    
    while (j <= end)
    {
        d[k] = arr[j];
        ++j;
        ++k;
    }
    
    for (int i = 0; i < k; ++i)
    {
        arr[begin + i] = d[i];
    }
    
    delete[] d;
}
template <class T>
void MergSort(T* arr, const int size, int left, int right)
{
    if (left < right)
    {
        if (right - left == 1)
        {
            bool flag = Comparison(arr, right, left);
            
            if (flag)
            {
                swap(arr[left], arr[right]);
            }
        }
        else
        {
            MergSort(arr, size, left, left + (right - left) / 2);
            MergSort(arr, size, left + (right - left) /2 +1, right);
            Merg(arr, size, left, right);
        }
    }
}

