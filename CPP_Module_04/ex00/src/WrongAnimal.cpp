#include "../include/WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        this->type = copy.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Base::MemberFunc" << std::endl;
    std::cout << "WrongAnimal: chirp chirp" << std::endl;
    std::cout << std::endl;
}