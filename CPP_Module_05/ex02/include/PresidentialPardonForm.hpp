#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

/*
********************************************************************************************************************************************************************
*/
class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        const std::string getTarget() const;

        //AForm getters
        const std::string   getAFormName() const;
        bool                getAFormSigned() const;
        int                 getAFormSignGrade() const;
        int                 getAFormExecGrade() const;

        void execute(const Bureaucrat& executor) const;
        void executeAction() const;

    private:
        const std::string _target;

};

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& rhs);

/*
********************************************************************************************************************************************************************
*/

#endif