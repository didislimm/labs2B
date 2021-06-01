/*
 +• сложение, вычитание, умножение, деление на число
 +• сложение, вычитание, умножение на другую матрицу
 +• комбинированные операции присваивания (+=, -=, *=, /=);
 +• операции сравнения на равенство/неравенство;
 +• операции вычисления транспонированной матрицы;
 +• операцию возведения в степень;
 +• методы, реализующие проверку типа матрицы (квадратная, диаго-
 нальная, нулевая, единичная, симметричная, верхняя треугольная,
 нижняя треугольная);
 +• операции ввода/вывода матрицы в стандартные потоки.
 
 */
//template <class T>
//Vector<T>& Matrix::operator[](int index)
//{
//    try
//    {
//        if (index < 0 || index >= valueOfStrings)
//        {
//            throw index;
//        }
//        return matrix[index];
//    }
//    catch (int)
//    {
//        cerr << "Index: " << index << "is out of range!" << endl;
//        exit(900);
//    }
//}
#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include "vector.hpp"
using namespace std;
class Matrix{
    string name;
     static int value;
    
    Vector< Vector<double> > matrix;
    int valueOfStrings;
    int valueOfColumns;
    
    friend ostream& operator<<(ostream& out, const Matrix& matrixToOut);
public:
    Matrix();
    Matrix(int m,int n);
    Matrix(const Matrix&anotherMatrix);
    ~Matrix();
    
    Matrix operator+(double );
    Matrix operator-(double );
    Matrix operator*(double );
    Matrix operator/(double );
    
    Matrix operator+=(double );
    Matrix operator-=(double );
    Matrix operator*=(double );
    Matrix operator/=(double );
    
    
    Matrix operator+(const Matrix& );
    Matrix operator-(const Matrix& );
    Matrix operator*(const Matrix& );
  //  Matrix operator=(const Matrix& );
    
    Matrix operator+=(const Matrix& );
    Matrix operator-=(const Matrix& );
    Matrix operator*=(const Matrix& );
    
    void isSimilar(const Matrix& anotherMatrix);
    
    Matrix transponed();
    Matrix pow(int );
    
    bool isSquared();
    bool isDiagonaled();
    bool isZero();
    bool isUnit();//единичная
    bool isSymmetrical();
    bool isUpperTriangular();
    bool isUnderTriangular();
    
    void random();
    
    template <class P>
    P& operator[](const int index) {
        try {
            if (index < 0 or index >= valueOfStrings) {
                throw ;
            }
            return matrix[index];
        } catch (...) {
            cout<< "Bounce of range" <<endl;
            
        }
    }
    
};

int Matrix::value=0;

Matrix::Matrix(){
    value++;
    name="Matrix "+to_string(value);
    valueOfColumns=0;
    valueOfStrings=0;
}
Matrix::Matrix(int str,int col){
   
    try{
        if(str<0){
            throw ;
        }
        if(col<0){
            throw ;
        }
    }
    catch(...){
        cout<<"Wrong size"<<endl;
    }
    value++;
    name="Matrix "+to_string(value);
    if(str==0 or col==0)
    {
        valueOfStrings=0;
        valueOfColumns=0;
        cout<<"Zero Matrix"<<endl;
    }
    else{
        valueOfStrings=str;
        valueOfColumns=col;
        Vector <double>temp;
        matrix.resize(valueOfStrings,temp);
        for(int i=0;i<valueOfStrings;++i){
            matrix[i].resize(valueOfColumns,0);//3=0
        }
    }
}
Matrix::Matrix(const Matrix &anotherMatrix){
    valueOfColumns=anotherMatrix.valueOfColumns;
    valueOfStrings=anotherMatrix.valueOfStrings;
    matrix=anotherMatrix.matrix;
}
Matrix::~Matrix(){
    for(int i=0;i<valueOfStrings;i++){
        matrix[i].clear();
    }
    value--;
    matrix.clear();
}

ostream& operator<<(std::ostream& out, const Matrix& matrixToOut) {
    out << matrixToOut.name << " (" << matrixToOut.valueOfStrings << "x" << matrixToOut.valueOfColumns << ")" <<endl;
        for (int i = 0; i < matrixToOut.valueOfStrings; ++i) {
            for (int j = 0; j < matrixToOut.valueOfColumns; ++j) {
                out << setw(5) << matrixToOut.matrix[i][j];
            }
            out<<endl;
        }
        return out;
    }


Matrix Matrix::operator+(double value){
    for(int i=0;i<valueOfStrings;i++){
        for(int j=0;j<valueOfColumns;j++){
            matrix[i][j]+=value;
        }
    }
    return *this;
}

Matrix Matrix::operator-(double value){
    for(int i=0;i<valueOfStrings;i++){
        for(int j=0;j<valueOfColumns;j++){
            matrix[i][j]-=value;
        }
    }
    return *this;
}

Matrix Matrix::operator*(double value){
    for(int i=0;i<valueOfStrings;i++){
        for(int j=0;j<valueOfColumns;j++){
            matrix[i][j]*=value;
        }
    }
    return *this;
}

Matrix Matrix::operator/(double value){
    for(int i=0;i<valueOfStrings;i++){
        for(int j=0;j<valueOfColumns;j++){
            matrix[i][j]/=value;
        }
    }
    return *this;
}

Matrix Matrix::operator+=(double value){
    *this=*this+value;
    return *this;
}
Matrix Matrix::operator-=(double value){
    *this=*this-value;
    return *this;
}
Matrix Matrix::operator*=(double value){
    *this=*this*value;
    return *this;
}
Matrix Matrix::operator/=(double value){
    *this=*this/value;
    return *this;
}
Matrix Matrix::operator+(const Matrix& anotherMatrix){
    if(valueOfStrings!=anotherMatrix.valueOfStrings or valueOfColumns!=anotherMatrix.valueOfColumns){
        cout<<"Error of Size"<<endl;
    }
    else{
        for(int i=0;i<valueOfStrings;i++){
            for(int j=0;j<valueOfColumns;j++){
                matrix[i][j]+=anotherMatrix.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& anotherMatrix){
    if(valueOfStrings!=anotherMatrix.valueOfStrings or valueOfColumns!=anotherMatrix.valueOfColumns){
        cout<<"Error of Size"<<endl;
    }
    else{
        for(int i=0;i<valueOfStrings;i++){
            for(int j=0;j<valueOfColumns;j++){
                matrix[i][j]-=anotherMatrix.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& anotherMatrix){
   // Matrix result(valueOfStrings,anotherMatrix.valueOfColumns);
    if( valueOfColumns!=anotherMatrix.valueOfStrings){//матрицы можно перемножить если их размеры M*N и N*T
        cout<<"Error of Size"<<endl;
    }
    else{
        //создаем результирующую матрицу правильными размерами M*T
        for(int i=0;i<valueOfStrings;i++){
            for(int j=0;j<valueOfColumns;j++){
                matrix[i][j]+=matrix[i][j]*anotherMatrix.matrix[i][j];
            }
        }
    }
    return *this;
}


Matrix Matrix::operator+=(const Matrix& anotherMatrix){
    *this=*this+anotherMatrix;
    return *this;
}
Matrix Matrix::operator-=(const Matrix& anotherMatrix){
    *this=*this-anotherMatrix;
    return *this;
}
Matrix Matrix::operator*=(const Matrix& anotherMatrix){
    *this=*this*anotherMatrix;
    return *this;
}

void Matrix::isSimilar(const Matrix&anotherMatrix){
    if(valueOfColumns!=anotherMatrix.valueOfColumns or valueOfStrings!=anotherMatrix.valueOfStrings){
        cout<<"Error of Size"<<endl;
    }
    for(int i=0;i<valueOfStrings;i++){
        for(int j=0;j<valueOfColumns;j++){
            matrix[i][j]!=anotherMatrix.matrix[i][j];
            cout<<"false"<<endl;
            exit(100);
        }
    }
    cout<<"true"<<endl;
}

bool Matrix::isSquared(){
    return valueOfColumns==valueOfStrings;
}
bool Matrix::isDiagonaled(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            if (i!=j and matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool Matrix::isZero(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            if ( matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool Matrix::isUnit(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            if (i==j and  matrix[i][j] != 1) {
                return false;
            }
            if (i!=j and matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetrical(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isUpperTriangular(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            if (i>j and  matrix[j][i]!=0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isUnderTriangular(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            if (i<j and  matrix[j][i]!=0) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::transponed(){
    Matrix result(valueOfColumns,valueOfStrings);
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            result.matrix[i][j]=matrix[j][i];
        }
    }
    return result;
}
Matrix Matrix::pow(int rank){
    if(!isSquared()){
        cout<<"Error with size"<<endl;
    }
    for(int i=0;i<rank-1;++i){
        *this*=*this;
    }
    return *this;
}

void Matrix::random(){
    for (int i = 0; i < valueOfStrings; ++i) {
        for (int j = 0; j < valueOfColumns; ++j) {
            matrix[i][j]=rand()%50;
        }
  }
}
