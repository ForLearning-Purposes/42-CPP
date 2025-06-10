/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:29:23 by msimic            #+#    #+#             */
/*   Updated: 2025/06/07 17:29:24 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
    int         employee_ID;
    std::string employee_name;
};

/*
- Take a pointer to a Data object.
- Convert it to an integer using serialize().
- Convert that integer back to a pointer using deserialize().
- Confirm that the pointer you get back is the same as the
  original one
*/

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &rhs);
};

#endif