/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:59 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 08:18:56 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    const int value = 5;
    
    vec.push_back( 1 );
    vec.push_back( 2 );
    vec.push_back( 3 );
    vec.push_back( 4 );
    vec.push_back( 5 );
    try {
        const std::vector<int>::iterator it = easyfind( vec, value );
        std::cout << "Found value " << value << " at index " << it - vec.begin() << std::endl;
    } catch( std::exception& e ) {
        std::cout << "Value " << value << " not found" << std::endl;
    }
    try {
        const std::vector<int>::iterator it = easyfind( vec, 126 );
        std::cout << "Found value " << value << " at index " << it - vec.begin() << std::endl;
    } catch( std::exception& e ) {
        std::cout << "Value " << value << " not found" << std::endl;
    }

    return 0;
}