

#include <iostream>
#include<iomanip>
#include<random>
#include<time.h>

using namespace std;
const int C = 127;

void input(char* mass, int n, int& start, int& end, bool& empt)
{
    for (int i = 0; i < n; i++)
    {
        char k = rand() % 100;//94+33
        if (empt)
        {
            start = 0;
            mass[start] = k;
            empt = false;
            end = start;
        }
        else
        {
            end++;
            mass[end] = k;
        }
    }

}
void search(char *mass,int *mass1,int start,int end)//
{
    for(int i  = start;i <= end;i++)
    {
        mass1[mass[i]] = 1;
    }
}

void input_2(char *mass,int*mass2,int& start,int& end,bool& empt)
{
    for(int i = 33;i<227;i++)
    {
        if (mass2[i] == 0)
        {
            if (empt)
            {
                start = 0;
                mass[start] = i;
                empt = false;
                end = start;
            }
            else
            {
                end++;
                mass[end] = i;
            }
        }
    }
}

void output(char* mass, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << mass[i] << setw(5);
    }
}

int main()
{
    srand(time(NULL));
    int n,start= 0,end = 0;
    bool ent = true;
    cout << "How elements: ";
    cin >> n;
    char* mass = new char[n];
    int mass_1[C] = { 0 };
    input(mass, n,start,end,ent);
    output(mass, start, end);
    search(mass, mass_1, start, end);
    char* mass_2 = new char[C];
    int start_2 = 0, end_2 = 0;
    bool empt = true;
    cout << endl;
    cout << " _______________________________________________________________" << endl;
    input_2(mass_2, mass_1, start_2, end_2, empt);
    output(mass_2, start_2, end_2);
}

