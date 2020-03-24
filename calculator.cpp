#include <vector>
#include "token.h"
#include "stack.h"
#include "calculator.h"
#include <exception>
#include <iostream>

using namespace std;

/*void printStack(Stack<double> &stack) {
    vector<double> lol;
    while (stack.size() != 0) {
        lol.insert(lol.begin(), stack.pop());
    }
    for (double d : lol) {
        cout << d << " ";
    }
    cout << endl;
}*/

double compute(const vector<Token *> &tokens) {
    Stack<double> numbers;
    for (auto token : tokens) {
        if (!token->isOperator()) {
            auto numberToken = dynamic_cast<Number *>(token);
            numbers.push(numberToken->getValue());
            //printStack(numbers);
        } else {
            auto operatorToken = dynamic_cast<Operator *>(token);
            double operand2 = numbers.pop(), operand1 = numbers.pop();
            double value = operatorToken->apply(operand1, operand2);
            numbers.push(value);
            //printStack(numbers);
        }
    }
    if (numbers.size() == 0) { // TODO: replace with isEmpty()
        throw exception("compute(): ill-formed input");
    }
    return numbers.pop();
}