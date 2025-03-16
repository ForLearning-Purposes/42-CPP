#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor is called with the name: " << this->_name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap parameterized constructor is called with the name: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor is called for: " << &copy << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << "FragTrap assignation operator is called" << std::endl;
    if (&copy == this) {
        return *this;
    }
    else {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor is called for: " << this->_name << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << std::endl;
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
    std::cout << std::endl;
}