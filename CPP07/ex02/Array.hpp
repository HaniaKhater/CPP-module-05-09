/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:53:02 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 10:37:06 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template < typename T = int >
class Array {
    public:
        Array();
        explicit Array(unsigned int n);
        Array(const Array<T>& ref);
        ~Array();
        Array<T>&       operator=(const Array<T>& rhs);
        class InvalidIndexException : public std::exception {
            public:
                virtual const char  *what(void) const throw();
        };
        T&              operator[](unsigned int i);
        const T&        operator[](unsigned int i) const;
        size_t          size() const;
    
    private:
        T* _data;
        size_t _size;
};

#include "Array.tpp"

#endif