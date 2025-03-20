#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &copy) {
    std::cout << "AAnimal assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        this->type = copy.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "Base::MemberFunc" << std::endl;
    std::cout << "chirp chirp" << std::endl;
    std::cout << std::endl;
}

void AAnimal::printType() const {
    std::cout << "Type: " << this->type << std::endl;
}