#include "../inc/RPN.hpp"

/*
INFO:
Reverse Polish Notation, the task is to create a program that
evaluates mathematical expressions written in RPN (postfix notation),
where operators follow their operands, using a stack-like approach.

-   For this exercise I used a list from the STL library.
    I chose list because it allows easy insertion and removal of
    elements from both ends, which fits well with the stack behavior
    needed to evaluate RPN expressions.
*/

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

/*     {
        (void) ac;
        try {
            (void) av;
            std::cout << "Creating a\n";
            RPN a;  // default constructor

            std::cout << "\nCreating b as a copy of a\n";
            RPN b(a);  // copy constructor

            std::cout << "\nCreating c\n";
            RPN c;

            std::cout << "\nAssigning a to c\n";
            c = a;  // copy assignment

            std::cout << "\nEnd of main\n";
        } catch (...) {
            std::cerr << "ERROR" << std::endl;
        }
        return 0;
    } */
    return 0;
}