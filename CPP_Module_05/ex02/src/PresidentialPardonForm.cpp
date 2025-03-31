#include "../include/PresidentialPardonForm.hpp"

/*
•PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
*/

PresidentialPardonForm::PresidentialPardonForm() {
    std::cout << "\nDefault constructor called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) {
    std::cout << "\nConstructor with target called for PresidentialPardonForm" << std::endl;
    (void)target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {
    std::cout << "\nCopy constructor called for PresidentialPardonForm" << std::endl;
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    std::cout << "\nCopy assignment operator called for PresidentialPardonForm" << std::endl;
    if (&copy == this) {
        return *this;
    }
    //this->_grade = copy._grade;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "\nDestructor called for PresidentialPardonForm" << std::endl;
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& rhs) {
    (void)rhs;
    os << "\n***PresidentialPardonForm:\n" << std::endl;
    return os;
}