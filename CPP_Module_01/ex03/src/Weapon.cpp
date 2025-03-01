#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) {
    std::cout << "Weapon constructor called for: " << type << std::endl;
    this->type = type;
}

Weapon::~Weapon(void) {
    std::cout << "Weapon destructor called for: " << this->type << std::endl;
    this->type = "";
}

const std::string& Weapon::getType(void) const {
    return (this->type);
}

void Weapon::setType(std::string type) {
    this->type = type;
}
