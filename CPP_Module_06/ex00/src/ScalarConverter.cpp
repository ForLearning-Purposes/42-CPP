#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {*this = src;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    if (this != &rhs) {
        // Copy assignment logic here
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &input) {
    std::cout << "Converting: " << input << std::endl;
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