
#include "Matrix.hpp"

using namespace std;

int main()
{
    srand(time(nullptr));
    //чтобы не было проблем с перемножением я ввел размеры сам 
    int m=2;
    int n=2;
    Matrix A(m,n),B(m,n),C(m,n),BC(m,n),D(m,n);
    A.random();
    cout<<A<<endl;

    B.random();
    cout<<B<<endl;

    C.random();
    cout<<C<<endl;

    BC=B+C;
    cout<<BC<<endl;

    D=BC*A;
    cout<<"Result "<<D<<endl;

    A.pow(2);
    cout<<A;
}
