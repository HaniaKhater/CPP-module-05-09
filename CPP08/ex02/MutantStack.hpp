/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:14:00 by hania             #+#    #+#             */
/*   Updated: 2023/04/27 03:20:50 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack &cpy);
        MutantStack & operator=(const MutantStack &cpy);
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
        ~MutantStack();
};

#include "MutantStack.tpp"

#endif