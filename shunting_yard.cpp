#include <vector>
#include <string>
#include "token.h"
#include "stack.h"

using namespace std;

vector<Token *> parse(const string &str) {
    vector<Token *> output;
    Stack<Token *> stack;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isspace(c)) continue;

        if (Operator::isOperator(c)) {
            auto o1 = Operator::get(c);
            while (!stack.empty()) {
                auto token = stack.peek();
                if (!token->isOperator()) break;

                auto o2 = dynamic_cast<Operator *>(stack.peek());
                if (o1->getPrecedence() > o2->getPrecedence()) break;

                output.push_back(stack.pop());
            }
            stack.push(o1);
        } else if (c == '(') {
            stack.push(OpeningBracket::getInstance());
        } else if (c == ')') {
            while (!stack.empty()) {
                auto token = stack.pop();
                if (token->isOperator()) {
                    output.push_back(token);
                } else break;
            }
        } else {
            int start = i++;
            for (; i < str.length() && (isdigit(str[i]) || str[i] == '.'); ++i) {}

            double number = stoi(str.substr(start, i - start));
            auto token = new Number(number);
            output.push_back(token);

            i--;
        }
    }

    while (!stack.empty()) {
        output.push_back(stack.pop());
    }

    return output;
}
