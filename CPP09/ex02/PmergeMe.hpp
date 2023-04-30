/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:32:36 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 03:06:50 by hania            ###   ########.fr       */
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

int isSorted( long nbs[], int qty );
void    Parse( int qty, char **arg, long *nbs );

void    MergeInsertVector( std::vector<std::pair<unsigned int, unsigned int> > &container, bool odd, unsigned int tmp );
void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, bool odd, unsigned int tmp );

#endif