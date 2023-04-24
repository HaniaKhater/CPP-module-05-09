/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:54:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/24 08:54:53 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Serializer serializer;
    Data data = { 2147483630 };

    std::cout << "Data value: \033[1;33m" << data.value << "\033[0m" << std::endl;
    uintptr_t serializedData = serializer.serialize(&data);
    std::cout << "Serialized data: \033[1;33m" << serializedData << "\033[0m" << std::endl;
    Data* deserializedData = serializer.deserialize(serializedData);
    std::cout << "Deserialized data: \033[1;33m" << data.value << "\033[0m" << std::endl;
    if (deserializedData == &data)
        std::cout << "Deserialized data compares equal to the original pointer" << std::endl;
    else
        std::cout << "Deserialized data does not compare equal to the original pointer" << std::endl;

    return 0;
}