#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat helo("Monika", 149);
        helo.incrementGrade();
        std::cout << helo;
    } catch (std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
}