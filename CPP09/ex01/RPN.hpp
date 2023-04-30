/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:22:30 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 08:23:20 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <string>
#include <stack>

bool        isOperator( const char token );
void        performRNP( const std::string input );
int         calculator( const char token, const int a, const int b );

#endif