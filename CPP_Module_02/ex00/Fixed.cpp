#include "Fixed.hpp"

// The rule of 3. The rule of three (also known as the Law of The Big Three or The Big Three) is a rule of thumb in C++ (prior to C++11) that claims that if a class defines one (or more) of the following it should probably explicitly define all three:
// (1) constructor
Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// (2) destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// (3) copy constructor
Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    //this->fixedPointValue = copy.getRawBits();
    *this = copy;
}

// (3 or 4) copy assignment operator | 2 because it is part of copy constructor
Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (&copy == this) {
        return *this;
    }
    else {
        this->fixedPointValue = copy.getRawBits();
    }
    return *this;
}

//****Functions****//
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}