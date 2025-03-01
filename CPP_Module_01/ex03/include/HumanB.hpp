#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/*
Now, create two classes: HumanA and HumanB. They both have a Weapon and
a name. They also have a member function attack() that displays (without the angle
brackets):
<name> attacks with their <weapon type>
HumanA and HumanB are almost identical except for these two small details:
• While HumanA takes the Weapon in its constructor, HumanB does not.
• HumanB may not always have a weapon, whereas HumanA will always be armed.
*/
class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void setName(std::string &name);
        void setWeapon(Weapon &weapon);
        void attack(void);
    private:
        std::string name;
        Weapon *weapon; // explain why we use pointer here.
};

#endif