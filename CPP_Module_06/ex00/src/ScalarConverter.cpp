#include "../include/ScalarConverter.hpp"
#include <string>
#include <cstdlib>


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {*this = src;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    if (this != &rhs) {
        // Copy assignment logic here
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// You have to first detect the type of the literal passed as a parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types
void ScalarConverter::convert(const std::string &input) {
    ScalarConverter converter;
    std::cout << "***Converting: " << input << std::endl;
    // Check if the input is a char
    converter.checkinput(input);
    std::cout << std::endl;
    std::cout << "Conversion results:" << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void ScalarConverter::checkinput(const std::string &input) {
    std::cout << std::endl;
    std::cout << "***Checking input: " << input << std::endl;
    if (input.length() == 1 && !isdigit(input[0])) {
        char c = input[0];
        std::cout << "Input is a char: " << c << std::endl;
        printChar(c);
    }
    else if (isInt(input)) {
        int num = static_cast<int>(atoi(input.c_str()));
        std::cout << "Input is an int: " << num << std::endl;
        // - or + sign can be at the start of the string only
    }
    else {
        std::cout << "INPUT IS NOT A CHAR OR INT" << std::endl;
    }
}

bool ScalarConverter::isInt(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {  // If any character is not a digit
            if (*it == '-' || *it == '+') {
                if (it != str.begin()) {  // If '-' or '+' is not at the start
                    return false;         // Return false immediately
                }
            }
            else
                return false;  // Return false if any character is not a digit
        }
    }
    return true;  // All characters are digits
}

void ScalarConverter::printChar(char c) {
    std::cout << "char: " << c << std::endl;
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << f << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d << std::endl;
}