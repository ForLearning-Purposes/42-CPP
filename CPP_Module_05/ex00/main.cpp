#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat helo("Monika", 3);
        helo.incrementGrade();
        helo.decrementGrade();
        // helo.incrementGrade();
        // helo.incrementGrade();
        std::cout << helo;
    } catch (std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
}