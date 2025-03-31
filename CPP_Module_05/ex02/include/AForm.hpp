#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

//the base class Form must be an abstract class
//Keep in mind that the form’s attributes need to remain private and
//that they belong to the base class

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        std::string         getName() const;
        bool                getSigned() const;
        int                 getSignGrade() const;
        void                setSigned(bool sign);

        void                beSigned(const Bureaucrat& bureaucrat);
        void                execute(const Bureaucrat& executor) const;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
    protected:
        virtual void executeAction() const; // Pure virtual function to be implemented in derived classes
    private:
        const       std::string _name;
        const       int _signGrade;
        bool        _signed;
        const int   execGrade;
};

std::ostream& operator<<(std::ostream& os, AForm const& rhs);

#endif