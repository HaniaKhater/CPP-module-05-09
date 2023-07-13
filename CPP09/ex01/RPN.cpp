/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:22:28 by hania             #+#    #+#             */
/*   Updated: 2023/07/13 22:50:42 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>

bool    isOperator( const char token ) {
    return ( token == '+' || token == '-' || token == '*' || token == '/' );
}

void    performRNP( const std::string input) {
    std::stack<int> nbStack;
	
    for (size_t i = 0; i < input.length(); i++) {
		if ( isdigit(input[i]) )
            nbStack.push( input[i] - '0' );
		else if ( isOperator(input.at(i)) && nbStack.size() > 1 ) {
			int top1 = nbStack.top();
			nbStack.pop();
			int top2 = nbStack.top();
			nbStack.pop();
			int result = calculator( input.at(i), top2, top1 );
			nbStack.push(result);
		}
		else if (isspace(input[i]))
			continue;
		else
			throw std::invalid_argument("Invalid Input");
	}
	if ( nbStack.size() != 1 ) {
		throw std::invalid_argument("Number of operators and operators are invalid");
    }
	std::cout << nbStack.top() << std::endl;
}

int     calculator( const char token, const int a, const int b ) {
    if ( token == '+' )
        return ( a + b );
    else if ( token == '-' )
        return ( a - b );
    else if ( token == '*' )
        return ( a * b );
    else if ( token == '/' ) {
        if ( b == 0 )
            throw ( std::invalid_argument("Invalid division: Cannot divide by zero") );
        return ( a / b );
    }
    throw ( std::invalid_argument("Invalid operator") );
}
