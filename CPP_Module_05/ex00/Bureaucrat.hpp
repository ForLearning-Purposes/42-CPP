#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        void incrementGrade();
        void decrementGrade();

        const std::string getName() const;
        // void setName(const std::string name); //const name
        int getGrade() const;
        void setGrade(const int grade);

        // User-defined exception classes:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw(); //https://cplusplus.com/reference/exception/exception/what/
        }; // Function may or may not throw exceptions. No restrictions.

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw(); // This is an exception specification. It means that the function does not throw any exceptions. the exception specification was not enforced at compile time—only at runtime.
        }; //throw(); -> Declares the function does not throw. If it does, std::terminate() is called.

    private:
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs);

#endif