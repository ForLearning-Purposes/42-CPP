/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:26:15 by msimic            #+#    #+#             */
/*   Updated: 2025/06/07 17:26:16 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./convert <value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]); // To call function without creating an object is called static function.
    //ScalarConverter converter;
    return 0;
}