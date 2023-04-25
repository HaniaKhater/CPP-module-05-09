/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:53:04 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 10:32:37 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    Array<> a( 3 );
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    Array<int> b( a );
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    Array<int> c;
    c = a;
    c[0] = 7.02;
    c[1] = 8.8;
    c[2] = 9;

    Array<char> s( 3 );
    s[0] = 'H';
    s[1] = 'i';
    s[2] = '!';
    
    std::cout << "a: ";
    for ( size_t i = 0; i < a.getSize(); ++i )
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "b: ";
    for ( size_t i = 0; i < b.getSize(); ++i )
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "c: ";
    for ( size_t i = 0; i < c.getSize(); ++i )
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "s: ";
    for ( size_t i = 0; i < s.getSize(); ++i )
        std::cout << s[i] << " ";
    std::cout << std::endl;

    try {
        s[3] = 'X'; // this index is out of bounds and should throw an exception
    }
    catch (const Array<char>::InvalidIndexException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}   