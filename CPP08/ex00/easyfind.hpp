/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:54 by hania             #+#    #+#             */
/*   Updated: 2023/04/26 06:26:09 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind( T& container, int value ) {
    typename T::iterator it = std::find( container.begin(), container.end(), value );
    if ( it == container.end() )
        throw std::exception();
    return it;
}

#endif