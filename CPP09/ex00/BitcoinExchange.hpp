/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:20:47 by hania             #+#    #+#             */
/*   Updated: 2023/04/28 05:52:59 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdlib.h>

void    RecordRates( std::map<std::string, float>& database );
bool    ValidDate( int year, int month, int day );
bool    ValidFormat( std::string line );
bool    ValidAmount( float amount );
void    Convert( char *file, std::map<std::string, float>& database );

#endif