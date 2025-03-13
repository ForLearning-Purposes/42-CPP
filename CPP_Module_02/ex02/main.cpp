#include <iostream>
#include "Fixed.hpp"

/*
Questions:
1. How do toIndex() and toFloat() work?
2. What is fixed-point number?
3. What are operators?
4. What are floating-point numbers?
5. What is the difference between fixed-point and floating-point numbers?
*/
int main() {
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
