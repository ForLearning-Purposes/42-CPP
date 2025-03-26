#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        const std::string getName() const;
        void setName(const std::string name);
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
        std::string _name;
        int _grade;
};

#endif