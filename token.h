#pragma once

#include <string>
#include <stdexcept>
#include <map>

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
    static std::map<char, Operator> operatorMap;

    Operator(const int precedence, char signature) : precedence(precedence), signature(signature) {}
public:
    static Operator get(char signature);

    bool isOperator() override { return true; };

    [[nodiscard]] int getPrecedence() const { return precedence; }

    double apply(double a, double b);
};
