#ifndef INPUTHANDLING_HPP
# define INPUTHANDLING_HPP

#include <string>

class inputHandling {
    public:
        inputHandling();
        ~inputHandling();
        bool ifInputEmptyAndNoCharacter(std::string input, std::string message);
        bool isPhoneNumberDigit(std::string input, std::string message);
        bool isIndexDigit(std::string input, std::string message);
};

#endif