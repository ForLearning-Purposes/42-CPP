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

        //6 comparison operators: >, <, >=, <=, ==, and !=
        bool operator>(const Fixed& fix) const;
        bool operator<(const Fixed& fix) const;
        bool operator>=(const Fixed& fix) const;
        bool operator<=(const Fixed& fix) const;
        bool operator==(const Fixed& fix) const;
        bool operator!=(const Fixed& fix) const;

        //4 arithmetic operators: +, -, *, and /
        Fixed operator+(const Fixed& fix) const;
        Fixed operator-(const Fixed& fix) const;
        Fixed operator*(const Fixed& fix) const;
        Fixed operator/(const Fixed& fix) const;


        //4 increment/decrement operators, which will increase or
        //decrease the fixed-point value by the smallest representable
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        //Overloaded static functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
};

// Overload the << operator | it's making the output of the object to the console
std::ostream    &operator<<(std::ostream &output, Fixed const &fixed);

#endif