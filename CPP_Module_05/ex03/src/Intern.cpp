#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <exception>

/*
********************************************************************************************************************************************************************
*/

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern &Intern::operator=(const Intern &rhs) {
    std::cout << "Intern assignment operator called" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

/*
********************************************************************************************************************************************************************
*/

const char *Intern::UnknownFormException::what() const throw() {
    return "\nERROR: Unknown form type\n";
}

/*
********************************************************************************************************************************************************************
*/

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm *form = NULL;
    int FormType;

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            FormType = i;
            break;
        }
        else
            FormType = UNKNOWN;
    }

    if (target.empty()) {
        std::cout << "Target is empty" << std::endl;
        return NULL;
    }

    switch (FormType) {
        case PRESIDENTIAL_PARDON:
            std::cout << "\n***Intern creates " << formName << std::endl;
            form = new PresidentialPardonForm(target);
            break;
        case ROBOTOMY_REQUEST:
            std::cout << "\n***Intern creates " << formName << std::endl;
            form = new RobotomyRequestForm(target);
            break;
        case SHRUBBERY_CREATION:
            std::cout << "\n***Intern creates " << formName << std::endl;
            form = new ShrubberyCreationForm(target);
            break;
        default:
            throw UnknownFormException();
    }

    return form;
}