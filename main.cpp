#include <iostream>
#include <string>
#include "shunting_yard.h"
#include "token.h"
#include "calculator.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 0) {
        cerr << "Arithmetic expression is not specified" << endl;
        return 0;
    }

    string expression;
    for (int i = 1; i < argc; i++) {
        expression.append(argv[i]);
    }

    auto tokens = parse(expression);
    double result = compute(tokens);
    cout << result << endl;

    for (Token *token : tokens) {
        if (token->isOperator()) {
            auto o = dynamic_cast<Operator *>(token);
            cout << o->getSignature();
        } else {
            auto number = dynamic_cast<Number *>(token);
            cout << number->getValue();
        }
        cout << " ";
    }

    Operator::destroyMap();
}
