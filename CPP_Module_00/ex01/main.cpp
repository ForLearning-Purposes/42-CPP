#include "include/PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

void handle_input(PhoneBook &phonebook, std::string input, int &i)
{
    if (input == "ADD")
    {
        phonebook.addContact(i);
        i += 1;
        if (i == 8)
            i = 0;
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

int main(int ac, char **av)
{
    (void)av;
    PhoneBook phonebook;
    int i = 0;

    if (ac == 1){
        phonebook.show_info();
        while (!std::cin.fail())
        {
            std::string input;
            std::getline(std::cin, input);
            if (std::cin.fail() == true || std::cin.eof() == true)
            {
                std::cout << "Exiting..." << std::endl;
                exit(0);
            }
            handle_input(phonebook, input, i);
            phonebook.show_info();
        }
    }
    else {
        std::cout << "Usage: ./phonebook" << std::endl;
    }
    return 0;
}