/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:20:47 by hania             #+#    #+#             */
/*   Updated: 2023/04/28 07:23:06 by hania            ###   ########.fr       */
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
#include <iomanip>

void            RecordRates( std::map<std::string, float>& database );
bool            ValidFormat( std::string line );
bool            ValidDate( int year, int month, int day );
bool            ValidAmount( float amount );
void            Convert( char *file, std::map<std::string, float>& database );
void            PrintResults( std::string date, float bitcoins, std::map<std::string, float>& database);
std::string     AssembleDate( int year, int month, int day );

#endif