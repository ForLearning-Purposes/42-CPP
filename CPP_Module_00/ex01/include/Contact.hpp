#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

/*
Purpose of the Contact class:
- The Contact class is a class that will store the information of a contact.
- The Contact class will have the following attributes:
    - first_name
    - last_name
    - nickname
    - phone_number
    - darkest_secret
- The Contact class will have the following methods:
    - Constructor -> The constructor will initialize the attributes of the class.
    - Destructor -> The destructor will delete the attributes of the class.
    - Getters -> The getters will return the attributes of the class.
    - Setters -> The setters will set the attributes of the class.
    - Display -> The display will display the attributes of the class.
*/
class Contact {
    public:
        // Public are variables and functions that can be accessed by other classes or functions.
        int random;
        Contact(); // Constructor -> A constructor is a special type of member function that initializes an object automatically when it is created.
        ~Contact(); // Destructor -> A destructor is a special member function that is called when the scope of an object ends.
    private:
        // Private are variables and functions that can only be accessed by the class they belong
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif