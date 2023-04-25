/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:35:50 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 08:35:51 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
		int intArray[10] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8};
		iter(intArray, 10, &print);
		std::cout << std::endl;

		std::string strArray[4] = {"Hello World!", "Now testing with strings", "blablabla", "etc."};
		iter(strArray, 4, &print);
		std::cout << std::endl;

        float floatArray[4] = {42.0f, 0, -42, -5.02};
		iter(floatArray, 4, &print);
		std::cout << std::endl;
	return 0;
}