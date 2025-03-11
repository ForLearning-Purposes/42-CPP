#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& copy);

        ~Fixed(void);

        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif