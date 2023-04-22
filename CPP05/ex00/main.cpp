/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 01:10:31 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include <stdexcept>

int main() {
    // Create a bureaucrat with a valid grade
    Bureaucrat yael("Yael", 1);
    std::cout << yael << std::endl;  
    
    // Try to create a bureaucrat with an invalid grade
    try {
      Bureaucrat mark("Mark", 151);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }   
    
    // Try to increment yael's grade
    try {
      yael.promote();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }   
    
    // Decrement yael's grade
    yael.demote();
    std::cout << yael << std::endl;  
    
    // Test Copy constructor
    Bureaucrat copy(yael);
    std::cout << copy << std::endl;
    return 0;
}