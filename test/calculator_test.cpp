#include "gtest/gtest.h"
#include <vector>
#include "calculator.h"

using namespace std;

TEST(CalculatorTest, ComputeTest) {
    vector<Token*> tokens;
    tokens.push_back(new Number(1));
    tokens.push_back(new Number(2));
    tokens.push_back(Operator::get('+'));
    ASSERT_EQ(3, compute(tokens));
    // test
}