#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw std::invalid_argument("Usage: ./RPN \"expression\"");
        RPN rpn;
        rpn.start(av[1]);
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}