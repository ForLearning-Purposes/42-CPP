#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>

class RPN {
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &rhs);
        ~RPN();

        void validateExpression(const std::string &expression);
    private:
};

#endif