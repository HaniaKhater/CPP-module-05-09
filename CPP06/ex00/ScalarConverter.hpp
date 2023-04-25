/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 06:18:02 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 06:18:09 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <climits>
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <sstream>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter( const ScalarConverter &ref );
        ~ScalarConverter();
        ScalarConverter&    operator=( const ScalarConverter &rhs );
        static double       convert( std::string in );
};

#endif