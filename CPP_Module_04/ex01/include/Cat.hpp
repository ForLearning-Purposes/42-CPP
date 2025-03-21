#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

/*
These two derived classes must set their type field depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
*/

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();
        void makeSound() const;
        void printType() const;
        Brain *getBrain() const;
        // std::string hehe;
    private:
        std::string type;
        Brain *brain;
};

#endif