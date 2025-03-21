#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

/*
Subject:
    - Constructors and destructors of each
      class must display specific messages.
      Don’t use the same message for all classes
    - Implement a Dog class that inherits from Animal.
    - Implement a Cat class that inherits from Animal.
    - These two derived classes must set their type
      field depending on their name. Then, he Dog’s
      type will be initialized to "Dog", and the Cat’s
      type will be initialized to "Cat". The type of
      the Animal class can be left empty or set to the
      value of your choice.
    - Every animal must be able to use the member function:
      makeSound() It will print an appropriate sound
    - To ensure you understood how it works, implement a
      WrongCat class that inherits from a WrongAnimal class.
      If you replace the Animal and the Cat by the wrong ones
      in the code above, the WrongCat should output the
      WrongAnimal sound
*/

int main()
{
    try {
        {
            // Animal *lol = new Dog();
            // Dog *hehe = new Dog();
            // lol->makeSound();
            // delete lol;
        }

        {
            std::cout << "**********Test 1**********" << std::endl;
            std::cout << std::endl;

            std::cout << "***Animal: " << std::endl;
            Animal animal;
            animal.printType();
            animal.makeSound();
            std::cout << "***Dog: " << std::endl;
            Dog dog;
            dog.printType();
            dog.makeSound();
            std::cout << "***Cat: " << std::endl;
            Cat cat;
            cat.printType();
            cat.makeSound();
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 2**********" << std::endl;
            std::cout << std::endl;

            Animal *cat1 = new Cat();
            cat1->makeSound();
            Animal *dog1 = new Dog();
            dog1->makeSound();
            delete cat1;
            delete dog1;
        
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 3**********" << std::endl;
            std::cout << std::endl;

            WrongAnimal *wrongCat = new WrongCat();
            std::cout << "****Info:\n"
            << "\t- So here you would see Derived message if we used virtual" << std::endl;
            wrongCat->makeSound();
            delete wrongCat;
        }

        {
            // Animal *dog = new Dog();
            // dog = new Cat();
            // std::cout << dog->hehe << std::endl;
        }
    }
    catch (std::bad_alloc &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

//*****************************************************/
/*
Info:
    -   Polymorphism allows the same function or method to
        work differently depending on the object it is
        called on.
    -   Subtype polymorphism allows an object of a subclass
        to be treated as an object of its superclass while
        still maintaining its specific behavior. This enables
        dynamic method overriding and is commonly used in
        object-oriented programming (OOP).
    -   Dynamic Dispatch is the mechanism by which a method
        call is resolved at runtime, rather than at
        compile-time. In object-oriented programming, dynamic
        dispatch is used when calling a method on an object
        through a reference or pointer to the base class,
        where the actual method that gets executed depends
        on the type of the object being pointed to
        (the runtime type).
    -   Virtual Function: Declared with the virtual keyword
        in the base class, allowing derived classes to
        override it.
    -   Dynamic Dispatch: The correct method is determined
        at runtime, based on the actual type of the object,
        not the type of the pointer/reference
*/