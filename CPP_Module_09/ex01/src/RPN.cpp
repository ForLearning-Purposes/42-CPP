#include "../inc/RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &src) {*this = src;}
RPN &RPN::operator=(const RPN &rhs) {(void)rhs; return *this;}
RPN::~RPN() {}

// *** VALIDATE EXPRESSION ***
void RPN::validateExpression(const std::string &expression) {
    for (int i = 0; i < static_cast<int>(expression.length()); ++i) {
        if (!isdigit(expression[i]) && expression[i] != '+' && expression[i] != '-' &&
            expression[i] != '*' && expression[i] != '/' && expression[i] != ' ') {
            throw std::invalid_argument("Invalid character in expression");
        }
    }
    unsigned long spaceCount = std::count(expression.begin(), expression.end(), ' ');
    unsigned long expectedSize = spaceCount + 1;
    if (expression.length() - spaceCount != expectedSize) {
        throw std::invalid_argument("Invalid expression format");
    }
    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] != ' ') {
            // Check that the current character is either at the start/end or surrounded by spaces
            if ((i > 0 && expression[i - 1] != ' ') || (i + 1 < expression.length() && expression[i + 1] != ' ')) {
                throw std::invalid_argument("Each token must be separated by a single space");
            }
        }
    }
    unsigned long operatorCount = 0;
    unsigned long numberCount = 0;
    for (size_t i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            numberCount++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operatorCount++;
        }
    }
    if (operatorCount != numberCount - 1) {
        throw std::invalid_argument("Invalid expression: number of operators must be one less than number of numbers");
    }
    if (!isdigit(expression[0]) || !isdigit(expression[2])) {
        if (expression.length() < 5 && (expression[4] != '+' || expression[4] != '-' ||
            expression[4] != '*' || expression[4] != '/')) // will never reach this point because of previous checks
            throw std::invalid_argument("Expression must start with two numbers in a row and an operator if len < 5");
        throw std::invalid_argument("Expression must start with two number in a row");
    }
}

/*
- is it Associativity and Evaluation Order
*/