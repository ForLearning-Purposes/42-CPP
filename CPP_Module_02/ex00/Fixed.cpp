#include "Fixed.hpp"

// The rule of 3. The rule of three (also known as the Law of The Big Three or The Big Three) is a rule of thumb in C++ (prior to C++11) that claims that if a class defines one (or more) of the following it should probably explicitly define all three:
// (1) constructor
Fixed::Fixed(void) : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// (2) destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// (3) copy constructor
Fixed::Fixed(const Fixed& copy) : fixedPointValue(copy.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

// (3 or 4) copy assignment operator | 2 because it is part of copy constructor
Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (&copy == this) {
        return *this; // return the object itself because it is already the same as the object we are trying to assign to it
        // return *this; is a common practice in operator= overloading to handle self-assignment.
        // * will return the object itself, so the object will not be changed.
        // if it's without * it will return the object itself, but it will be copied to another object first.
    }
    else
        this->fixedPointValue = copy.getRawBits();
    return *this;
}

/*
INFO:
1.  operator= is a special function used for copying an object and assigning it to another (already existing) object of the same type/class.
2.  if we don't define operator=, the compiler will generate a default one for us.
    which means it's goind to perform a shallow copy of the object. But we need to
    perform a deep copy of the object because if we had a pointer in the object, the
    default operator= would copy the address of the pointer, not the value it points to.
    which can lead to a double delete/free problem.
3.  copy constrictur is constructor and is used in creating new oobject by copying the
    values of another aleady existing object. Performing a deep copy of the object.
*/

//****Functions****//
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}