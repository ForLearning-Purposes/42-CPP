#include "../include/ShrubberyCreationForm.hpp"

/*
•ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.
*/

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "\nDefault constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) {
    std::cout << "\nConstructor with target called for ShrubberyCreationForm" << std::endl;
    (void)target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) {
    std::cout << "\nCopy constructor called for ShrubberyCreationForm" << std::endl;
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    std::cout << "\nCopy assignment operator called for ShrubberyCreationForm" << std::endl;
    if (&copy == this) {
        return *this;
    }
    //this->_grade = copy._grade;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "\nDestructor called for ShrubberyCreationForm" << std::endl;
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& rhs) {
    (void)rhs;
    os << "\n***ShrubberyCreationForm:\n" << std::endl;
    return os;
}