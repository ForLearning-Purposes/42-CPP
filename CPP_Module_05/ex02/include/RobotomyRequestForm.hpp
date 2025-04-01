#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

/*
********************************************************************************************************************************************************************
*/

class RobotomyRequestForm : public AForm {
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();

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

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& rhs);

/*
********************************************************************************************************************************************************************
*/

#endif