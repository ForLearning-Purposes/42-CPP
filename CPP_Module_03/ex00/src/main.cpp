#include "../include/ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "***ClapTrap Testining Orthodox Canonical Class form first" << std::endl;
    std::cout << std::endl;

    ClapTrap ClapTrap1;
    ClapTrap ClapTrap2("Monika");
    ClapTrap ClapTrap3;
    ClapTrap ClapTrap4("Yuri");

    ClapTrap3 = ClapTrap2;
    std::cout << "ClapTrap3 name: " << ClapTrap3.getName() << std::endl;

    //**********************************************************/

    std::cout << std::endl;
    std::cout << "***ClapTrap Testing Functions" << std::endl;
    std::cout << std::endl;

    //attack
    ClapTrap1.attack("Natsuki");
    ClapTrap1.attack("Sayori");
    ClapTrap1.attack("Monika");
    ClapTrap1.attack("Yuri");
    ClapTrap1.attack("Monika");
    ClapTrap1.attack("Yuri");
    ClapTrap1.attack("Monika");
    ClapTrap1.attack("Yuri");
    ClapTrap1.attack("Monika");
    ClapTrap1.attack("Yuri");
    ClapTrap1.attack("Monika");

    //takeDamage
    ClapTrap1.takeDamage(5);
    ClapTrap1.takeDamage(5); // Dead
    ClapTrap1.takeDamage(5);
    ClapTrap1.attack("Monika"); //Dead

    //beRepaired
    ClapTrap1.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5);
    ClapTrap2.beRepaired(5); // No energy points left
}