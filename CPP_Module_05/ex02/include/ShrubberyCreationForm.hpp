#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

class ShrubberyCreationForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();
    private:
};

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& rhs);

#endif