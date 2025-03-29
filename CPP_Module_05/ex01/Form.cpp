#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form() : _name("Officially Official Form of Officialness"), _signGrade(150), _signed(false) {}
Form::Form(const Form& copy) : _name(copy._name), _signGrade(copy._signGrade) {*this = copy;}
Form& Form::operator=(const Form& copy) {
    std::cout << "Form assignation operator is called" << std::endl;
    if (&copy == this) {
        return *this;
    }
    this->_signed = copy._signed;
    return *this;
}
Form::~Form() {}

// Getters and setters:
std::string Form::getName() const {
    return this->_name;
}
bool Form::getSigned() const {
    return this->_signed;
}
int Form::getSignGrade() const {
    return this->_signGrade;
}
void Form::setSigned(bool sign) {
    this->_signed = sign;
}

// Exceptions:
const char* Form::GradeTooHighException::what() const throw() {
    return "\nERROR: Form grade too high\n";
}
const char* Form::GradeTooLowException::what() const throw() {
    return "\nERROR: Form grade too low\n";
}

// Functions:
void Form::beSigned(const Bureaucrat& bureaucrat) {
    std::cout << "\nBureaucrat grade = " << bureaucrat.getGrade() << "; _signGrade = " << this->_signGrade << std::endl;
    if (bureaucrat.getGrade() <= 50) {
        std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
        this->_signed = true;
    }
    else {
        std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << std::endl;
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, Form const& rhs) {
    os << "\n***Form:\n" << "Name = " << rhs.getName() << "; Sign grade = " << rhs.getSignGrade() << "; Form signed = " << (rhs.getSigned() ? "true" : "false") << std::endl;
    return os;
}