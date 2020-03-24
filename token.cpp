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

Operator Operator::get(char signature) {
    switch(signature) {
        case '+':
            return Operator(1, '+');
        case '-':
            return Operator(1, '-');
        case '*':
            return Operator(2, '*');
        case '/':
            return Operator(2, '/');
        case '^':
            return Operator(3, '^');
        default:
            throw std::invalid_argument("Unknown operator: " + std::to_string(signature));
    }
}
