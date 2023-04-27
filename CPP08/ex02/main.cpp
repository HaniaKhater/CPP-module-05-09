/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:13:51 by hania             #+#    #+#             */
/*   Updated: 2023/04/27 05:09:42 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    std::cout << "-------- Testing MutantStack ----------" << std::endl;
    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    if (mstack.empty())
        std::cout << "MutantStack is empty" << std::endl;
    else
        std::cout << "MutantStack is not empty" << std::endl;
    std::cout << "MutantStack size is " << mstack.size() << std::endl << std::endl;

    std::cout << "------------ Testing List -------------" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    //[...]
    l.push_back(0);
    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    if (l.empty())
        std::cout << "List is empty" << std::endl;
    else
        std::cout << "List is not empty" << std::endl;
    std::cout << "List size is " << l.size() << std::endl << std::endl;


    std::cout << "----------- Testing Vector ------------" << std::endl;
    std::vector<int> v;
    v.push_back(5);
    v.push_back(17);
    std::cout << v.back() << std::endl;
    v.pop_back();
    std::cout << v.size() << std::endl;
    v.push_back(3);
    v.push_back(5);
    v.push_back(737);
    //[...]
    v.push_back(0);
    std::vector<int>::iterator vit = v.begin();
    std::vector<int>::iterator vite = v.end();
    ++vit;
    --vit;
    while (vit != vite)
    {
        std::cout << *vit << std::endl;
        ++vit;
    }
    if (v.empty())
        std::cout << "Vector is empty" << std::endl;
    else
        std::cout << "Vector is not empty" << std::endl;
    std::cout << "Vector size is " << v.size() << std::endl << std::endl;

    return 0;
}