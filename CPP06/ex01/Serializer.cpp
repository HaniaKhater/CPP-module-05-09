/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:54:59 by hania             #+#    #+#             */
/*   Updated: 2023/04/24 08:55:00 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer( const Serializer& ref ) {
    *this = ref;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=( const Serializer &rhs ) {
    *this = rhs;
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr) {
    uintptr_t	result;

	result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data*       Serializer::deserialize(uintptr_t raw) {
	Data*	result;

	result = reinterpret_cast<Data *>(raw);
	return (result);
}