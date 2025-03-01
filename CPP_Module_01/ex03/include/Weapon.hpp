#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

/*
• A private attribute type, which is a string.
• A getType() member function that returns a constant reference to type.
• A setType() member function that sets type using the new value passed as a parameter.
*/
class Weapon {
    public:
        Weapon(std::string type);
        ~Weapon(void);
        const std::string& getType(void) const;
        void setType(std::string type);
    private:
        std::string type;

};

#endif