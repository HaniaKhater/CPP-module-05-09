/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 02:47:06 by hania             #+#    #+#             */
/*   Updated: 2023/04/24 02:47:07 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <stdexcept>

class Base {
    public:
        virtual ~Base();
};

Base*   generate( void );
void    identify( Base *p );
void    identify( Base &p );

#endif