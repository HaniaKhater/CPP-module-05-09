/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:53:04 by hania             #+#    #+#             */
/*   Updated: 2023/04/26 04:32:31 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>
#include <cmath>

#define MAX_VAL 750

int test(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main(int ac, char **av)
{
    test(ac, av);
    std::cout << std::endl;
    
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
    for ( size_t i = 0; i < a.size(); ++i )
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "b: ";
    for ( size_t i = 0; i < b.size(); ++i )
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "c: ";
    for ( size_t i = 0; i < c.size(); ++i )
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "s: ";
    for ( size_t i = 0; i < s.size(); ++i )
        std::cout << s[i] << " ";
    std::cout << std::endl;

    try {
        s[3] = 'X';
    }
    catch (const Array<char>::InvalidIndexException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}   