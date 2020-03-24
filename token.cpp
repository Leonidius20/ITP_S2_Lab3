#include "token.h"
#include <cmath>
#include <stdexcept>

using namespace std;

double Operator1::apply(double a, double b) {
    if (signature == "+") {
        return a + b;
    } else if (signature == "-") {
        return a - b;
    } else if (signature == "*") {
        return a * b;
    } else if (signature == "/") {
        return a / b;
    } else if (signature == "^") {
        return pow(a, b);
    } else {
        throw invalid_argument("Unknown operator: " + signature);
    }
}
