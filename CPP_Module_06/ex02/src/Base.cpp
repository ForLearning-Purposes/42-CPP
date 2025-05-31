#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>
#include <cstdlib>


Base::~Base() {}

/*
Base * generate(void);
It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation
*/
Base *generate(void) {
    Base *ret;

    int random = rand() % 3;
    if (random == 0) {
        ret = new A();
    } else if (random == 1) {
        ret = new B();
    } else {
        ret = new C();
    }
    return ret;
}

/*
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B", or "C"
*/
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
    if (p)
        delete p;
}

/*
void identify(Base& p);
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden
*/
void identify(Base& p) {
    Base base;

    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Avoid unused variable warning
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b; // Avoid unused variable warning
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c; // Avoid unused variable warning
                std::cout << "C" << std::endl;
            } catch (std::bad_cast&) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
    if (&p != &base) {
        // Only delete if p is not the base object
        // This prevents deleting a stack-allocated object
        delete &p;
    }
}