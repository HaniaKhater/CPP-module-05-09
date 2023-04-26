/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:32:35 by hania             #+#    #+#             */
/*   Updated: 2023/04/26 07:33:48 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>

class Span {
    private:
        unsigned int        _N;
        std::vector<int>    _nbs;

        Span();
    public:
        Span( const Span& ref );
        Span( unsigned int N );
        ~Span();
        Span    &operator=( const Span& rhs );

        void            addNumbers( std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
        void            addNumber( int n );
        unsigned int    longestSpan() const;
        unsigned int    shortestSpan() const;
};

#endif