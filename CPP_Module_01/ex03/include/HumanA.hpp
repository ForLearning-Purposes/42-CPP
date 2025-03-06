#ifndef HUMANA_HPP
# define HUMANA_HPP

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
class HumanA {
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void attack(void);
        bool isArmed(void);
    private:
        std::string name;
        Weapon &weapon;
};

/*
Why Use a Reference (Weapon &weapon) in HumanA?
• A reference must be initialized when declared and cannot be changed afterward.
• This means HumanA must always have a weapon; it cannot exist without being armed.
• Since references do not allow reassignment, HumanA's weapon cannot change once set in the constructor.
*/

#endif