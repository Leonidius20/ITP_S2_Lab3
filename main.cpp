#include <iostream>
#include <string>
#include <vector>
#include "shunting_yard.h"
#include "token.h"
#include "calculator.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Arithmetic expression is not specified" << endl;
        return 0;
    }

    string expression;
    for (int i = 1; i < argc; i++) {
        expression.append(argv[i]);
    }

    try {
        auto tokens = parse(expression);
        double result = compute(tokens);
        cout << result << endl;

        for (auto token : tokens) { // use smart pointers instead
            delete token;           // because what if we don't reach this code at all
                                    // due to an exception?
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    Operator::destroyMap();
}
