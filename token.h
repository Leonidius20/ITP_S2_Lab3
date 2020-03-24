#pragma once

#include <string>
#include <stdexcept>

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
    const char signature;

    Operator(const int precedence, char signature) : precedence(precedence), signature(signature) {} // NOLINT(modernize-pass-by-value)
public:
    static Operator get(char signature);

    bool isOperator() override { return true; };

    [[nodiscard]] int getPrecedence() const { return precedence; }

    double apply(double a, double b);
};
