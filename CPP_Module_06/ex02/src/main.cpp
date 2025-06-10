/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:31:07 by msimic            #+#    #+#             */
/*   Updated: 2025/06/07 17:31:08 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Base.hpp"
#include <cstdlib>
#include <ctime>

int main () {
    std::srand(std::time(0));

    Base base;
    Base *ptr = generate();
    std::cout << "Using pointer:" << std::endl;
    identify(ptr);
    std::cout << "Using reference:" << std::endl;
    // Base &ref = *ptr;
    // identify(ref);
    identify(&*ptr);
    delete ptr;
}