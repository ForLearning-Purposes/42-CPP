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
    //std::cout << std::endl;
    //std::cout << "****************************************************" << std::endl;
    //std::cout << "value: " << value << std::endl;
    //std::cout << "1 << this->fractionalBits: " << (1 << this->fractionalBits) << std::endl;
    //std::cout << "____________________________________________________" << std::endl;
    //std::cout << "value * (1 << this->fractionalBits): " << value * (1 << this->fractionalBits) << std::endl;
    //std::cout << "Fixed point value: " << this->fixedPointValue << std::endl;
    //std::cout << "****************************************************" << std::endl;
    //std::cout << std::endl;
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
    // std::cout << std::endl;
    // std::cout << "****************************************************" << std::endl;
    // std::cout << "this->fixedPointValue: " << this->fixedPointValue << std::endl;
    // std::cout << "1 << this->fractionalBits: " << (1 << this->fractionalBits) << std::endl;
    // std::cout << "____________________________________________________" << std::endl;
    // std::cout << "Fixed point value: " << this->fixedPointValue << std::endl;
    // std::cout << "this->fixedPointValue / (1 << this->fractionalBits): " << (float)this->fixedPointValue / (float)(1 << this->fractionalBits) << std::endl;
    // std::cout << "****************************************************" << std::endl;
    // std::cout << std::endl;

    return (float)this->fixedPointValue / (float)(1 << this->fractionalBits);
    // converts the fixed-point value to a floating-point value

}

int Fixed::toInt( void ) const {
    // std::cout << std::endl;
    // std::cout << "****************************************************" << std::endl;
    // std::cout << "this->fixedPointValue: " << this->fixedPointValue << std::endl;
    // std::cout << "1 << this->fractionalBits: " << (1 >> this->fractionalBits) << std::endl;
    // std::cout << "____________________________________________________" << std::endl;
    // std::cout << "Fixed point value: " << this->fixedPointValue << std::endl;
    // std::cout << "this->fixedPointValue >> this->fractionalBits: " << (this->fixedPointValue >> this->fractionalBits) << std::endl;
    // std::cout << "****************************************************" << std::endl;
    // std::cout << std::endl;

    return this->fixedPointValue >> this->fractionalBits;
    // converts the fixed-point value to an integer value
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
    // overload of the insertion («) operator that inserts a floating-point representation
    // of the fixed-point number into the output stream object passed as a parameter.
}

/*
1 << 8 = 256
Steps:
X<<N=X×2N
 
Expression	| Binary (Before)	     |  Binary (After)	     |  Decimal Result
1 << 8	    | 0000 0000 0000 0001	 |  0000 0001 0000 0000	 |      256
2 << 8	    | 0000 0000 0000 0010	 |  0000 0010 0000 0000	 |      512
3 << 8	    | 0000 0000 0000 0011	 |  0000 0011 0000 0000	 |      768

X>>N=X/2N

Expression	| Binary (Before)	     |  Binary (After)	     |  Decimal Result
256 >> 8	| 0000 0001 0000 0000	 |  0000 0000 0000 0001	 |      1
512 >> 8	| 0000 0010 0000 0000	 |  0000 0000 0000 0010	 |      2
768 >> 8	| 0000 0011 0000 0000	 |  0000 0000 0000 0011	 |      3
*/