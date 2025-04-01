#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"

/*
•PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
*/

/*
********************************************************************************************************************************************************************
*/

// Constructors and destructors:

PresidentialPardonForm::PresidentialPardonForm() :    AForm("PresidentialPardonForm", 25, 5), _target("DefaultTarget") {
    std::cout << "\nDefault constructor called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "\nConstructor with target called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {
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

/*
********************************************************************************************************************************************************************
*/

// Getters and setters:

const std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

//AForm getters

const std::string PresidentialPardonForm::getAFormName() const {
    return AForm::getName();
}

bool PresidentialPardonForm::getAFormSigned() const {
    return AForm::getSigned();
}

int PresidentialPardonForm::getAFormSignGrade() const {
    return AForm::getSignGrade();
}

int PresidentialPardonForm::getAFormExecGrade() const {
    return AForm::getExecGrade();
}

/*
********************************************************************************************************************************************************************
*/

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::cout << "PresidentialPardonForm::execute() called" << std::endl;
}

void PresidentialPardonForm::executeAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::printAForm() const {
    AForm::printForm();
}

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& rhs) {
    (void)rhs;
    os << "\n***PresidentialPardonForm:\nTarget: " << rhs.getTarget() << std::endl;
    return os;
}