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
    if (isChar(input)) {
        char c = input[0];
        std::cout << "Input is a char: " << c << std::endl;
        printChar(c);
    }
    else if (isInt(input)) {
        int num = static_cast<int>(atoi(input.c_str()));
        std::cout << "Input is an int: " << num << std::endl;
        // - or + sign can be at the start of the string only
    }
    else if (isFloat(input)) {
        std::cout << "HERE" << std::endl;
    }
    else if (isDouble(input)) {
        std::cout << "HERE2" << std::endl;
    }
    else {
        std::cout << "INPUT IS NOT A SCALAR TYPE" << std::endl;
    }
}

// Check if the string length is 1 and the first character is a printable character
bool ScalarConverter::isChar(const std::string& str) {
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0])) {
        return true;
    }
    else {
        std::cout << "\nINPUT IS NOT A CHAR" << std::endl;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string& str) {
    // check that int is not avove or below the limits
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {  // If any character is not a digit
            if (*it == '-' || *it == '+') {
                if (it != str.begin()) {  // If '-' or '+' is not at the start
                    return false;         // Return false immediately
                }
            }
            else {
                std::cout << "\nINPUT IS NOT AN INT" << std::endl;
                return false;  // Return false if any character is not a digit
            }
        }
        
    }
    return true;  // All characters are digits
}

// Check if the string is a valid float
bool ScalarConverter::isFloat(const std::string& str) {
    std::cout << "Checking if float: " << str << std::endl;
    if (str.c_str()[str.length() - 1] == 'f' && str.c_str()[str.length()] == '\0') {
        if (str == "-inf" || str == "+inf" || str == "nan") {
            std::cout << "\nINPUT IS A FLOAT" << std::endl;
            return true;
        }
        size_t i = 0;
        if (str[i] == '-' || str[i] == '+') {
            i++;
        }
        int dotCount = 0;
        while (i < str.length()) {
            if (str.c_str()[i] == '.' && isdigit(str.c_str()[i + 1])) {
                i++;
                dotCount++;
            }
            else if (isdigit(str.c_str()[i])) {
                i++;
            }
            else {
                std::cout << "\nINPUT IS NOT A FLOAT" << std::endl;
                return false;  // Return false if any character is not a digit  
            }
        }
        if (dotCount > 1) {
            std::cout << "\nINPUT IS NOT A FLOAT" << std::endl;
            return false;  // More than one dot is not valid
        }
        std::cout << "\nINPUT IS A FLOAT" << std::endl;
        return true;
    }
    return false; 
}

bool ScalarConverter::isDouble(const std::string& str) {
    std::cout << "Checking if double: " << str << std::endl;
    return false;  // Placeholder for double check
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