/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:55:01 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 09:05:18 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <ostream>
#include <inttypes.h>

typedef struct s_Data {
    unsigned int    valueInt;
    float           valueFloat;
    double          valueDouble;
    char            valueChar;
}   Data;

std::ostream& operator<<( std::ostream& os, const Data& data );

class Serializer {
    public:
        Serializer();
        Serializer( const Serializer &ref );
        ~Serializer();
        Serializer& operator=( const Serializer &rhs );
        uintptr_t serialize( Data* ptr);
        Data* deserialize( const uintptr_t raw );
};

#endif