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
            /*
            ********************************************************************************************************************
            */
            // std::cout << "*********SHRUBBERYCREATIONFORM:" << std::endl;
            // {
            //     ShrubberyCreationForm shrubberyForm;
            //     std::cout << std::endl;
            //     std::cout << "Form Name: " << shrubberyForm.getAFormName() << std::endl;
            //     std::cout << "Exec Grade: " << shrubberyForm.getAFormExecGrade() << std::endl;
            //     std::cout << "Sign Grade: " << shrubberyForm.getAFormSignGrade() << std::endl;
            //     std::cout << "Target: " << shrubberyForm.getTarget() << std::endl;
            //     shrubberyForm.printAForm();
            // }
            // std::cout << "\n\n*********ROBOTOMYREQUESTFORM:" << std::endl;
            // {
            //     RobotomyRequestForm RobotomyForm;
            //     std::cout << std::endl;
            //     std::cout << "Form Name: " << RobotomyForm.getAFormName() << std::endl;
            //     std::cout << "Exec Grade: " << RobotomyForm.getAFormExecGrade() << std::endl;
            //     std::cout << "Sign Grade: " << RobotomyForm.getAFormSignGrade() << std::endl;
            //     std::cout << "Target: " << RobotomyForm.getTarget() << std::endl;
            //     RobotomyForm.printAForm();
            // }
            // std::cout << "\n\n*********PRESIDENTIALPARDONFORM:" << std::endl;
            // {
            //     PresidentialPardonForm PresidentialForm;
            //     std::cout << std::endl;
            //     std::cout << "Form Name: " << PresidentialForm.getAFormName() << std::endl;
            //     std::cout << "Exec Grade: " << PresidentialForm.getAFormExecGrade() << std::endl;
            //     std::cout << "Sign Grade: " << PresidentialForm.getAFormSignGrade() << std::endl;
            //     std::cout << "Target: " << PresidentialForm.getTarget() << std::endl;
            //     PresidentialForm.printAForm();
            // }
            /*
            ********************************************************************************************************************
            */
            // std::cout << "*********SHRUBBERYCREATIONFORM:" << std::endl;
            // {
            //     ShrubberyCreationForm shrubberyForm("home1");
            //     std::cout << std::endl;
            //     std::cout << "Form Name: " << shrubberyForm.getAFormName() << std::endl;
            //     std::cout << "Exec Grade: " << shrubberyForm.getAFormExecGrade() << std::endl;
            //     std::cout << "Sign Grade: " << shrubberyForm.getAFormSignGrade() << std::endl;
            //     std::cout << "Target: " << shrubberyForm.getTarget() << std::endl;
            //     shrubberyForm.printAForm();
            // }
            // std::cout << "\n\n*********ROBOTOMYREQUESTFORM:" << std::endl;
            // {
            //     RobotomyRequestForm RobotomyForm("home2");
            //     std::cout << std::endl;
            //     std::cout << "Form Name: " << RobotomyForm.getAFormName() << std::endl;
            //     std::cout << "Exec Grade: " << RobotomyForm.getAFormExecGrade() << std::endl;
            //     std::cout << "Sign Grade: " << RobotomyForm.getAFormSignGrade() << std::endl;
            //     std::cout << "Target: " << RobotomyForm.getTarget() << std::endl;
            //     RobotomyForm.printAForm();
            // }
            // std::cout << "\n\n*********PRESIDENTIALPARDONFORM:" << std::endl;
            // {
            //     PresidentialPardonForm PresidentialForm("home3");
            //     std::cout << std::endl;
            //     std::cout << "Form Name: " << PresidentialForm.getAFormName() << std::endl;
            //     std::cout << "Exec Grade: " << PresidentialForm.getAFormExecGrade() << std::endl;
            //     std::cout << "Sign Grade: " << PresidentialForm.getAFormSignGrade() << std::endl;
            //     std::cout << "Target: " << PresidentialForm.getTarget() << std::endl;
            //     PresidentialForm.printAForm();
            // }
            /*
            ********************************************************************************************************************
            */
            std::cout << "*********SHRUBBERYCREATIONFORM:" << std::endl;
            {
                Bureaucrat bureaucrat("Bureaucrat", 1);
                ShrubberyCreationForm shrubberyForm("home1");
                bureaucrat.signForm(shrubberyForm);
                shrubberyForm.execute(bureaucrat);
                shrubberyForm.printAForm();
            }
            std::cout << "\n\n*********ROBOTOMYREQUESTFORM:" << std::endl;
            {
                Bureaucrat bureaucrat("Bureaucrat", 45);
                RobotomyRequestForm RobotomyForm("home2");
                bureaucrat.signForm(RobotomyForm);
                RobotomyForm.execute(bureaucrat);
                RobotomyForm.printAForm();
            }
            std::cout << "\n\n*********PRESIDENTIALPARDONFORM:" << std::endl;
            {
                Bureaucrat bureaucrat("Bureaucrat", 5);
                PresidentialPardonForm PresidentialForm("home3");
                bureaucrat.signForm(PresidentialForm);
                PresidentialForm.execute(bureaucrat);
                // PresidentialForm.printAForm();
            }
            /*
            ********************************************************************************************************************
            */
        }
        {
            /*
            ********************************************************************************************************************
            */
            /*
            ********************************************************************************************************************
            */
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}