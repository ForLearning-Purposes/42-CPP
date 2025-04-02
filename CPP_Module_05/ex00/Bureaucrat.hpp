#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

/*
********************************************************************************************************************************************************************
*/

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();
        void incrementGrade();
        void decrementGrade();
        const std::string getName() const;
        int getGrade() const;
        void setGrade(const int grade);

        // User-defined exception classes:
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
        int _grade;
};

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs);

/*
********************************************************************************************************************************************************************
*/

/*
INFO;
- https://cplusplus.com/reference/exception/exception/what/
- "const char* what() const throw();" Function may or may not throw exceptions.
  No restrictions.
- This is an exception specification. It means that the function does
  not throw any exceptions. the exception specification was not enforced
  at compile time—only at runtime.
- throw(); -> Declares the function does not throw. If it does,
  std::terminate() is called.
*/
#endif