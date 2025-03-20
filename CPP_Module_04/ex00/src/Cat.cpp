#include "../include/Cat.hpp"
#include "../include/Animal.hpp"

Cat::Cat() : Animal(), type("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat &copy) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        this->type = copy.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Derived::MemberFunc" << std::endl;
    std::cout << "Meow Meow" << std::endl;
    std::cout << std::endl;
}

void Cat::printType() const {
    std::cout << "Type: " << this->type << std::endl;
}