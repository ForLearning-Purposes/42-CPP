#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

class PresidentialPardonForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
    private:
};

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& rhs);

#endif