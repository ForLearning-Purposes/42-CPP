#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

/*
********************************************************************************************************************************************************************
*/
class ShrubberyCreationForm : public AForm {
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();

        const std::string   getTarget() const;

        //AForm getters
        const std::string   getAFormName() const;
        bool                getAFormSigned() const;
        int                 getAFormSignGrade() const;
        int                 getAFormExecGrade() const;

        void                execute(const Bureaucrat& executor) const;
        void                printAForm() const;
        
    private:
        
        void                executeAction() const;
        const std::string _target;

};

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& rhs);

/*
********************************************************************************************************************************************************************
*/

#endif