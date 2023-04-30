/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:32:39 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 08:14:39 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span( const Span& ref )
    : _N(ref._N)
    , _nbs(ref._nbs) {}

Span::Span( unsigned int N ) 
    : _N(N) {}

Span::~Span() {}

Span    &Span::operator=( const Span& rhs ) {
    _N = rhs._N;
    _nbs = rhs._nbs;
    return *this;
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (std::distance(begin, end) > static_cast<int>(_N - _nbs.size()))
        throw std::out_of_range("There isn't enough space in Span to add all the numbers");
    _nbs.insert(_nbs.end(), begin, end);
}

void Span::addNumber(int n) {
    if (_nbs.size() == _N )
        throw std::out_of_range("Span is full, you can't add more numbers");
    _nbs.push_back(n);
}

unsigned int Span::longestSpan() const {
    if (_nbs.size() < 2)
        throw std::logic_error("There aren't enough numbers in Span to find the longest span. Try to add more");

    int min = *std::min_element(_nbs.begin(), _nbs.end());
    int max = *std::max_element(_nbs.begin(), _nbs.end());

    return std::abs(max - min);
}

unsigned int Span::shortestSpan() const {
    if (_nbs.size() < 2)
        throw std::logic_error("There aren't enough numbers in Span to find the shortest span. Try to add more");

    unsigned int tmp = std::abs(_nbs[0] - _nbs[1]);
    for (std::vector<int>::size_type i = 0; i < _nbs.size(); ++i)
    {
        for (std::vector<int>::size_type j = i + 1; j < _nbs.size(); ++j)
        {
            unsigned int diff = std::abs(_nbs[i] - _nbs[j]);
            if (diff < tmp)
                tmp = diff;
        }
    }
    return tmp;
}