#include "../include/Cat.hpp"
#include "../include/Animal.hpp"

Cat::Cat() : Animal(), type("Cat"), brain(NULL) {
    // this->hehe = "hehe";
    std::cout << "Cat constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(NULL) {
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
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Derived::MemberFunc" << std::endl;
    std::cout << "Meow Meow" << std::endl;
    std::cout << std::endl;
}

void Cat::printType() const {
    std::cout << "Type: " << this->type << std::endl;
}

Brain *Cat::getBrain() const {
    return brain;
}