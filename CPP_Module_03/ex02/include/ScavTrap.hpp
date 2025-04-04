#ifndef SVAC_TRAP_HPP
#define SVAC_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
    protected:
        bool _gateKeeperMode;
};

#endif