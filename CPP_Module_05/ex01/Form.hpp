#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration of Bureaucrat class

class Form {
    public:
        //constructors and destructors
        Form();
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();
        // exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        //getters and setters
        std::string getName() const;
        bool        getSigned() const;
        int         getSignGrade() const;
        void        setSigned(bool sign);
        //functions
        void        beSigned(const Bureaucrat& bureaucrat);
    private:
        const       std::string _name;
        const       int _signGrade;
        bool        _signed;
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);

#endif