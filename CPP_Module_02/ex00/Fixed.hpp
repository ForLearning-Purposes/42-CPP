#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed(void);
        // learn first about copy constructor
        // and Copy assignment operator overload
        ~Fixed(void);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;// A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.
};

#endif