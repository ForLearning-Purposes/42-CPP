#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
    std::cout << "HumanA constructor called for: " << this->name << std::endl;
}

HumanA::~HumanA(void) {
    std::cout << "HumanA destructor called for: " << this->name << std::endl;
    this->name = "";
}

//check if the weapon type is empty
bool HumanA::isArmed(void) {
    std::string type = this->weapon.getType();
    for (size_t i = 0; i < type.length(); i++) {
        if (type[i] != ' ')
            return (true);
    }
    return (false);
}

//• HumanA will always be armed.
void HumanA::attack(void) {
    if (!this->isArmed()) {
        std::cout << "Error: " << this->name << " is not armed" << std::endl;
        exit(1);
    }
    else
        std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
