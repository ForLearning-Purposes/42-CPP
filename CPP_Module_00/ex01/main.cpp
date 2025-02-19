#include "include/PhoneBook.hpp"
#include <string>

void handle_input(std::string input)
{
    if (input == "ADD")
    {
        std::cout << "If ADD, then set information" << std::endl;
    }
    else if (input == "SEARCH")
    {
        std::cout << "if SEARCH, then get information" << std::endl;
    }
    else if (input == "EXIT")
    {
        std::cout << "If EXIT, then delete contacts and quit" << std::endl;
    }
    else
    {
        std::cout << "Invalid command" << std::endl;
    }
}

int main()
{
    PhoneBook phonebook;
    std::string input;

    phonebook.show_info();
    while (true && std::getline(std::cin, input))
    {
    }
    return 0;
}