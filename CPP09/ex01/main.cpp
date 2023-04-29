/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:22:22 by hania             #+#    #+#             */
/*   Updated: 2023/04/29 10:37:07 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

int main( int ac, char* av[] ) {
    if ( ac != 2 ) {
        std::cerr << "Error: wrong number of arguments. Try " << av[0] << " \"RPN expression\"" << std::endl;
        return EXIT_FAILURE;
    }  
    std::string input = av[1];
    
    try {
        performRNP( input );
    } catch ( std::invalid_argument& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}