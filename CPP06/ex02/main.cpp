/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 02:47:13 by hania             #+#    #+#             */
/*   Updated: 2023/04/24 02:55:45 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Base.hpp"

int main( int argc, char **argv )
{
    (void)argv;
    if ( argc != 1 ) {
        std::cerr << "Error: Too many arguments" << std::endl;
        return (1);
    }
    for ( int i = 0; i < 10; i++ ) {
        Base *base = generate();
        identify( base );
        identify( *base );
        std::cout << std::endl;
        delete base;
        sleep(2);
    }
    return 0;
}