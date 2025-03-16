#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _gateKeeperMode(false) {
    std::cout << "ScavTrap default constructor is called with the name: " << this->_name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeperMode(false) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor is called with the name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor is called for: " << &copy << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << "ScavTrap assignation operator is called" << std::endl;
    if (&copy == this) {
        return *this;
    }
    else {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
        this->_gateKeeperMode = copy._gateKeeperMode;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor is called for: " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "***Attacking*** " << target << std::endl;
    std::cout << std::endl;
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " can't attack because it has no hit points left!" << std::endl;
    }
    else if (this->_energyPoints == 0) {
        std::cout << this->_name << " can't attack because it has no energy points left!" << std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        std::cout << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
    }
    std::cout << std::endl;
}

void ScavTrap::guardGate() {
    if (this->_gateKeeperMode == false) {
        this->_gateKeeperMode = true;
        std::cout << this->_name << " has entered Gate Keeper mode!" << std::endl;
    }
    else {
        this->_gateKeeperMode = false;
        std::cout << this->_name << " has exited Gate Keeper mode!" << std::endl;
    }
}