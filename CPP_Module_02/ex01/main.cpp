#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
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