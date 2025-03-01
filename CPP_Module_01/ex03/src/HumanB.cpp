#include <iostream>
#include <string>
#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
    std::cout << "HumanB constructor called for: " << this->name << std::endl;
}

HumanB::~HumanB(void) {
    std::cout << "HumanB destructor called for: " << this->name << std::endl;
    this->weapon = NULL;
    this->name = "";
}

void HumanB::setName(std::string &name) {
    this->name = name;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon; // We pass the address of the weapon object.
}

//• HumanB may not always have a weapon.
void HumanB::attack(void) {
    if (this->weapon->getType() == "")
        std::cout << this->name << " attacks with their bare hands" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
