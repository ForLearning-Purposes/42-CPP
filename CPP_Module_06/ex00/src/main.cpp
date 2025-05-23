#include <iostream>
#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./convert <value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]); // To call function without creating an object is called static function.
    return 0;
}