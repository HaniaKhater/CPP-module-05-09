/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 06:18:02 by hania             #+#    #+#             */
/*   Updated: 2023/07/11 01:44:21 by hkhater          ###   ########.fr       */
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

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &ref);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &rhs);
	static void printChar(std::string input);
	static void printInt(std::string input);
	static void printFloat(std::string input);
	static void printDouble(std::string input);
    static void	convert( std::string in );
};

#endif