#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

#include "Contact.hpp"

// CLASS DECLARATION:
// Declaration of a class is done using the class keyword followed by the class name.
class PhoneBook {
    public:
        // Public are variables and functions that can be accessed by other classes or functions.
        PhoneBook(); // Constructor -> A constructor is a special type of member function that initializes an object automatically when it is created.
        ~PhoneBook(); // Destructor -> A destructor is a special member function that is called when the scope of an object ends.
        void show_info(void);
        void addContact(int intex_count);
        void searchContact(void);
        bool addContactInfo(int i, int index_to_replace);
        void clearContactLast(int i, int index_to_rm);
        void show_contact(int index_of_the_contact);
        void show_contacts(void);
    private:
        // Private are variables and functions that can only be accessed by the class they belong
        Contact contacts[8]; // this is an array of 8 contacts. Each contact has a first name, last name, nickname, phone number, and darkest secret.
        int index; // this is the index of the contact in the array.

};

#endif