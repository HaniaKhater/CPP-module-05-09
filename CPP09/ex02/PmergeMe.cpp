/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:32:11 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 00:35:25 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int isSorted( long nbs[], int qty ) {
    if (qty == 1 || qty == 0) 
        return 1;
    return nbs[qty - 1] >= nbs[qty - 2]
           && isSorted( nbs, qty - 1);
}

void    parse( int qty, char **arg, long *nbs ) {
    for ( size_t i = 0; arg[i]; i++) {
        if ( arg[i][0] == '-' )
            throw ( std::invalid_argument("PmergeMe only accepts positive numbers") );
        for ( size_t j = 0; arg[i][j]; j++) {
            if ( arg[i][j] == '.' || arg[i][j] == ',' ) 
                throw ( std::invalid_argument("PmergeMe only accepts whole numbers") );
            if ( !isdigit( arg[i][j] ) )
                throw ( std::invalid_argument("PmergeMe only accepts numbers") );
        }
        std::cout << arg[i] << std::endl;
        nbs[i] = atol( arg[i] );
        if ( nbs[i] > INT_MAX )
            throw ( std::invalid_argument("PmergeMe does not accept numbers higher than INT_MAX") );
    }
    if ( isSorted( nbs, qty ) )
        throw ( std::invalid_argument("The input is already sorted") );  
}