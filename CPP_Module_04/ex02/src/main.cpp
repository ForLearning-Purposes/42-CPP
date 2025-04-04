#include "../include/AAnimal.hpp"
#include "../include/Brain.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

/*
Subject:
    - Constructors and destructors of each
      class must display specific messages.
      Don’t use the same message for all classes
    - Implement a Dog class that inherits from AAnimal.
    - Implement a Cat class that inherits from AAnimal.
    - These two derived classes must set their type
      field depending on their name. Then, he Dog’s
      type will be initialized to "Dog", and the Cat’s
      type will be initialized to "Cat". The type of
      the AAnimal class can be left empty or set to the
      value of your choice.
    - Every AAnimal must be able to use the member function:
      makeSound() It will print an appropriate sound
    - To ensure you understood how it works, implement a
      WrongCat class that inherits from a WrongAAnimal class.
      If you replace the AAnimal and the Cat by the wrong ones
      in the code above, the WrongCat should output the
      WrongAAnimal sound
*/

int main()
{
    try
    {
        {
            std::cout << "**********Test 1**********" << std::endl;
            std::cout << std::endl;

            std::cout << "***AAnimal: " << std::endl;
            std::cout << "\tinstance of AAnimal can't be crated because AAnimal is abstract class" << std::endl;
            // AAnimal AAnimal;
            // AAnimal.printType();
            // AAnimal.makeSound();
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

            std::cout << "***Cat: " << std::endl;
            AAnimal *cat1 = new Cat();
            cat1->makeSound();
            std::cout << "***Dog: " << std::endl;
            AAnimal *dog1 = new Dog();
            dog1->makeSound();
            delete cat1;
            delete dog1;
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 3**********" << std::endl;
            std::cout << std::endl;
            std::cout << "***Cat: " << std::endl;
            Cat cat;
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 4**********" << std::endl;
            std::cout << std::endl;

            std::cout << "***Array of AAnimals: " << std::endl;
            int n = 4;
            AAnimal *AAnimals[n]; // Array of pointers to AAnimal
            std::cout << "\t- There ase " << n << " AAnimals in the array" << std::endl;
            std::cout << std::endl;
            std::cout << "***Creating array of Dogs and Cats:" << std::endl;
            std::cout << std::endl;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    std::cout << "\t- Dog index " << i << ":" << std::endl;
                    AAnimals[i] = new Dog();
                    AAnimals[i]->makeSound();
                }
                else {
                    std::cout << "\t- Cat index " << i << ":" << std::endl;
                    AAnimals[i] = new Cat();
                    AAnimals[i]->makeSound();
                }
            }

            std::cout << std::endl;
            std::cout << "***Deleting array of Dogs and Cats:" << std::endl;
            std::cout << std::endl;
            for (int i = 0; i < n; i++) {
                std::cout << "\t- AAnimal index " << i << ":" << std::endl;
                delete AAnimals[i];
            }
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 5**********" << std::endl;
            std::cout << std::endl;

            Dog dog;
            dog.getBrain()->setIdea(10, "I am a dog");
            std::cout << dog.getBrain()->getIdea(10) << std::endl;
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 6**********" << std::endl;
            std::cout << std::endl;

            Cat cat;
            {
                Cat cat2 = cat;
            }
            Dog dog;
            {
                Dog dog2 = dog;
            }
            Brain brain;
            {
                Brain brain2 = brain;
            }
        }

        {
            std::cout << std::endl;
            std::cout << "**********Test 7**********" << std::endl;
            std::cout << std::endl;

            const AAnimal* j = new Dog();
            const AAnimal* i = new Cat();
            delete j;//should not create a leak
            delete i;
        }
    }
    catch(const std::bad_alloc& e)
    {
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