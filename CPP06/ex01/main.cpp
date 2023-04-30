/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:54:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 09:01:49 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Serializer serializer;
    Data data = { 2146, 42.0f, 65146565, 'h' };

    std::cout << "Data value: " << data << std::endl;
    uintptr_t serializedData = serializer.serialize(&data);
    std::cout << "Serialized data: \033[1;33m" << serializedData << "\033[0m" << std::endl;
    Data* deserializedData = serializer.deserialize(serializedData);
    std::cout << "Deserialized data: " << data << std::endl;
    if (deserializedData == &data)
        std::cout << "Deserialized data compares equal to the original pointer" << std::endl;
    else
        std::cout << "Deserialized data does not compare equal to the original pointer" << std::endl;

    return 0;
}