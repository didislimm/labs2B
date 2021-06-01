//6+(4-1)*2-3/(7+5)=
#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main(void)
{
    cout << "Enter an expression:" << endl;
    string expression;
    expression.clear();
    getline(cin, expression);

    string polExpression = convertToRPN(expression);
    double result = calculateRPN(polExpression);

    cout << "This expression in reverse Polish notation:" << endl;
    cout << polExpression << " " << result << endl;

}
