#include <vector>
#include <string>
#include "token.h"
#include "stack.h"

using namespace std;

const char NOT_FOUND = -1;

bool shouldParseAsOperator(const string &str, int position);

vector<Token *> parse(const string &str) {
    vector<Token *> output;
    Stack<Token *> stack;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isspace(c)) continue;

        if (shouldParseAsOperator(str, i)) {
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

            double number = stod(str.substr(start, i - start));
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

bool shouldParseAsOperator(const string &str, int position) {
    char c = str[position];
    if (c != '-') {
        return Operator::isOperator(c);
    }

    char previous = NOT_FOUND;
    for (int i = position - 1; i >= 0; i--) {
        if (!isspace(str[i])) {
            previous = str[i];
            break;
        }
    }

    return previous != NOT_FOUND && previous != '(';
}
