#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0) {}

Fixed::Fixed(const int value) : fixedPointValue(0) {
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) : fixedPointValue(0) {
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed& copy) { *this = copy; }

Fixed& Fixed::operator=(const Fixed& copy) {
    if (&copy == this) {
        return *this;
       }
    else
        this->fixedPointValue = copy.getRawBits();
    return *this;
}
//*****************************************************************//

//****Operators****//
//6 comparison operators: >, <, >=, <=, ==, !=
bool Fixed::operator>(const Fixed& fix) const {
    return (this->fixedPointValue > fix.getRawBits());
}

bool Fixed::operator<(const Fixed& fix) const {
    return (this->fixedPointValue < fix.getRawBits());
}

bool Fixed::operator>=(const Fixed& fix) const {
    return (this->fixedPointValue >= fix.getRawBits());
}

bool Fixed::operator<=(const Fixed& fix) const {
    return (this->fixedPointValue <= fix.getRawBits());
}

bool Fixed::operator==(const Fixed& fix) const {
    return (this->fixedPointValue == fix.getRawBits());
}

bool Fixed::operator!=(const Fixed& fix) const {
    return (this->fixedPointValue != fix.getRawBits());
}

//4 arithmetic operators: +, -, *, /
Fixed Fixed::operator+(const Fixed& fix) const {
    return Fixed(this->toFloat() + fix.toFloat());
}

Fixed Fixed::operator-(const Fixed& fix) const {
    return Fixed(this->toFloat() - fix.toFloat());
}

Fixed Fixed::operator*(const Fixed& fix) const {
    return Fixed(this->toFloat() * fix.toFloat());
}

Fixed Fixed::operator/(const Fixed& fix) const {
    return Fixed(this->toFloat() / fix.toFloat());
}

//4 increment/decrement operators: ++x, x++, --x, x--:

// Pre-increment (++x): Increase by 1
Fixed& Fixed::operator++(void) {
    this->fixedPointValue++; // this->fixedPointValue += (1 << this->fractionalBits);  // Increase by 256 (equivalent to 1.0 in fixed-point) which means 1 in real-world value
    return *this;
}
/*
Info:
We're not adding 1 in real-world value,
we're adding 1 in the raw integer representation,
which corresponds to 1 / 256 (0.00390625 in decimal).
*/

// Post-increment (x++): Increase but return old value
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixedPointValue++;
    return temp;
}

// Pre-decrement (--x): Decrease by 1
Fixed& Fixed::operator--(void) {
    this->fixedPointValue--;
    return *this;
}

// Post-decrement (x--): Decrease but return old value
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->fixedPointValue--;
    return temp;
}
//*****************************************************************//

//****Overloaded static functions****//
/*
min(Fixed&, Fixed&) → Returns a reference to the smaller of the two Fixed objects.
min(const Fixed&, const Fixed&) → Same as (1), but works with const references.
max(Fixed&, Fixed&) → Returns a reference to the larger of the two Fixed objects.
max(const Fixed&, const Fixed&) → Same as (3), but works with const references.
*/

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a <= b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a <= b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a >= b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a >= b) ? a : b;
}
//*****************************************************************//

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
//*****************************************************************//

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
    output << fixed.toFloat();
    return (output);
}