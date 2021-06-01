/*Выполнить задания, используя двусвязные динамические структуры данных в
 виде связных компонент. Оценить асимптотическую сложность алгоритма.
 2. Даны натуральное число n, действительные числа x1, x2, ... xn. Разработать программу вычисления значения выражения следующего вида:
*/
#include "7_6.hpp"
int main()
{
    int n=0;
    n=Input();
    Node *top=NULL,*end=NULL;
    for(int i=n;i>0;i--){
        add(top, end);
    }
    output(top);
    cout<<'\n';
    //output1(end); Вывод с конца
    cout<<'\n';
    double res=0;
    res=result(top,end);
    cout<<"Result multiplication  "<< res<<'\n';
    
    
}

