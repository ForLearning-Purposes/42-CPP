#include "../include/Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal &copy) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        this->type = copy.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Base::MemberFunc" << std::endl;
    std::cout << "chirp chirp" << std::endl;
    std::cout << std::endl;
}

void Animal::printType() const {
    std::cout << "Type: " << this->type << std::endl;
}