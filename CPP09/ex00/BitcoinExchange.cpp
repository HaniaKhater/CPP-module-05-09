/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:20:42 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 13:52:46 by hania            ###   ########.fr       */
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

bool    ValidFormat( std::string line ) {
    size_t  pipe = line.find("|");
    if (( line[pipe + 1] != ' ' || line[pipe - 1] != ' ') 
    || ( line.substr(4,1) != "-" && line.substr(7,1) != "-" ))
        return false;
    return true;
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

bool    ValidAmount( float btc, std::string qty ) {
    int decimal = 0;
    int neg = 0;

    for ( size_t j = 0; qty[j] == '-'; j++ ) {
        neg++;
    }
    if ( neg % 2 == 1 )
        return false;
    for ( size_t i = 0; i < qty.length(); i++ ) {
        if ( qty[i] == '.' )
            decimal++;
        if ( (!(isdigit(qty[i]) || qty[i] == '-' ) && qty[i] != '.' && (decimal == 1 || decimal == 0)) || decimal > 1 )
            return false;
    }
    if ( btc < 0 || btc > 1000 || neg % 2 == 1 )
        return false;
    return true;
}

void    Convert( char *file, std::map<std::string, float>& database ) {
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
            if ( line != "date | value" && !input.eof() )
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
            std::cerr << "Invalid Date   => " << line << std::endl;
            continue;
        }
        std::string         amount = line.substr(13);
        std::stringstream   qty;
        float               bitcoins = 0.00;
        
        if ( !ValidAmount( bitcoins, amount ) ) {
            std::cerr << "Invalid Amount => " << line << std::endl;
            continue;
        }
        for ( size_t i = 0; amount.at(0) == '-'; i++)
            amount = amount.substr(1);
        qty << amount;
        qty >> bitcoins;        std::string date = AssembleDate( year, month, day );
        PrintResults( date, bitcoins, database );
    }
}

std::string     AssembleDate( int year, int month, int day ) {
    std::stringstream   y, m, d;
    std::string         date;

    y << year;
    m << std::setw(2) << std::setfill('0') << month;
    d << std::setw(2) << std::setfill('0') << day;
    date = y.str() + "-" + m.str() + "-" + d.str();
    return date;
}

std::map<std::string, float>::iterator  FindPreviousDate( std::map<std::string, float>& database, std::string unfound ) {
    std::map<std::string, float>::iterator itb = database.begin();
    std::map<std::string, float>::iterator ite = database.end();
    std::string         tmp;
    std::stringstream   a, t;
    int                 actual, next;
    
    tmp = unfound.erase(4,1).erase(6,1);
    a << unfound;
    a >> actual;

    for ( ; itb != ite; itb++ ) {
        tmp = itb->first;
        t.clear();
        t << tmp;
        t >> next;
        if ( next > actual ) {
            return ( itb );
        }
    }
    return ite;
}

void    PrintResults( std::string date, float bitcoins, std::map<std::string, float>& database)
{
    std::map<std::string, float>::iterator itb = database.begin();
    std::map<std::string, float>::iterator ite = database.end();
    bool    exact = false;

    for ( ; itb != ite; itb++ ) {
        if (itb->first == date) {
            exact = true;
            break;
        }
    }
    if ( exact == true ) {
        std::cout << date << " => " << bitcoins << " = " <<  std::fixed << std::setprecision(2) << bitcoins * itb->second << std::endl;
        exact = false;
    }
    else {
        ite = FindPreviousDate( database, date );
        ite--;
        std::cout << date << " => " << static_cast<float>(bitcoins) << " = " << std::fixed << std::setprecision(2) << "\033[1;33m" << bitcoins * ite->second << "\033[0m" << std::endl;
    }
}