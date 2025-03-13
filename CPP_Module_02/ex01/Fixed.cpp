#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixedPointValue(0) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) : fixedPointValue(0) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    //this->fixedPointValue = copy.getRawBits();
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (&copy == this) {
        return *this;
       }
    else
        this->fixedPointValue = copy.getRawBits();
    return *this;
}


//****Functions****//
float Fixed::toFloat( void ) const {
    return (float)this->fixedPointValue / (float)(1 << this->fractionalBits);
}

int Fixed::toInt( void ) const {
    return this->fixedPointValue >> this->fractionalBits;
}

int Fixed::getRawBits( void ) const {
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    this->fixedPointValue = raw;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
    output << fixed.toFloat();
    return (output);
}