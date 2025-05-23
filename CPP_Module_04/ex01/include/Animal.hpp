#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

/*
The type of the Animal class can be left empty or set to the value of your choice
*/

class Animal {
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal();
        virtual void makeSound() const;
        virtual void printType() const;
    protected:
        std::string type;
};

/*
Info:
- destructors are the only member functions
  that must be explicitly marked as virtual
  in the base class when you have inheritance
  and polymorphism (i.e., a pointer or
  reference to the base class points to a
  derived class object), the destructor needs
  to be virtual to ensure the correct destructor
  is called.
- If the destructor of the base class is not virtual,
  and you delete an object through a base class
  pointer, the destructor of the derived class will
  not be called, which can result in resource leaks.
- So When you delete an object through a base class
  pointer, if the base class destructor is virtual,
  C++ will properly call the derived class destructor
  first, then the base class destructor.
- And If the destructor is not virtual, only the
  base class destructor will be called, potentially
  skipping necessary cleanup in the derived class.
*/

#endif