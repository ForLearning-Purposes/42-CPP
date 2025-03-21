#include "../include/Dog.hpp"
#include "../include/AAnimal.hpp"

Dog::Dog() : AAnimal(), type("Dog"), brain(NULL) {
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy), brain(NULL) {
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
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Derived::MemberFunc" << std::endl;
    std::cout << "Woof Woof" << std::endl;
    std::cout << std::endl;
}

void Dog::printType() const {
    std::cout << "Type: " << this->type << std::endl;
}

Brain *Dog::getBrain() const {
    return brain;
}