#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
    (void)av;
    try {
        if (ac != 2)
            throw std::invalid_argument("Usage: ./RPN \"expression\"");
        RPN reversePolishNotation;
        reversePolishNotation.validateExpression(av[1]);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}