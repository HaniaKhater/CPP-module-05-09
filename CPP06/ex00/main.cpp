/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 06:17:42 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 06:20:12 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ---------------------------------------------------------
// NEED TO REVIEW BEFORE SUBMITTING, DOUBLE CHECK EXCEPTIONS
// ---------------------------------------------------------


#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <exception>
#include "ScalarConverter.hpp"

bool isInfinity(double d)
{
	double zero = 0;
	double posinf = 1 / zero;
	double naginf = - 1 / zero;
	if (d == posinf || d == naginf)
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
    std::cerr << "Please try ./ScalarConverter [literal]" << std::endl;
		return 0;
	}

	std::string arg(argv[1]);
	double d;
	try
	{
		d = ScalarConverter::convert(arg);
	}
	catch (std::exception &e)
	{
		std::cout << "char:  impossible" << std::endl;
		std::cout << "int: impossible"<< std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 0;
	}

	std::cout.precision(1);
	std::cout << std::fixed;
	if (d != d || isInfinity(d))
	{
		std::cout << "char:  impossible" << std::endl;
		std::cout << "int: impossible"<< std::endl;
		std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		if (std::isprint(static_cast<char>(d)))
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
		std::cout << "int: "<< static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
