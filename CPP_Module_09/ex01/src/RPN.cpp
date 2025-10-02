#include "../inc/RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &src) {*this = src;}
RPN &RPN::operator=(const RPN &rhs) {(void)rhs; return *this;}
RPN::~RPN() {}

void RPN::start(std::string expression) {
    if (!validateExpression(expression)) {
        throw std::invalid_argument("Invalid RPN expression");
    }
    int result = calculate(expression);
    std::cout << result << std::endl;
}

// Check if token is one-digit number
bool RPN::isDigit(const std::string &token) {
    return token.length() == 1 && std::isdigit(token[0]);
}

// Check if token is valid operator
bool RPN::isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::validateExpression(const std::string &expression) {
    std::stringstream ss(expression);
    std::string token;
    int depth = 0;

    while (ss >> token) {
        if (isDigit(token)) {
            depth++;
        } else if (isOperator(token)) {
            if (depth < 2)
                return false;
            depth--; // two popped, one pushed
        } else {
            return false; // invalid token
        }
    }
    return depth == 1;
}

int RPN::applyOperator(int a, int b, const std::string &op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

int RPN::calculate(const std::string &input) {
    std::stringstream ss(input);
    std::string token;

    while (ss >> token) {
        if (isDigit(token)) {
            lst.push_back(token[0] - '0');
        } else if (isOperator(token)) {
            int b = lst.back(); lst.pop_back();
            int a = lst.back(); lst.pop_back();
            int result = applyOperator(a, b, token);
            lst.push_back(result);
        }
    }
    return lst.back();
}