/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 07:14:32 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  // Create a ShrubberryCreationForm
  ShrubberyCreationForm shrub("home");

   // Create a RobotomyRequestForm
  RobotomyRequestForm robot("Robot");

   // Create a PresidentialPardonForm
  PresidentialPardonForm pardon("Pardon");

   // Create a Bureaucrat
  Bureaucrat Mark("Mark", 1);

   // Try to sign the ShrubberryCreationForm
  try {
    shrub.beSigned(Mark);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

   // Try to execute the ShrubberryCreationForm
  try {
    shrub.execute(Mark);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

   // Try to sign the RobotomyRequestForm
  try {
    robot.beSigned(Mark);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

   // Try to execute the RobotomyRequestForm
  try {
    robot.execute(Mark);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

   // Try to sign the PresidentialPardonForm
  try {
    pardon.beSigned(Mark);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

   // Try to execute the PresidentialPardonForm
  try {
    pardon.execute(Mark);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

   return 0;
} 