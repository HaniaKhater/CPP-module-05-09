/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:32:36 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 11:39:12 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <climits>
#include <sys/time.h>
#include <typeinfo>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int     isSorted( long nbs[], const int qty );
void    Parse( const int qty, char **arg, long *nbs );

void    MergeInsertVector( std::vector<std::pair<unsigned int, unsigned int> > &container, const bool &odd, const unsigned int &tmp );
void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp );

#endif