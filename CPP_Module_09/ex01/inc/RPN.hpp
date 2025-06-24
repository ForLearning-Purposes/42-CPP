#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <cctype>
#include <stdexcept>

class RPN {
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &rhs);
        ~RPN();
        void start(std::string expression);
    private:
        std::list<int> stack;

        bool validateExpression(const std::string &expression);
        int calculate(const std::string &input);
        bool isOperator(const std::string &token);
        bool isDigit(const std::string &token);
        int applyOperator(int a, int b, const std::string &op);
};


#endif