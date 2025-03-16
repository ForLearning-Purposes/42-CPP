#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor is called with the name: " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap parameterized constructor is called with the name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout << "ClapTrap copy constructor is called for: " << &copy << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
    std::cout << "ClapTrap assignation operator is called" << std::endl;
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

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor is called for: " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "***Attacking*** " << target << std::endl;
    std::cout << std::endl;
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't attack because it has no hit points left!" << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't attack because it has no energy points left!" << std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
    }
    std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "***Taking Damage***" << std::endl;
    std::cout << std::endl;
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " already died!" << std::endl;
    }
    else if (this->_hitPoints <= amount){
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " died!" << std::endl;
    }
    else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    }
    std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "***Repairing***" << std::endl;
    std::cout << std::endl;
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't be repaired because it has no energy points left!" << std::endl;
    }
    else {
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
    }
    std::cout << std::endl;
}

std::string ClapTrap::getName() const { return this->_name; }

void ClapTrap::setName(const std::string name) { this->_name = name; }