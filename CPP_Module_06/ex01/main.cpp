/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:29:14 by msimic            #+#    #+#             */
/*   Updated: 2025/06/07 17:29:15 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main() {
    Data employee_data = {123342, "Monika Simic"};

    std::cout << "Original Data: " << employee_data.employee_ID << ", " << employee_data.employee_name << std::endl;

    uintptr_t ser_data = Serializer::serialize(&employee_data);
    std::cout << "Serialized Data: " << ser_data << std::endl; //
    Data* des_data = Serializer::deserialize(ser_data);
    std::cout << "Deserialized Data: " << des_data->employee_ID << ", " << des_data->employee_name << std::endl;
}