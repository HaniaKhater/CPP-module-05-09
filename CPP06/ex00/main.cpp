/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 06:17:42 by hania             #+#    #+#             */
/*   Updated: 2023/07/11 02:10:28 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
    std::cerr << "Please try ./ScalarConverter [literal]" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}