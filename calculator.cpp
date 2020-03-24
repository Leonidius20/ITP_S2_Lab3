#include <vector>
#include "token.h"
#include "stack.h"
#include "calculator.h"
#include <exception>

using namespace std;

double compute(const vector<Token *> &tokens) {
    Stack<Number *> numbers;
    for (auto token : tokens) {
        if (!token->isOperator()) {
            auto numberToken = dynamic_cast<Number *>(token);
            numbers.push(numberToken);
        } else {
            auto operatorToken = dynamic_cast<Operator *>(token);
            double operand1 = numbers.pop()->getValue(),
                    operand2 = numbers.pop()->getValue();
            double value = operatorToken->apply(operand1, operand2);
            numbers.push(new Number(value));
        }
    }
    if (numbers.size() == 0) { // TODO: replace with isEmpty()
        throw exception("compute(): ill-formed input");
    }
    return numbers.pop()->getValue();
}