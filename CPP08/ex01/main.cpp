/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:32:44 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 08:06:23 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
    } catch ( std::out_of_range &e ) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    Span multiple = Span(10000);
    std::vector<int> nums(10000);
    std::srand( std::time(NULL) );
    std::generate( nums.begin(), nums.end(), std::rand );
    try {
        multiple.addNumbers( nums.begin(), nums.end() );
    } catch ( std::out_of_range &e ) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Shortest span: " << multiple.shortestSpan() << std::endl;
        std::cout << "Longest span: " << multiple.longestSpan() << std::endl;
    } catch ( std::logic_error &e ) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}