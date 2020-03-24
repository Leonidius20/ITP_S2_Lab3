#pragma once

#include <string>

class Token {
public:
    virtual bool isOperator() = 0;
};

class Number : public Token {
private:
    const double value;
public:
    explicit Number(double value) : value(value) {}

    [[nodiscard]] double getValue() const { return value; };

    bool isOperator() override { return false; };
};

class Operator : public Token {
private:
    const int precedence;
    const std::string signature;
public:
    Operator(const int precedence, const std::string &signature) : precedence(precedence), signature(signature) {} // NOLINT(modernize-pass-by-value)

    bool isOperator() override { return true; };

    [[nodiscard]] int getPrecedence() const { return precedence; }

    double apply(double a, double b);
};
