#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"

/*
In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why? Think about it before
starting this exercise.
*/
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        std::cout << "\n\n" << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
