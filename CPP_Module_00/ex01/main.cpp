#include "include/PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

void handle_input(PhoneBook &phonebook, std::string input)
{
    if (input == "ADD")
    {
        phonebook.searchContact();
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
    else
    {
        //std::cout << "Invalid command.\nTRY AGAIN!!" << std::endl;
        return;
    }
}

//handle control + C

int main()
{
    PhoneBook phonebook;
    std::string input;

    phonebook.show_info();
    while (true && std::getline(std::cin, input))
    {
        // what for EOF - end of file - ctrl + D
        if (std::cin.eof() == true)
        {
            std::cout << "Ctrl + D -> Exiting..." << std::endl;
            exit(0);
        }
        handle_input(phonebook, input);
    }
    return 0;
}