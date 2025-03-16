#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
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
    std::cout << "***ScavTrap Testining Orthodox Canonical Class form first" << std::endl;
    std::cout << std::endl;

    ScavTrap ScavTrap1;
    ScavTrap ScavTrap2("Tadashi");
    //ScavTrap ScavTrap3;
    //ScavTrap ScavTrap4("Dominique");

    //ScavTrap3 = ScavTrap2;
    //std::cout << "ClapTrap3 name: " << ClapTrap3.getName() << std::endl;

    //**********************************************************/

    std::cout << std::endl;
    std::cout << "***FragTrap Testining Orthodox Canonical Class form first" << std::endl;
    std::cout << std::endl;

    FragTrap FragTrap1;
    FragTrap FragTrap2("Tadashi");
    //FragTrap FragTrap3;
    //FragTrap FragTrap4("Dominique");

    //FragTrap3 = FragTrap2;
    //std::cout << "ClapTrap3 name: " << ClapTrap3.getName() << std::endl;

    //**********************************************************/

    std::cout << std::endl;
    std::cout << "***Testing Functions" << std::endl;
    std::cout << std::endl;

    ClapTrap1.attack("Monika");
    ScavTrap1.attack("Tadashi");
    ScavTrap1.attack("Tadashi");
    ScavTrap1.guardGate();
    ScavTrap1.beRepaired(10);
    FragTrap1.highFivesGuys();
    FragTrap2.highFivesGuys();

    ScavTrap1.takeDamage(10);

    //**********************************************************/

    std::cout << std::endl;
    std::cout << "***Destructor Testing" << std::endl;
    std::cout << std::endl;

}