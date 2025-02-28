#include "include/PhoneBook.hpp"
#include "include/inputHandling.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>

PhoneBook::PhoneBook(void) : index(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::show_info(void) {

    std::cout << "\033[1;34m";
    std::cout << "\n\tInfo:" << std::endl;
    std::cout << "\tADD -> to add a new contact" << std::endl;
    std::cout << "\tSEARCH -> to search for a contact" << std::endl;
    std::cout << "\tEXIT -> to exit the program" << std::endl;
    std::cout << "\033[0m";

    std::cout << "\n\tENTER COMMAND:" << std::endl;
}

bool PhoneBook::addContactInfo(int i, int index_to_replace) {
    inputHandling inputHandling;
    std::string input;
    if (std::cin.eof() == true) {
        std::cout << "Ctrl + D -> Exiting..." << std::endl;
        exit(0);
    }
    switch (i) {
        case 0:
            std::cout << "Enter first name:" << std::endl;
            std::getline(std::cin, input);
            if (inputHandling.ifInputEmptyAndNoCharacter(input, "First name") == false){
                return false;
            }
            contacts[index_to_replace].setFirstName(input);
            input.clear();
            break;
        case 1:
            std::cout << "Enter last name:" << std::endl;
            std::getline(std::cin, input);
            if (inputHandling.ifInputEmptyAndNoCharacter(input, "Last name") == false){
                return false;
            }
            contacts[index_to_replace].setLastName(input);
            input.clear();
            break;
        case 2:
            std::cout << "Enter nickname:" << std::endl;
            std::getline(std::cin, input);
            if (inputHandling.ifInputEmptyAndNoCharacter(input, "Nickname") == false){
                return false;
            }
            contacts[index_to_replace].setNickname(input);
            input.clear();
            break;
        case 3:
            std::cout << "Enter phone number:" << std::endl;
            std::getline(std::cin, input);
            if (inputHandling.ifInputEmptyAndNoCharacter(input, "Phone number") == false){
                return false;
            }
            else if (inputHandling.isPhoneNumberDigit(input, "Phone number") == false){
                return false;
            }
            contacts[index_to_replace].setPhoneNumber(input);
            input.clear();
            break;
        case 4:
            std::cout << "Enter darkest secret:" << std::endl;
            std::getline(std::cin, input);
            if (inputHandling.ifInputEmptyAndNoCharacter(input, "Darkest secret") == false){
                return false;
            }
            contacts[index_to_replace].setDarkestSecret(input);
            input.clear();
    }
    return true;
}

void PhoneBook::clearContactLast(int i, int index_to_rm) {
    switch (i) {
        case 0:
            contacts[index_to_rm].setFirstName("");
            break;
        case 1:
            contacts[index_to_rm].setLastName("");
            break;
        case 2:
            contacts[index_to_rm].setNickname("");
            break;
        case 3:
            contacts[index_to_rm].setPhoneNumber("");
            break;
        case 4:
            contacts[index_to_rm].setDarkestSecret("");
    }
}

void PhoneBook::addContact(int intex_count) {
    std::string input;
    std::cout << "**ADDING CONTACT**" << std::endl;
    std::cout << "\nContact no. #" << this->index << std::endl;
    // == 8 because it starts from 0 and when it reaches 8, it's full and already added 8 contacts
    if (this->index == 8) {
        std::cout << "PhoneBook is full.\nBy adding a new conntact you replace the oldest one by the new one added" << std::endl;
        for (int i = 0; i < 5; i++) {
            clearContactLast(i, intex_count);
        }
        for (int i = 0; i < 5; i++) {
            if (addContactInfo(i, intex_count) == false){
                i -= 1;
            }
        }
        std::cout << "Contact added." << std::endl;
    }
    else if (this->index < 8) {
        for (int i = 0; i < 5; i++) {
            if (addContactInfo(i, intex_count) == false){
                i -= 1;
            }
        }
        std::cout << "Contact added." << std::endl;
        this->index++;
    }
}

void PhoneBook::searchContact() {
    inputHandling inputHandling;
    std::string input;

    if (this->index > 0)
        show_contacts();

    std::cout << "Enter index of the contact:" << std::endl;
    std::getline(std::cin, input);
    if (inputHandling.isIndexDigit(input, "Index") == false){
        return;
    }
    else if (this->index == 0) {
        std::cout << "\033[1;91m";
        std::cout << "\nPhoneBook is empty.\nPlease add conntact first." << std::endl;
        std::cout << "\033[0m";
    }
    else if (this->index > 0 && this->index <= 8) {
        if (std::cin.eof() == true) {
            std::cout << "Ctrl + D -> Exiting..." << std::endl;
            exit(0);
        }
        int index_num;
        std::stringstream ss(input);
        ss >> index_num;
        if (ss.fail() == true) {
            std::cout << "\033[1;91m";
            std::cout << "ERROR:\nConversion failed.\n" << std::endl;
            std::cout << "\033[0m";
            return;
        }
        else if (index_num >= this->index) {
            std::cout << "\033[1;91m";
            std::cout << "\nERROR:\nIndex is out of range.\n" << std::endl;
            std::cout << "\033[0m";
            return;
        }
        show_contact(index_num);
    }
}

void PhoneBook::show_contacts(void){
    std::cout << "\n\n****************PHONEBOOK****************" << std::endl;
    std::cout << "|    INDEX" << "|   F_NAME" << "|   L_NAME" << "| NICKNAME|" << std::endl;
    for (int i = 0; i < this->index; i++)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "|";
        std::cout << "        " << i;
        std::cout << "|";
        int len = contacts[i].getFirstName().length();
        if (len > 10)
            std::cout << contacts[i].getFirstName().substr(0, 9) << ".";
        else
            std::cout << std::string(10 - len, ' ') << contacts[i].getFirstName();
        std::cout << "|";
        len = contacts[i].getLastName().length();
        if (len > 10)
            std::cout << contacts[i].getLastName().substr(0, 9) << ".";
        else
            std::cout << std::string(10 - len, ' ') << contacts[i].getLastName();
        std::cout << "|";
        len = contacts[i].getNickname().length();
        if (len > 10)
            std::cout << contacts[i].getNickname().substr(0, 9) << ".";
        else
            std::cout << std::string(10 - len, ' ') << contacts[i].getNickname();
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << "*****************************************" << std::endl;
}

void PhoneBook::show_contact(int index_of_the_contact) {
    std::cout << "\033[1;32m";
    std::cout << "\n\n****************PHONEBOOK****************" << std::endl;
    std::cout << "\nINDEX: " << "\n-> " << index_of_the_contact << std::endl;
    std::cout << "FIRST NAME: " << "\n-> " << contacts[index_of_the_contact].getFirstName() << std::endl;
    std::cout << "LAST NAME: " << "\n-> " << contacts[index_of_the_contact].getLastName() << std::endl;
    std::cout << "NICKNAME: " << "\n-> " << contacts[index_of_the_contact].getNickname() << std::endl;
    std::cout << "PHONE NUMBER: " << "\n-> " << contacts[index_of_the_contact].getPhoneNumber() << std::endl;
    std::cout << "DARKEST SECRET: " << "\n-> " << contacts[index_of_the_contact].getDarkestSecret() << std::endl;
    std::cout << "\n*****************************************" << std::endl;
    std::cout << "\033[0m";
}
