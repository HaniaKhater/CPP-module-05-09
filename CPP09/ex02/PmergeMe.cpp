/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:32:11 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 11:33:53 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int isSorted( long nbs[], const int qty ) {
    if (qty == 1 || qty == 0) 
        return 1;
    return nbs[qty - 1] >= nbs[qty - 2]
           && isSorted( nbs, qty - 1);
}

void    Parse( const int qty, char **arg, long *nbs ) {
    for ( size_t i = 0; arg[i]; i++) {
        if ( arg[i][0] == '-' )
            throw ( std::invalid_argument("PmergeMe only accepts positive numbers") );
        for ( size_t j = 0; arg[i][j]; j++) {
            if ( arg[i][j] == '.' || arg[i][j] == ',' ) 
                throw ( std::invalid_argument("PmergeMe only accepts whole numbers") );
            if ( !isdigit( arg[i][j] ) )
                throw ( std::invalid_argument("PmergeMe only accepts numbers") );
        }
        nbs[i] = atol( arg[i] );
        if ( nbs[i] > INT_MAX )
            throw ( std::invalid_argument("PmergeMe does not accept numbers higher than INT_MAX") );
    }
    if ( isSorted( nbs, qty ) )
        throw ( std::invalid_argument("The input is already sorted") );  
}

void    MergeInsertVector( std::vector<std::pair<unsigned int, unsigned int> > &container, const bool &odd, const unsigned int &tmp )
{
    std::vector<unsigned int>   low, high;
    struct timeval  start, end;
    long            sec, micro, timeTaken;

    gettimeofday( &start, NULL );
    for ( size_t i = 0; i < container.size(); i++ ) {
        if ( container[i].first > container[i].second )
            std::swap( container[i].first, container[i].second );
    }

    for ( size_t i = 0; i < container.size(); i++ )
        low.push_back( container[i].first );
    for ( size_t i = 0; i < container.size(); i++ )
        high.push_back( container[i].second );
    
    std::sort( high.begin(), high.end() );
    for ( size_t i = 0; i < low.size(); i++ )
        high.insert( std::lower_bound( high.begin(), high.end(), low[i]), low[i] );

    if ( odd )
        high.insert( std::lower_bound( high.begin(), high.end(), tmp), tmp );

    std::cout << "After  : ";
    if ( high.size() < 6 ) {
        for ( size_t i = 0; i < high.size(); i++ )
            std::cout << high[i] << " ";
    } else {
        for ( int i = 1; i < 6; i++ )
            std::cout << high[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;

    gettimeofday( &end, NULL );
    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    timeTaken = ( sec / 1000000 ) + ( micro );
    std::cout << "Time to process a range of " << high.size() << " elements with std::vector : " << GREEN << timeTaken << " microseconds" << RESET << std::endl;
}

void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp ) {
    std::deque<unsigned int>   low, high;
    struct timeval  start, end;
    long            sec, micro, timeTaken;

    gettimeofday( &start, NULL );
    for ( size_t i = 0; i < container.size(); i++ ) {
        if ( container[i].first > container[i].second )
            std::swap( container[i].first, container[i].second );
    }

    for ( size_t i = 0; i < container.size(); i++ )
        low.push_back( container[i].first );
    for ( size_t i = 0; i < container.size(); i++ )
        high.push_back( container[i].second );
    
    std::sort( high.begin(), high.end() );
    for ( size_t i = 0; i < low.size(); i++ )
        high.insert( std::lower_bound( high.begin(), high.end(), low[i]), low[i] );

    if ( odd )
        high.insert( std::lower_bound( high.begin(), high.end(), tmp), tmp );

    std::cout << "After  : ";
    if ( high.size() < 6 ) {
        for ( size_t i = 0; i < high.size(); i++ )
            std::cout << high[i] << " ";
    } else {
        for ( int i = 1; i < 6; i++ )
            std::cout << high[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;

    gettimeofday( &end, NULL );
    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    timeTaken = ( sec / 1000000 ) + ( micro );
    std::cout << "Time to process a range of " << high.size() << " elements with std::deque : " << GREEN << timeTaken << " microseconds" << RESET << std::endl;
}