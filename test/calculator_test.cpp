#include "gtest/gtest.h"
#include <vector>
#include "calculator.h"

using namespace std;

TEST(CalculatorTest, ComputeTest) {
    // 1 + 2
    auto *n1 = new Number(1), *n2 = new Number(2);
    auto op = Operator::get('+');

    vector<Token *> tokens;
    tokens.push_back(n1);
    tokens.push_back(n2);
    tokens.push_back(op);

    double result = compute(tokens);

    delete n1;
    delete n2;

    ASSERT_EQ(3, result);

    // 1 + 2 * (3 ^ 6)
    // in postfix notation 1 2 3 6 ^ * +
    vector<Token *> tokens2;
    tokens2.push_back(new Number(1));
    tokens2.push_back(new Number(2));
    tokens2.push_back(new Number(3));
    tokens2.push_back(new Number(6));
    tokens2.push_back(Operator::get('^'));
    tokens2.push_back(Operator::get('*'));
    tokens2.push_back(Operator::get('+'));

    ASSERT_EQ(1459.0, compute(tokens2));

    // 1 / 5 + 1 / (9 + 1)
    // in postfix notation  1 5 / 1 9 1 + / +
    // 0.2 1 9 1 + / +
    // 0.2 1 10 / +
    // 0.2 0.1 +
    // 0.3

    vector<Token *> tokens3;
    tokens2.push_back(new Number(1));
    tokens2.push_back(new Number(5));
    tokens2.push_back(Operator::get('/'));
    tokens2.push_back(new Number(1));
    tokens2.push_back(new Number(9));
    tokens2.push_back(new Number(1));
    tokens2.push_back(Operator::get('+'));
    tokens2.push_back(Operator::get('/'));
    tokens2.push_back(Operator::get('+'));

    ASSERT_EQ(0.3, compute(tokens3));
}