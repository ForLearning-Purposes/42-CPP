#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// Constructors and destructors:
Bureaucrat::Bureaucrat() : _name("Default_Name"), _grade(150) {
    std::cout << "\nDefault constructor called for Bureaucrat" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    std::cout << "\nConstructor with name and grade called for Bureaucrat" << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name) {
    std::cout << "\nCopy constructor called for Bureaucrat" << std::endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    std::cout << "Bureaucrat assignation operator is called" << std::endl;
    if (&copy == this) {
        return *this;
    }
    this->_grade = copy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "\nDestructor called for Bureaucrat" << std::endl;
}

// Getters and setters:
const std::string Bureaucrat::getName() const {
    return this->_name;
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
// Increment and decrement grade:
void Bureaucrat::incrementGrade() {
    std::cout << "\nIncrementing grade" << std::endl;
    std::cout << "Current grade: " << this->_grade << std::endl;
    if (this->_grade <= 1) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade--;
    std::cout << "New grade: " << this->_grade << std::endl;
}
void Bureaucrat::decrementGrade() {
    std::cout << "\nDecrementing grade" << std::endl;
    std::cout << "Current grade: " << this->_grade << std::endl;
    if (this->_grade >= 150) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade++;
    std::cout << "New grade: " << this->_grade << "\n" << std::endl;
}

//function to sign a form: 
void Bureaucrat::signForm(AForm &form) const {
    form.beSigned(*this);
}

// User-defined exception classes:
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "\nERROR: Grade too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "\nERROR: Grade too low\n";
}

// Overload << operator:
std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs) {
    os << "\n***Bureaucrat:\n" << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return os;
}

/*
INFO:
- When throw Bureaucrat::GradeTooHighException(); is executed:
1. A temporary object of GradeTooHighException is created.
2. Execution immediately stops in the function where throw occurs.
3. The exception object is passed up to the nearest catch block that can handle it.
- If no catch block is found, std::terminate() is called, which crashes the program.

- throw Bureaucrat::GradeTooHighException(); //The throw keyword in this context is actually throwing an exception, which means it's signaling that an error has occurred

*/