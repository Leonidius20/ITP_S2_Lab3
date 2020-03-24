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
    Operator::destroyMap();

    ASSERT_EQ(3, result);

}