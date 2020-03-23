#pragma once

class Token {
public:
    virtual bool isOperator() = 0;
};

class Number : public Token {
public:
    double getValue() const;
    bool isOperator() override { return false; };
};

class Operator : public Token {
public:
    bool isOperator() override { return true; };
    int getPrecedence() const;
    void apply();
};