

#ifndef main_5_hpp
#define main_5_hpp
#include <stdio.h>
#endif main_5_hpp 
void printSolution(double (*funcPtr)(char, double), double xi, int iterations);
void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations);
//Вывод шапки таблицы.
// 0 - без параметра; 1 - с параметром
void printTableHeader(int type);

//Проверка правильности позиции аргументов
bool argsCorrect(double &leftBorder, double &rightBorder, double &x0);

//Функции
double function(char type, double x);
double function1(char type, double x, double param);
void solveHalfDivision(double (*funcPtr)(char, double), double leftBorder = 1, double rightBorder = 4, double epsilon = 1E-6);
void solveHalfDivision(double (*funcPtr)(char, double, double), double leftBorder = 0, double rightBorder = 4.5 , double epsilon = 1E-6, double paramMin = 0.5, double paramMax = 2, double deltaParam = 0.5);
