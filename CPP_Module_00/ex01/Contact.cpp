#include "include/Contact.hpp"
#include <iostream>

// Contact
// ◦Stands for a phonebook contact

// Constructor
Contact::Contact(void) {
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::~Contact(void) {
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
    return;
}

