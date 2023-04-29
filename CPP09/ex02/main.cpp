/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:31:39 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 00:23:05 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int     main( int ac, char **av ) {
    long    nbs[ac - 1];
    if ( ac == 1 || ac == 2) {
        if ( ac == 1 )
            std::cerr << "PmergeMe needs numbers to sort. Try ./PmergeME 4 204 26 123" << std::endl;
        if ( ac == 2 )
            std::cout << av[1] << " is already sorted" << std::endl;
        return 0;
    }
    try {
        parse( ac - 1, &av[1], nbs );
    } catch ( std::invalid_argument &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}