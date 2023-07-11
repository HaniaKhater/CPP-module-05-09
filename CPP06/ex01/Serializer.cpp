/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:54:59 by hania             #+#    #+#             */
/*   Updated: 2023/07/11 03:12:02 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <ostream>

Serializer::Serializer() {}

Serializer::Serializer( const Serializer& ref ) {
    *this = ref;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=( const Serializer &rhs ) {
    if (this == &rhs)
		*this = rhs;
    return *this;
}

uintptr_t   Serializer::serialize( Data* ptr ) {
    uintptr_t	result;

	result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data*       Serializer::deserialize( const uintptr_t raw ) {
	Data*	result;

	result = reinterpret_cast<Data *>(raw);
	return (result);
}

std::ostream& operator<<( std::ostream& os, const Data& data ) {
	const std::string	color = "\033[1;32m";
	const std::string	reset = "\033[0m";

    os << "{ Int: " << color << data.valueInt << reset << ", Float: " << color << data.valueFloat << reset << ", Double: " << color << data.valueDouble << reset << ", Char: " << color << data.valueChar << reset << " }" << std::endl;
    return os;
}