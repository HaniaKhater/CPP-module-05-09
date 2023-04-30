/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:31:39 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 03:51:33 by hania            ###   ########.fr       */
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
        Parse( ac - 1, &av[1], nbs );
    } catch ( std::invalid_argument &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Before : "; 
    if ( ac < 11 ) {
        for ( int i = 1; i < ac; i++ )
            std::cout << av[i] << " ";
    } else {
        for ( int i = 1; i < 10; i++ )
            std::cout << av[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
    
    bool    odd = false;
    int     tmp;
    if ( (ac - 1) % 2 != 0 ) {
        odd = true;
        tmp = std::atoi( av[ac - 1] );
        ac-=1;
    }

    std::vector<std::pair<unsigned int, unsigned int> > vec;
    for ( int i = 1; i < ac; i+=2 )
        vec.push_back( std::make_pair( std::atoi(av[i]), std::atoi(av[i + 1]) ) );
    MergeInsertVector( vec, odd, tmp );

    std::deque<std::pair<unsigned int, unsigned int> > deq;
    for ( int i = 1; i < ac; i+=2 )
        deq.push_back( std::make_pair( std::atoi(av[i]), std::atoi(av[i + 1]) ) );
    MergeInsertDeque( deq, odd, tmp );

    return 0;
}