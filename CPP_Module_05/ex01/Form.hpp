#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

/*  
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
*/

class Form {
    public:
        Form();
        Form(std::string name, int signGrade);
        ~Form();
        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);

#endif