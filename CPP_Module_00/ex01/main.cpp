#include "include/PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

void handle_input(PhoneBook &phonebook, std::string input)
{
    if (input == "ADD")
    {
        phonebook.addContact();
    }
    else if (input == "SEARCH")
    {
        phonebook.searchContact();
    }
    else if (input == "EXIT")
    {
        std::cout << "\nExiting..." << std::endl;
        exit(0);
    }
}

//handle control + C

int main()
{
    PhoneBook phonebook;

    phonebook.show_info();
    while (!std::cin.fail())
    {
        std::string input;
        std::cin >> input;
        if (std::cin.fail() == true || std::cin.eof() == true)
        {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }
        handle_input(phonebook, input);
        phonebook.show_info();
    }
    return 0;
}