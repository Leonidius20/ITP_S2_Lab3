#include "token.h"
#include <cmath>
#include <stdexcept>

using namespace std;

double Operator::apply(double a, double b) {
    if (signature == '+') {
        return a + b;
    } else if (signature == '-') {
        return a - b;
    } else if (signature == '*') {
        return a * b;
    } else if (signature == '/') {
        return a / b;
    } else if (signature == '^') {
        return pow(a, b);
    } else {
        throw invalid_argument("Unknown operator: " + to_string(signature));
    }
}

map<char, Operator> Operator::operatorMap = {
        {'+', Operator(1, '+')},
        {'-', Operator(1, '-')},
        {'*', Operator(2, '*')},
        {'/', Operator(2, '/')},
        {'^', Operator(3, '^')},
};

Operator Operator::get(char signature) {
    if (!operatorMap.contains(signature)) {
        throw invalid_argument("Unknown operator: " + to_string(signature));
    }
    return operatorMap[signature];
}
