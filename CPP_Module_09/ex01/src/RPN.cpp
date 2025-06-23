#include "../inc/RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &src) {*this = src;}
RPN &RPN::operator=(const RPN &rhs) {(void)rhs; return *this;}
RPN::~RPN() {}

// *** VALIDATE EXPRESSION ***
void RPN::validateExpression(std::string expression) {
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

    size_t OperatorIndex = 0;
    size_t countNumbers = 0;
    size_t countOperators = 0;
    size_t skipFirstChunk = 0;
    for (size_t i = 0; i < expression.length(); ++i) {
        if (i == 0){
            std::cout << "|";
            for (; isdigit(expression[i]) || expression[i] == ' '; ++i, ++skipFirstChunk) {
                std::cout << expression[i];
            }
            std::cout << "|";
            std::cout << std::endl;
            std::cout << "0. First chunk size: " << skipFirstChunk << std::endl;
            std::cout << "|";
            for (; expression[i] == ' ' || expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/'; ++i, ++skipFirstChunk) {
                std::cout << expression[i];
            }
            std::cout << "|";
            std::cout << std::endl;
            std::cout << "1. First chunk size: " << skipFirstChunk << std::endl;
        }
        if (i == expression.length() - 1 && i >= skipFirstChunk) {
            std::cout << "Last character: " << expression[i] << std::endl;
            while ((expression[i] == ' ' || expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') && !isdigit(expression[i])) {
                if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {
                       countOperators++;
                       std::cout << "Operator found: " << expression[i] << std::endl;
                   }
                i--;
            }
            while (isdigit(expression[i]) || expression[i] == ' ') {
                if (isdigit(expression[i])) {
                    std::cout << "Number found: " << expression[i] << std::endl;
                    countNumbers++;
                }
                i--;
            }
            if (countNumbers != countOperators) {
                throw std::invalid_argument("Invalid expression: number of operators must be one less than number of numbers 1");
            }
            break;
        }
    }
   
    std::cout << "OperatorIndex: " << OperatorIndex << std::endl;
    std::cout << "countNumbers: " << countNumbers << std::endl;
    std::cout << "countOperators: " << countOperators << std::endl;
}

/*
- is it Associativity and Evaluation Order
*/