#include "../include/Dog.hpp"
#include "../include/Animal.hpp"

Dog::Dog() : Animal(), type("Dog") {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog &copy) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        this->type = copy.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Derived::MemberFunc" << std::endl;
    std::cout << "Woof Woof" << std::endl;
    std::cout << std::endl;
}

void Dog::printType() const {
    std::cout << "Type: " << this->type << std::endl;
}