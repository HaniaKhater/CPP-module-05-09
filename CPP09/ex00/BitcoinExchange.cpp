/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:20:42 by hania             #+#    #+#             */
/*   Updated: 2023/04/28 05:51:27 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    RecordRates( std::map<std::string, float>& database ) {
    std::ifstream   input;
    std::string     line;
    std::string     date;
    float           rate;

    input.open( "./data.csv" );
    while ( !input.eof() )
    {
        input >> line;
        date = line.substr( 0, 10 ).erase( 4, 1 ).erase( 6, 1 );
        rate = 0.0;
        std::stringstream converter;
        converter << line.substr(11);
        converter >> rate;
        database.insert( std::make_pair( date, rate ) );
    }
    input.close();
}

bool    ValidDate( int year, int month, int day ) {
    int     limits[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ( day < 1 || month < 1 || month > 12 || year < 2009 )
        return false;
    if ( month == 2 && !((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) )
        if ( day > 28 )
            return false;
    if ( day > limits[month + 1] )
        return false;
    return true; 
}

bool    ValidFormat( std::string line ) {
    size_t  pipe = line.find("|");
    if (( line[pipe + 1] != ' ' || line[pipe - 1] != ' ') 
    || ( line.substr(4,1) != "-" && line.substr(7,1) != "-" ))
        return false;
    return true;
}

bool    ValidAmount( float amount ) {
    if ( amount >= 0 && amount <= 1000)
        return true;
    return false;
}

void    Convert( char *file, std::map<std::string, float>& database ) {
    (void)database;
    std::ifstream   input;
    std::string     line;

    input.open( file );
    if ( input.fail() ) {
        std::cerr << "Error: Could not open file." << std::endl;
        input.close();
        exit(0);
    }
    while ( !input.eof() ) {
        std::getline( input, line );
        if ( line.length() < 14 || !ValidFormat( line ))  {
            std::cerr << "Invalid Format => " << line << std::endl;
            continue;
        }
        int                 year, month, day = 0;
        std::stringstream   y, m, d;
        y << line.substr( 0, 4 );
        m << line.substr( 5, 2 );
        d << line.substr( 8, 2 );
        y >> year;
        m >> month;
        d >> day;
        if ( !ValidDate( year, month, day ) ) {
            std::cerr << "Invalid Date => " << line << std::endl;
            continue;
        }
        std::string         amount = line.substr(13);
        std::stringstream   qty;
        float               bitcoins = 0.00;
        qty << amount;
        qty >> bitcoins;
        if ( !ValidAmount(bitcoins) ) {
            std::cerr << "Invalid amount => " << line << std::endl;
            continue;
        }
        std::cout << "Amount: " << amount << std::endl;
    }
}
