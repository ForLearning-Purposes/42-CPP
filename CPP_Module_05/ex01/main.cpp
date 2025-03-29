#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat helo("Monika", 149);
        Form form;
        helo.setGrade(50);
        helo.signForm(form);
        std::cout << helo;
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << "\n***Caught an exception***" << e.what() << std::endl;
    }
}