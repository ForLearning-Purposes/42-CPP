#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm; // Forward declaration of Form class

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

        void                incrementGrade();
        void                decrementGrade();

        const std::string   getName() const;
        int                 getGrade() const;
        void                setGrade(const int grade);
        void                signForm(AForm &form) const;

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

#endif