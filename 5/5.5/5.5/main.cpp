//
//  main.cpp
//  5.5
//
//  Created by Егор Миронов on 4.03.21.
//

#include <iostream>
#include "main_5.hpp"
#include <cmath>
#include <iomanip>
using namespace std;
void printSolution(double (*funcPtr)(char, double), double xi, int iterations) {
    cout << setw(10) << xi << setw(20) << (*funcPtr)('F', xi) << setw(20) << iterations << endl;
}
void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations) {
    cout << setw(10) << param << setw(20) << xi << setw(20) << (*funcPtr)('F', xi, param) << setw(20) << iterations << endl;
}
void printTableHeader(int type) {
    if (type == 0) {
        cout << setw(10) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    }
    if (type == 1) {
        cout << setw(10) << "S" << setw(20) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    }
}

bool argsCorrect(double &leftBorder, double &rightBorder, double &x0) {
    return leftBorder <= rightBorder and leftBorder <= x0 and rightBorder >= x0;
}

double function(char type, double x) {
    switch (type) {
        case 'F': {
            return x*x*x - 3;
        }
        
        default: {
            return 0;
        }
            
    }
}
double function1(char type, double x, double param) {
    switch (type) {
        case 'F': {
            return pow(x*x*x,1/param)-2* cos(M_PI * x/2) * cos(M_PI * x/2);
        }
        default: {
            return 0;
       }
    }
}
void solveHalfDivision(double (*funcPtr)(char, double), double leftBorder, double rightBorder, double epsilon) {
    if ((*funcPtr)('F', leftBorder) * (*funcPtr)('F', rightBorder) > 0) {
        cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
        return;
    }
    int iterations = 0;
    double xi = (leftBorder + rightBorder) / 2;
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        if ((*funcPtr)('F', leftBorder) * (*funcPtr)('F', xi) < 0) {
            xi = (leftBorder + xi) / 2;
        } else {
            xi = (rightBorder + xi) / 2;
        }
        iterations++;
    }
    printSolution(funcPtr, xi, iterations);
}
void solveHalfDivision(double (*funcPtr)(char, double, double), double leftBorder, double rightBorder, double epsilon, double paramMin, double paramMax, double deltaParam) {
    double sLB = leftBorder;
    double sRB = rightBorder;
    int iterations = 0;
    double xi = (leftBorder + rightBorder) / 2;
    int n = ceil((paramMax - paramMin) / deltaParam);
    for (int i = 0; i <= n; ++i) {
        double param = paramMin + deltaParam * i;
        if ((*funcPtr)('F', leftBorder, param) * (*funcPtr)('F', rightBorder, param) > 0) {
            cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
            break;
        }
        while ((abs((*funcPtr)('F', xi, param))) > epsilon) {
            if ((*funcPtr)('F', leftBorder, param) * (*funcPtr)('F', xi, param) > 0) {
                leftBorder = xi;
            } else {
                rightBorder = xi;
            }
            xi = (leftBorder + rightBorder) / 2;
            iterations++;
        }
        printSolution(funcPtr, xi, param, iterations);
        leftBorder = sLB;
        rightBorder = sRB;
        xi = (leftBorder + rightBorder) / 2;
        iterations = 0;
    }
}

