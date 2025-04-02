#include <iostream>
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"


int main()
{
    try {
        Intern intern;
        AForm* form1;
        form1 = intern.makeForm("presidential pardon", "Bender");
        delete form1;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}