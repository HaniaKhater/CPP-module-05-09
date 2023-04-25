/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:43:54 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 07:43:55 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template< typename T >
void swap( T &x, T &y ) {
	T tmp = x;
	x = y;
	y = tmp;
}

template < typename T >
T   min( T x, T y ) {
    return ( x < y ? x : y );
}

template < typename T >
T   max( T x, T y ) {
    return ( x > y ? x : y );
}

#endif