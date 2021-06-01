#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

template <class T>
void input(istream& in, T& data)
{
    while (true)
    {
        in >> data;

        if (in.fail())
        {
            in.clear();
            in.ignore(INT_MAX, '\n');

            cout << "An incorrect value. Please try again:" << endl;

            continue;
        }
        else
        {
            break;
        }
    }
}

void correction(string& expression)
{
    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == ' ')
        {
            expression.erase(i, 1);
            i--;
        }
    }

    char last = expression[expression.size() - 1];

    if (last != '=')
    {
        if (last == '*' || last == '/' || last == '*' || last == '+' || last == '-' || last == '(')
        {
            expression.pop_back();
        }
        expression.push_back('=');
    }
}

string convertToRPN(string expression)
{
    correction(expression);

    string result;
    result.clear();

    multimap<char, int> symbols;
    symbols.insert(make_pair('*', 3));
    symbols.insert(make_pair('/', 3));
    symbols.insert(make_pair('+', 2));
    symbols.insert(make_pair('-', 2));
    symbols.insert(make_pair('(', 1));
    symbols.insert(make_pair('=', 0));

    list<string> operands;
    list<char> signs;

    for (int i = 0; i < expression.size(); ++i)
    {
        string currentOperand;
        currentOperand.clear();

        multimap<char, int>::iterator iMapSym = symbols.find(expression[i]);
        if (iMapSym == symbols.end()) // ÂÒÎË ˜ËÒÎÓ
        {
            while (i < expression.size() && iMapSym == symbols.end())
            {
                if (expression[i] == ')')
                {
                    break;
                }
                currentOperand.push_back(expression[i]);
                iMapSym = symbols.find(expression[++i]);
            }

            operands.push_back(currentOperand);
        }

        
        if (expression[i] == ')')
        {
            list<char>::reverse_iterator iMoveSigns = signs.rbegin();
            while (iMoveSigns != signs.rend() && (*iMoveSigns) != '(')
            {
                string charToString;
                charToString = *iMoveSigns;
                operands.push_back(charToString);
                signs.erase(next(iMoveSigns).base());
            }
            if ((*iMoveSigns) == '(')
            {
                signs.erase(next(iMoveSigns).base());
            }
        }

        if (iMapSym != symbols.end())
        {
            signs.push_back(iMapSym->first);
        }

        // iMapSym - ÒÎÂ‰Û˛˘ËÈ ÁÌ‡Í Á‡ ˜ËÒÎÓÏ
        if (signs.size() > 1 && iMapSym != symbols.end() && iMapSym->first != '(')
        {
            list<char>::reverse_iterator headSigns = signs.rbegin(); // ‚Â¯ËÌ‡ ÒÔËÒÍ‡ ÁÌ‡ÍÓ‚
            ++headSigns;
            map<char, int>::iterator headSignsMap = symbols.find(*headSigns); // ‚Â¯ËÌ‡ ÒÔËÒÍ‡ ÁÌ‡ÍÓ‚ ‚ map
            while (headSigns != signs.rend() && iMapSym->second <= headSignsMap->second)
            {
                string charToString;
                charToString = *headSigns;

                operands.push_back(charToString);
                signs.erase(next(headSigns).base());

                headSigns = signs.rbegin();
                if (signs.size() > 1)
                {
                    ++headSigns;
                    headSignsMap = symbols.find(*headSigns);
                }
                else if (expression[i] == '=')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }

    list<string>::iterator iOperands = operands.begin();
    while (iOperands != operands.end())
    {
        result += *iOperands + " ";
        ++iOperands;
    }

    return result;
}

double calculateRPN(string polExpression)
{
    double result = 0;

    multimap<char, int> symbols;
    symbols.insert(make_pair('*', 3));
    symbols.insert(make_pair('/', 3));
    symbols.insert(make_pair('+', 2));
    symbols.insert(make_pair('-', 2));
    symbols.insert(make_pair('(', 1));
    symbols.insert(make_pair('=', 0));

    list<string> operands;

    for (int i = 0; i < polExpression.size(); ++i)
    {
        string currentOperand;
        currentOperand.clear();

        while (polExpression[i] != ' ')
        {
            currentOperand.push_back(polExpression[i++]);
        }

        operands.push_back(currentOperand);
    }

    list<string>::iterator iOperands = operands.begin();
    while (iOperands != operands.end())
    {
        if ((*iOperands)[0] == '=')
        {
            --iOperands;
            result = stod(*iOperands);
            break;
        }

        multimap<char, int>::iterator iMapSym = symbols.find((*iOperands)[0]);
        if (iMapSym != symbols.end())
        {
            --iOperands; --iOperands;
            double firstOperand = stod(*iOperands);
            ++iOperands;
            double secondOperand = stod(*iOperands);
            --iOperands;

            double resultOperand = 0;

            switch (iMapSym->first)
            {
            case '*':
                resultOperand = firstOperand * secondOperand;
                break;
            case '/':
                resultOperand = firstOperand / secondOperand;
                break;
            case '+':
                resultOperand = firstOperand + secondOperand;
                break;
            case '-':
                resultOperand = firstOperand - secondOperand;
                break;
            default:
                cerr << "OPERATION NOT DEFINED" << endl;
                exit(0);
                break;
            }

            iOperands = operands.erase(iOperands);
            iOperands = operands.erase(iOperands);
            iOperands = operands.erase(iOperands);

            operands.insert(iOperands, to_string(resultOperand));

            iOperands = operands.begin();
        }
        else
        {
            ++iOperands;
        }
    }

    return result;
}
