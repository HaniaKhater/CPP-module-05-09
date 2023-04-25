/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:35:57 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 08:35:58 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>
#include <iostream>

template< typename T, typename U >
void	print(U &index, T &arg) { 
    std::cout << index << " --> " << arg << std::endl; 
}

template< typename T, typename U >
void    iter( T *array, U size, void ( *f )( U &, T & ) ) {
    for (U i = 0; i < size; i++) 
        f(i, array[i]);
    return;
}

#endif