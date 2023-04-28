/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:24:00 by hania             #+#    #+#             */
/*   Updated: 2023/04/28 05:56:41 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int     main( int ac, char **av ) {
    (void)av;
    if ( ac != 2 ) {
        std::cerr << "Error: the btc program requires a file as an argument" << std::endl;
        return 0;
    }
    std::map<std::string, float>    database;
    try {
        RecordRates( database );
        Convert( av[1], database );
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    }
}