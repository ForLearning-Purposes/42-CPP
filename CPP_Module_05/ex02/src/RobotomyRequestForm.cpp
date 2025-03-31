#include "../include/RobotomyRequestForm.hpp"

/*
•RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "\nDefault constructor called for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) {
    std::cout << "\nConstructor with target called for RobotomyRequestForm" << std::endl;
    (void)target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) {
    std::cout << "\nCopy constructor called for RobotomyRequestForm" << std::endl;
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    std::cout << "\nCopy assignment operator called for RobotomyRequestForm" << std::endl;
    if (&copy == this) {
        return *this;
    }
    //this->_grade = copy._grade;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "\nDestructor called for RobotomyRequestForm" << std::endl;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& rhs) {
    (void)rhs;
    os << "\n***RobotomyRequestForm:\n" << std::endl;
    return os;
}