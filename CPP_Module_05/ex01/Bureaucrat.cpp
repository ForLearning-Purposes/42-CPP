#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and destructors:
Bureaucrat::Bureaucrat() : _name("Default_Name"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {this->setGrade(grade);}
//add copy constructor and assignment operator
Bureaucrat::~Bureaucrat() {}

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
void Bureaucrat::signForm(Form &form) const {
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