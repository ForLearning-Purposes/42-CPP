#include "../include/WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal(), type("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &copy) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        this->type = copy.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Derived::MemberFunc" << std::endl;
    std::cout << "WrongCat: Meow Meow" << std::endl;
    std::cout << std::endl;
}