#include "include/PhoneBook.hpp"
#include <iostream>
#include <string>

/*
CLASS DEFINITION:
Separated Definition (opposite is Inline Definition in Header File) of member functions in source file
- The member functions of a class can be defined outside the class or within the class.
- When a member function is defined outside the class, it is known as a separated definition.
- The separated definition of a member function is done using the class name followed by the scope resolution operator and the function name.
EXAMPLE:
    -void is a return type.
    -PhoneBook is the class name.
    - :: is the scope resolution operator that is used to define the member function outside the class.
    - show_info is the function name.
    - void is the parameter list.

    void PhoneBook::show_info(void) {
        std::cout << "\tEnter command (ADD, SEARCH, EXIT):" << std::endl;
    }

*/

// PhoneBook
// ◦It has an array of contacts.
// ◦It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
//  replace the oldest one by the new one.
// ◦Please note that dynamic allocation is forbidden

// Constructor
// adter : random_variable(0) is an initialization list and if we initialize one more variable, we separate them with a comma.
PhoneBook::PhoneBook(void) : index(0) {
    std::cout << "***PhoneBook constructor called in PhoneBook.cpp***" << std::endl;
    std::cout << "- Constructor is a special type of member function that initializes an object automatically when it is created.\n" << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "\n\n***PhoneBook destructor called in PhoneBook.cpp***" << std::endl;
    std::cout << "- Destructor is a special member function that is called when the scope of an object ends." << std::endl;
}

void PhoneBook::show_info(void) {
    std::cout << "\tEnter command (ADD, SEARCH, EXIT):" << std::endl;
}

void PhoneBook::addContact(void) {
    std::cout << "**ADD**" << std::endl;
    std::cout << this->index << std::endl;

}

void PhoneBook::searchContact(void) {
    std::string input;

    std::getline(std::cin, input);

    if (this->index == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
    }
    else if (this->index > 0) {
        std::cout << "PhoneBook is not empty." << std::endl;
        if (std::cin.eof() == true) {
            std::cout << "Ctrl + D -> Exiting..." << std::endl;
            exit(0);
        }
        // first:
    }
}