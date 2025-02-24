#include "include/Contact.hpp"

// Contact
// ◦Stands for a phonebook contact

// Constructor
Contact::Contact(void) {
    this->first_name = "Monika";
    this->last_name = "Simic";
    this->nickname = "mona";
    this->phone_number = "05533441";
    this->darkest_secret = "None";
}

Contact::~Contact(void) {
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
    return;
}

std::string Contact::getFirstName() {
    return this->first_name;
}

std::string Contact::getLastName() {
    return this->last_name;
}

std::string Contact::getNickname() {
    return this->nickname;
}

std::string Contact::getPhoneNumber() {
    return this->phone_number;
}

std::string Contact::getDarkestSecret() {
    return this->darkest_secret;
}

void Contact::setFirstName(std::string first_name) {
    this->first_name = first_name;
}

void Contact::setLastName(std::string last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(std::string nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number) {
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}
