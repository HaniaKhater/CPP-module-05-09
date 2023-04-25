/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 06:17:56 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 06:17:58 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <sstream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter &ref ) {
    (void)ref;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&    ScalarConverter::operator=( const ScalarConverter& rhs ) {
    (void)rhs;
    return *this;
}

double ScalarConverter::convert( std::string in )
{
	double out;
	try
	{
		std::string number_as_text(in);
		std::istringstream number_stream(number_as_text);
		number_stream >> out;
	}
	catch (std::invalid_argument& e)
	{
		if (in.length() == 1)
			return in[0];
		throw e;
	}
	return out;
}
