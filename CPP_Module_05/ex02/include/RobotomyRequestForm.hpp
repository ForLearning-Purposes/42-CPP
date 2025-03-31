#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

class RobotomyRequestForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
    private:
};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& rhs);

#endif