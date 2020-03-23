#pragma once

#include <vector>
#include <string>
#include "token.h"

std::vector<Token> parse(const std::string& str);
double compute(const std::vector<Token>& tokens);