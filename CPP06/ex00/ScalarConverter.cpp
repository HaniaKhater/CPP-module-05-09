/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 06:17:56 by hania             #+#    #+#             */
/*   Updated: 2023/07/11 01:49:46 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <sstream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	(void)ref;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

void	ScalarConverter::printChar(std::string input)
{
	std::istringstream iss(input);
	int ascii_value;
	iss >> ascii_value;
	char c = static_cast<char>(ascii_value);
	if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
		std::cout << "char:   \'" + input + "\'" << std::endl;
	else if (ascii_value >= 32 && ascii_value <= 126)
		std::cout << "char:   \'" + std::string(1, c) + "\'" << std::endl;
	else if (ascii_value < 0 || ascii_value > 127)
		std::cout << "char:   impossible" << std::endl;
	else
		std::cout << "char:   Non displayable" << std::endl;
}

void ScalarConverter::printInt(std::string input)
{
	std::istringstream iss(input);
	int value;
	if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
		std::cout << "int:    " << static_cast<int>(input[0]) << std::endl;
	else if (!(iss >> value))
		std::cout << "int:    impossible" << std::endl;
	else
	{
		try
		{
			int i = 0;
			bool dot_found = false;
			while (input[i])
			{
				if (i == 0 && (input[i] == '+' || input[i] == '-'))
					i++;
				if (dot_found == false && (input[i] == '.'))
				{
					dot_found = true;
					i++;
				}
				if (dot_found == true && (i == static_cast<int>(input.length()-1) && input[i] == 'f'))
					i++;
				if (!isdigit(input[i]))
					break;
				i++;
			}
			if (input[i])
				std::cout << "int:    impossible" << std::endl;
			else
				std::cout << "int:    " << atoi(input.c_str()) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "int:    impossible" << std::endl;
		}
	}
}

void ScalarConverter::printFloat(std::string input)
{
	std::istringstream iss(input);
	float value;
	if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
		std::cout << "float:  " << static_cast<float>(input[0]) << ".0f" << std::endl;
	else if (!(iss >> value))
		std::cout << "float:  impossible" << std::endl;
	else
	{
		try
		{
			int i = 0;
			bool dot_found = false;
			while (input[i])
			{
				if (i == 0 && (input[i] == '+' || input[i] == '-'))
					i++;
				if (dot_found == false && (input[i] == '.'))
				{
					dot_found = true;
					i++;
				}
				if (dot_found == true && (i == static_cast<int>(input.length()-1) && input[i] == 'f'))
					i++;
				if (!isdigit(input[i]))
					break;
				i++;
			}
			std::ostringstream oss;
			oss << atof(input.c_str());
			std::string output = oss.str();
			if (input[i])
				std::cout << "float:  impossible" << std::endl;
			else if (output.find(".") == std::string::npos)
				std::cout << "float   " << atof(input.c_str()) << ".0f" << std::endl;
			else
				std::cout << "float   " << atof(input.c_str()) << "f" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "float:  impossible" << std::endl;
		}
	}
}

void ScalarConverter::printDouble(std::string input)
{
	std::istringstream iss(input);
	double value;
	if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	else if (!(iss >> value))
		std::cout << "double: impossible" << std::endl;
	else
	{
		try
		{
			int i = 0;
			bool dot_found = false;
			while (input[i])
			{
				if (i == 0 && (input[i] == '+' || input[i] == '-'))
					i++;
				if (dot_found == false && (input[i] == '.'))
				{
					dot_found = true;
					i++;
				}
				if (dot_found == true && (i == static_cast<int>(input.length()-1) && input[i] == 'f'))
					i++;
				if (!isdigit(input[i]))
					break;
				i++;
			}
			std::ostringstream oss;
			oss << strtod(input.c_str(), NULL);
			std::string output = oss.str();
			if (input[i])
				std::cout << "double: impossible" << std::endl;
			else if (output.find(".") == std::string::npos)
				std::cout << "double: " << strtod(input.c_str(), NULL) << ".0" << std::endl;
			else
				std::cout << "double: " << strtod(input.c_str(), NULL) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "double: impossible" << std::endl;
		}
	}
}

bool isWeirdLiteral(std::string input)
{
	return (input == "-inf" || input == "+inf" || input == "nan" || input == "-inff" || input == "+inff" || input == "nanf");
}


void ScalarConverter::convert(std::string input)
{
	if (isWeirdLiteral(input))
	{
		std::cout << "char:   impossible" << std::endl << "int:    impossible" << std::endl;
		if (input[0] == '-' || input[0] == '+')
			std::cout << "float:  " << input[0] << "inff" << std::endl << "double: " << input[0] << "inf" << std::endl;
		else
			std::cout << "float:  " << "nanf" << std::endl << "double: " << "nan" << std::endl;
		return;
	}
	ScalarConverter::printChar(input);
	ScalarConverter::printInt(input);
	ScalarConverter::printFloat(input);
	ScalarConverter::printDouble(input);
}