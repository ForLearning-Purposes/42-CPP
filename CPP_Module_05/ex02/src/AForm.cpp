#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

/*
********************************************************************************************************************************************************************
*/

// Constructors and destructors:

AForm::AForm() : _name("Officially Official AForm of Officialness"), _signGrade(150), _signed(false), execGrade(150) {
    std::cout << "\nDefault constructor called for AForm" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _signed(false), execGrade(execGrade) {
    std::cout << "\nParameterized constructor called for AForm" << std::endl;
    if (signGrade < 1 || execGrade < 1) {
        throw AForm::GradeTooHighException();
    }
    else if (signGrade > 150 || execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signGrade(copy._signGrade), execGrade(copy.execGrade) {
    std::cout << "\nCopy constructor called for AForm" << std::endl;
    *this = copy;
}

AForm& AForm::operator=(const AForm& copy) {
    std::cout << "AForm assignation operator is called" << std::endl;
    if (&copy == this) {
        return *this;
    }
    this->_signed = copy._signed;
    return *this;
}

AForm::~AForm() {
    std::cout << "\nDestructor called for AForm" << std::endl;
}

/*
********************************************************************************************************************************************************************
*/

// Getters and setters:

std::string AForm::getName() const {
    return this->_name;
}
bool AForm::getSigned() const {
    return this->_signed;
}
int AForm::getSignGrade() const {
    return this->_signGrade;
}
void AForm::setSigned(bool sign) {
    this->_signed = sign;
}

int AForm::getExecGrade() const {
    return this->execGrade;
}

/*
********************************************************************************************************************************************************************
*/

// Functions:

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    std::cout << "\nBureaucrat grade = " << bureaucrat.getGrade() << "; _signGrade = " << this->_signGrade << std::endl;
    if (bureaucrat.getGrade() <= 50) {
        std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
        this->_signed = true;
    }
    else {
        std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << std::endl;
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!this->_signed) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->execGrade) {
        throw AForm::GradeTooLowException();
    }
    this->executeAction();
}

void AForm::executeAction() const {
    std::cout << "Executing action of AForm" << std::endl;
}

void AForm::printForm() const {
    std::cout << *this << std::endl;
}

/*
********************************************************************************************************************************************************************
*/

// Exceptions:

const char* AForm::GradeTooHighException::what() const throw() {
    return "\nERROR: AForm grade too high\n";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "\nERROR: AForm grade too low\n";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "\nERROR: AForm not signed\n";
}

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, AForm const& rhs) {
    os << "\n***AForm:\n" << "Name = " << rhs.getName() << "; Sign grade = " << rhs.getSignGrade() << "; AForm signed = " << (rhs.getSigned() ? "true" : "false") << std::endl;
    return os;
}