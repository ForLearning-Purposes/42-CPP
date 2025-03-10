#include "Fixed.hpp"
#include <iostream>


int main() {
    std::cout << "Here 1" << std::endl;
    Fixed a;
    std::cout << "Here 2" << std::endl;
    Fixed b( a );
    std::cout << "Here 3" << std::endl;
    Fixed c;
    std::cout << "Here 4" << std::endl;

    c = b;
    std::cout << "Here 5" << std::endl;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << "Here 6" << std::endl;

return 0;
}

/*
INFO:
- fixed-point numbers
*/