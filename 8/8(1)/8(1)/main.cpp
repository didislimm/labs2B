#include "8_1.hpp"
int main(){
    srand(time(nullptr));
    cout<<"Input value of digits \n";
    int n=0;
    cin>>n;
    Vect<int> vector(n, 0);
    vector.createFile(n);
    int k=0;
    k=vector.fill();
    Vect <int> result(k);
    vector.getArr(result);
    cout<<result;
}
