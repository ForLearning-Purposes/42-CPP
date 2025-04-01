#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

//enum
enum FormType {
    PRESIDENTIAL_PARDON,
    ROBOTOMY_REQUEST,
    SHRUBBERY_CREATION,
    UNKNOWN
};

//array of form names
const std::string formNames[3] = {
    "presidential pardon",
    "robotomy request",
    "shrubbery creation"
};

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &rhs);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target);
        
        class UnknownFormException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Intern const &rhs);

#endif