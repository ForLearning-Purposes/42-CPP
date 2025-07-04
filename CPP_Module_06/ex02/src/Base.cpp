/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:31:04 by msimic            #+#    #+#             */
/*   Updated: 2025/06/07 17:31:05 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>


Base::~Base() {}

/*
Base * generate(void);
It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation
*/
Base *generate(void) {
    Base *ret;

    int random = std::rand() % 4; // Generate a random number between 0 and 2

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
    if (!p) {
        std::cout << "Null pointer" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
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
    } catch (std::exception &ex) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b; // Avoid unused variable warning
            std::cout << "B" << std::endl;
        } catch (std::exception &ex) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c; // Avoid unused variable warning
                std::cout << "C" << std::endl;
            } catch (std::exception &ex) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}