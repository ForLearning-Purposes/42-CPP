#include <iostream>
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"


int main()
{
    try {
        {
            Bureaucrat bureaucrat("John", 1);
            std::cout << bureaucrat << std::endl;

            AForm form;
            std::cout << form << std::endl;
            std::cout << std::endl;
            // form.beSigned(bureaucrat);
            form.setSigned(true);
            form.execute(bureaucrat);
            std::cout << std::endl;
            std::cout << std::endl;


            PresidentialPardonForm presidentialForm("Target1");
            std::cout << presidentialForm << std::endl;

            RobotomyRequestForm robotomyForm("Target2");
            std::cout << robotomyForm << std::endl;

            ShrubberyCreationForm shrubberyForm("Target3");
            std::cout << shrubberyForm << std::endl;
        }

        {

        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}