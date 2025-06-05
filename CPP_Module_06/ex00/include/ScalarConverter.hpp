#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

// Only one static method "convert"
// As this class doesn’t need to store anything at all, it must not be instantiable by users
// You have to handle these pseudo-literals as well -inf(f), +inf(f), and nan(f)
//
class ScalarConverter {
    public:
        static void convert(const std::string &input);
        void checkinput(const std::string &input);
        bool isInt(const std::string& str);
        bool isChar(const std::string& str);
        bool isFloat(const std::string& str);
        bool isDouble(const std::string& str);
        
        void printChar(char c);
        void printInt(int i);
        void printFloat(float f);
        void printDouble(double d);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &rhs);
        ~ScalarConverter();
    
};

#endif