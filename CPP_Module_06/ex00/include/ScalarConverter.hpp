#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>


class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &rhs);
        ~ScalarConverter();

        static void convert(const std::string &input);
        void printChar(char c);
        void printInt(int i);
        void printFloat(float f);
        void printDouble(double d);
    private:

};

#endif