/*2. Описать функцию, которая формирует список символов L2, включив в не-
 го те символы из L1, которые входят в него более одного раза.*/
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
using namespace std;
//struct Person
//{
//    string name;
//    string surname;
//    int age;
//    int course;
//    int score;
//};
template <class T>
void printList(const list<T>&lst){
    for(auto i=lst.cbegin();i!=lst.cend();++i){
        cout<<*i<<" ";
    }
    cout<<'\n';
}
template <class T>
void result( list<T>&res,list<T>&lst){// i-указывает на элемент j-на следующий
    auto j=lst.cbegin();
    for(auto i=lst.cbegin();i!=lst.cend();++i){
        *j++;
        bool skip=false;// если в списке будет идти 5555
          if(*i==*j)//то в результирующий запишет только 1 раз 5
        {
            skip = true;
            res.push_back(*i);
        }
        if (skip==true) {
            while(*i==*j){
                i++;
                j++;
            }
        }
   }
}
template <class T>
double multiplay(vector<T>&arr){
    double m=1;
    for(int i=0,j=arr.size();i<arr.size();i++,j--){
        m*=arr[i]+arr[j];
    }
    return m;
}
char Generation_of_simbol()
{
    char simbol;
    bool selector = false;
    
    selector = rand() % 2;
    
    if (selector == false)
    {
        simbol = rand() % ('z' - 'a') + 'a';
    }
    else
    {
        simbol = rand() % ('Z' - 'A') + 'A';
    }
    return simbol;
}

int main(){
    srand(time(nullptr));
    cout<<"Input value of symbols for 7.4"<<endl;
    int n=0;
    cin>>n;
    list<char> mylist;
    list<char>res;
    
    for(int i=0;i<n;++i){
        char k= Generation_of_simbol();
        mylist.push_back(k);
    }
    printList(mylist);
    mylist.sort();
    cout<<"Sorted list"<<endl;
    printList(mylist);
    cout<<"Result list"<<endl;
    result(res,mylist);
    printList(res);
    
    vector<int> array;
    cout<<"Input value of digits for 7.6"<<endl;
    int k=0;
    cin>>k;
    for(int i=0;i<k;i++){
        int k=rand()%10;
        array.push_back(k);
    }
    double mult=multiplay(array);
    cout<<"Result multiplay: "<<mult<<endl;
    
//    list<struct Person>student;
//    cout<<"Input value of students for 7.3"<<endl;
//    int l=0;
//    cin>>l;
//    for(int i=0;i<l;i++){
//       
//    }
}
