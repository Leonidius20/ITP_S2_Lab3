#include <vector>
#include "token.h"
#include "stack.h"
#include "calculator.h"

using namespace std;

double compute(const vector<Token*>& tokens) {
    Stack<Number*> numbers;
    for (auto token : tokens) {
        if (!token->isOperator()) {
            auto number = dynamic_cast<Number*>(token);
            numbers.push(number);
        } else {
            auto oper = dynamic_cast<Operator*>(token);
            numbers.push(new Number(oper->apply(numbers.pop()->getValue(), numbers.pop()->getValue())));
        }
        delete token;
    }
    return numbers.pop()->getValue();
}