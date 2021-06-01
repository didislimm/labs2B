#include <iostream>

using namespace std;

int is_safe(int rows[8], int x, int y)
{
    int i;
    if (y == 0)
    {
        return 1;
    }
    for (i = 0; i < y; ++i)
    {
        if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y + i)//
        {
            return 0;
        }
    }
    return 1;
}

void out(int rows[8],int &count)
{
    count++;
    int x, y;
    cout << "\nSolution #"<<count<< ":\n---------------------------------\n";
    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 8; x++)
        {
            if (x == rows[y])
            {
                cout << "| B ";
            }
            else
            {
                cout << "|   ";
            }
        }
        cout << "|\n---------------------------------\n";
    }
}

void eightBishops(int rows[8], int y,int &count)
{
    int x;
    for (x = 0; x < 8; x++) {
        if (is_safe(rows, x, y))
        {
            rows[y] = x;
            if (y == 7)
            {
                out(rows,count);
            }
            else
            {
                eightBishops(rows, y + 1,count);
            }
        }
    }
}


int main()
{
    int rows[8];
    int count = 0;
    eightBishops(rows,0,count);
    cout << '\n';
}
