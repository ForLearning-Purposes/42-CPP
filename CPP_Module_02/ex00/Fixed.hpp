#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed(void);
        // Copy Constructor
        Fixed(const Fixed& copy);
        // learn Copy Assignment Operator overload
        Fixed& operator=(const Fixed& copy);
        ~Fixed(void);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;// A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.
};

#endif