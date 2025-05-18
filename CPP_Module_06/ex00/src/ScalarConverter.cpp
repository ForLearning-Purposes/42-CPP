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

void ScalarConverter::convert(const std::string &input) {

    ScalarConverter converter;
    std::cout << "***Converting: " << input << std::endl;

    converter.checkinput(input);

    std::cout << std::endl;
    std::cout << "Conversion results:" << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
}

/*
You have to first detect the type of the literal passed as a parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
*/
void ScalarConverter::checkinput(const std::string &input) {
    std::cout << std::endl;
    std::cout << "***Checking input: " << input << std::endl;

    char c;
    int i;
    float f;
    double d;

    if (isChar(input)) {
        std::cout << "**CHAR**\n" << std::endl;
        c = input[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        printChar(c);
        printInt(i);
        printFloat(f);
        printDouble(d);
    }
    else if (isInt(input)) {
        std::cout << "**INT**\n" << input << std::endl;
        c = static_cast<char>(atoi(input.c_str()));
        i = atoi(input.c_str());
        f = static_cast<float>(atoi(input.c_str()));
        d = static_cast<double>(atoi(input.c_str()));
        printChar(c);
        printInt(i);
        printFloat(f);
        printDouble(d);
    }
    else if (isFloat(input)) {
        std::cout << "**FLOAT**\n" << std::endl;
        c = static_cast<char>(atof(input.c_str()));
        i = static_cast<int>(atof(input.c_str()));
        f = static_cast<float>(atof(input.c_str()));
        d = static_cast<double>(atof(input.c_str()));

        if (input == "-inff" || input == "+inff" || input == "nanf") {
            std::cout << "int: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
        }
        else {
            printInt(i);
            printChar(c);
        }
        printFloat(f);
        printDouble(d);
    }
    else if (isDouble(input)) {
        std::cout << "**DOUBLE**\n" << std::endl;
        c = static_cast<char>(atof(input.c_str()));
        i = static_cast<int>(atof(input.c_str()));
        f = static_cast<float>(atof(input.c_str()));
        d = static_cast<double>(atof(input.c_str()));
        
        if (input == "-inf" || input == "+inf" || input == "nan") {
            std::cout << "int: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
        }
        else {
            printInt(i);
            printChar(c);
        }
        printFloat(f);
        printDouble(d);
    }
    else {
        std::cout << "INPUT IS NOT A SCALAR TYPE" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& str) {
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0])) {
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {
            if (*it == '-' || *it == '+') {
                if (it != str.begin())
                    return false;
            }
            else
                return false;
        }
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.c_str()[str.length() - 1] == 'f' && str.c_str()[str.length()] == '\0') {
        if (str == "-inff" || str == "+inff" || str == "nanf")//WHAT IS NAN? CAN IS GET TO THIS POINT BECAUSE OF THE CHECK ABOVE?
            return true;
        size_t i = 0;
        if (str[i] == '-' || str[i] == '+')
            i++;
        int dotCount = 0;
        int fCount = 0;
        while (i < str.length()) {
            if (str.c_str()[i] == '.' && isdigit(str.c_str()[i + 1]) && isdigit(str.c_str()[i - 1])) {
                dotCount++;
                i++;
            }
            else if (isdigit(str.c_str()[i]))
                i++;
            else if (str.c_str()[i] == 'f') {
                fCount++;
                i++;
            }
            else
                return false;
        }
        if (dotCount == 1 && fCount == 1)
            return true;
        return false;
    }
    return false; 
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    int dotCount = 0;
    while (i < str.length()) {
        std::cout << "Checking character: " << str.c_str()[i] << std::endl;
        if (str.c_str()[i] == '.' && isdigit(str.c_str()[i + 1]) && isdigit(str.c_str()[i - 1])) {
            dotCount++;
            i++;
        }
        else if (isdigit(str.c_str()[i]))
            i++;
        else
            return false;
    }
    if (dotCount == 1)
        return true;
    return false;
}

void ScalarConverter::printChar(char c) {
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
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