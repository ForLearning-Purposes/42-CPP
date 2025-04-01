#include <iostream>
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"


int main()
{
    try {
        {
            Intern intern;
            AForm* form1;
            form1 = intern.makeForm("presidential pardon", "Bender");
            form1->beSigned(Bureaucrat("Bureaucrat", 1));
            delete form1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}