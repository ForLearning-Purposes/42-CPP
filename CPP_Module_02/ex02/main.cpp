#include <iostream>
#include "Fixed.hpp"

int main() {
    std::cout << std::endl;
    std::cout << "********** Test 1 **********" << std::endl;
    std::cout << std::endl;

    Fixed w;
    Fixed q( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << w << std::endl;
    std::cout << ++w << std::endl;
    std::cout << w << std::endl;
    std::cout << w++ << std::endl;
    std::cout << w << std::endl;

    std::cout << q << std::endl;

    std::cout << Fixed::max( w, q ) << std::endl;
    
    std::cout << std::endl;
    std::cout << "********** Test 2 **********" << std::endl;
    std::cout << std::endl;

    Fixed a(0);
    Fixed b(10);
    Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << std::endl;

    std::cout << "6 comparison operators: >, <, >=, <=, ==, and !=" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << std::endl;

    std::cout << "4 arithmetic operators: +, -, *, and /" << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;

    std::cout << std::endl;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << d << std::endl;
    std::cout << Fixed::max( a, d ) << std::endl;

    std::cout << std::endl;

    std::cout << "4 increment/decrement operators: ++x, x++, --x, x--" << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;

    return 0;
}

/*
INFO:
    -   operator is a special keyword, not just a function name.
        It allows defining how operators work for user-defined types.
        Without operator, you cannot overload operators.
        It improves readability, consistency, and integration with C++ features.
    -   Static means these functions belong to the class rather than an instance.
    -   Overloading means defining multiple functions with the same name but different parameter lists.
        In this case, there are two versions of min and max (see in the Fixed.hpp file).
*/