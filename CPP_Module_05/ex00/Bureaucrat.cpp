#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    this->setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const {
    return this->_name;
}

void Bureaucrat::setName(const std::string name) {
    this->_name = name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::setGrade(const int grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

// User-defined exception classes:
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}