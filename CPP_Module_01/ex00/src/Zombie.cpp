#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "A Zombie (" << this->name << ") is born." << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << this->name << " is dead." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}