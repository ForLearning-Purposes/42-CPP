#include "include/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

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

    std::cout << "\033[1;34m";
    std::cout << "\n\tInfo:" << std::endl;
    std::cout << "\tADD -> to add a new contact" << std::endl;
    std::cout << "\tSEARCH -> to search for a contact" << std::endl;
    std::cout << "\tEXIT -> to exit the program" << std::endl;
    std::cout << "\033[0m";

    std::cout << "\n\tENTER COMMAND:" << std::endl;
}

bool PhoneBook::addContactInfo(int i) {
    std::string input;
    // input can't be empty
    if (std::cin.eof() == true) {
        std::cout << "Ctrl + D -> Exiting..." << std::endl;
        exit(0);
    }
    switch (i) {
        case 0:
            std::cout << "Enter first name:" << std::endl;
            std::cin >> input;
            //handle input for first and last name
            contacts[this->index].setFirstName(input);
            break;
        case 1:
            std::cout << "Enter last name:" << std::endl;
            std::cin >> input;
            //handle input for first and last name
            contacts[this->index].setLastName(input);
            break;
        case 2:
            std::cout << "Enter nickname:" << std::endl;
            std::cin >> input;
            //handle input for nickname
            contacts[this->index].setNickname(input);
            break;
        case 3:
            std::cout << "Enter phone number:" << std::endl;
            std::cin >> input;
            //handle input for phone number
            contacts[this->index].setPhoneNumber(input);
            break;
        case 4:
            std::cout << "Enter darkest secret:" << std::endl;
            std::cin >> input;
            //handle input for darkest secret
            contacts[this->index].setDarkestSecret(input);
    }
    return true;
}

void PhoneBook::clearContactLast(int i) {
    switch (i) {
        case 0:
            contacts[7].setFirstName("");
            break;
        case 1:
            contacts[7].setLastName("");
            break;
        case 2:
            contacts[7].setNickname("");
            break;
        case 3:
            contacts[7].setPhoneNumber("");
            break;
        case 4:
            contacts[7].setDarkestSecret("");
    }
}

void PhoneBook::addContact(void) {
    std::string input;
    std::cout << "**ADDING CONTACT**" << std::endl;
    std::cout << "\nContact no. #" << this->index << std::endl;
    // == 8 because it starts from 0 and when it reaches 8, it's full and already added 8 contacts
    if (this->index == 8) {
        std::cout << "PhoneBook is full.\nBy adding a new conntact you will delete last contact added" << std::endl;
        for (int i = 0; i < 5; i++) {
            clearContactLast(i);
        }
        this->index = 7;
        for (int i = 0; i < 5; i++) {
            addContactInfo(i);
        }
        this->index++;
        std::cout << "Contact added." << std::endl;
    }
    else if (this->index < 8) {
        for (int i = 0; i < 5; i++) {
            addContactInfo(i);
        }
        std::cout << "Contact added." << std::endl;
        this->index++;
    }
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