#include "Harl.hpp"

/*
This is a pointer to member function.
We use typedef to give a name to the pointer to member function.
*/
typedef void (Harl::*funcPTR)(void);

Harl::Harl() {}

Harl::~Harl() {}

/*
Harl also has a public member function that calls the four member functions above
depending on the level passed as a parameter: void complain( std::string level );
The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. He doesn’t
think twice!
Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed above in the subject or choose to use comments of your own
*/
void Harl::complain( std::string level ) {
    funcPTR funcPTR; // Here we declare a pointer to member function
    int index_level = -1;

    std::cout << "Complaining at level: " << level << std::endl;
    index_level = complainLevel(level);
    std::cout << "Index level: " << index_level << std::endl;
    switch (index_level) {
        case DEBUG:
            funcPTR = &Harl::debug; // Here we assign the address of the member function to the pointer
            break;
        case INFO:
            funcPTR = &Harl::info;
            break;
        case WARNING:
            funcPTR = &Harl::warning;
            break;
        case ERROR:
            funcPTR = &Harl::error;
            break;
    }
    (this->*funcPTR)();
}

/*
"DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.
Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-
ketchup burger. I really do!"
*/
void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

/*
"INFO" level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.
Example: "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
*/
void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

/*
"WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.
Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
years, whereas you started working here just last month."
*/
void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years, whereas you started working here just last month." << std::endl;
}

/*
"ERROR" level: These messages indicate that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.
Example: "This is unacceptable! I want to speak to the manager now."
*/
void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}