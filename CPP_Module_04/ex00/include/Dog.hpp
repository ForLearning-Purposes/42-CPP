#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

/*
These two derived classes must set their type field depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
*/

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        ~Dog();
        void makeSound() const;
        void printType() const;
    private:
        std::string type;
};

#endif