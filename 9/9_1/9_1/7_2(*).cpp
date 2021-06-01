//#include <vector>
//#include <iostream>
//#include <ctime>
//#include <iomanip>
//#include <stdlib.h>
//using namespace std;
//void input(vector<vector<int>> &array,int n){
//    for (int i = 0; i < n; i++)
//    for (int j = 0; j < n; j++)
//    array[i][j] = rand() % 20;
//}
//void output (vector<vector<int>> &array, int n)
//{
//    for (int i = 0; i < n; i++)
//    { for (int j = 0; j < n; j++)
//        cout << setw(5) << array[i][j];
//        cout << endl;
//    }
//}
//void draw(){
//    for(int i=0;i<30;i++){
//        cout<<"-";
//    }
//    cout<<endl;
//}
//
//void sum(vector<vector<int>> &BC,vector<vector<int>> &B,vector<vector<int>> &C,int size)
//{
//   
//    for(int i = 0; i < size; ++i){
//        for(int j = 0; j < size; ++j){
//            BC[i][j] = B[i][j] + C[i][j];
//        }
//    }
//}
//
//void multiPlay(vector<vector<int>> &D,vector<vector<int>> &BC,vector<vector<int>> &A,int size)
//{
//    for(int i = 0; i < size; i++){
//        for(int j = 0; j < size; j++){
//            for(int k=0;k<size;k++){
//                D[i][j] += A[i][k]*BC[k][j];
//            }
//        }
//    }
//    
//}
//int main(){
//    int n=0;
//    cout<<"Input size of Matrix:"<<'\n';
//    cin>>n;
//    
//    vector<vector<int>> A(n, vector <int> (n) );
//    input(A, n);
//    cout<<"Array A:"<<'\n';
//    output(A, n);
//    draw();
//    
//    vector<vector<int>> B(n, vector <int> (n) );
//    input(B, n);
//    cout<<"Array B:"<<'\n';
//    output(B, n);
//    draw();
//    
//    vector<vector<int>> C(n, vector <int> (n) );
//    input(C, n);
//    cout<<"Array C:"<<'\n';
//    output(C, n);
//    draw();
//    
//    vector<vector<int>> BC(n, vector <int> (n) );
//    sum(BC, B, C, n);
//    cout<<"Array BC:"<<'\n';
//    output(BC, n);
//    draw();
//    
//    vector<vector<int>> D(n, vector <int> (n) );
//    multiPlay(D, BC, A, n);
//    cout<<"Array D:"<<'\n';
//    output(D, n);
//    draw();
//}
