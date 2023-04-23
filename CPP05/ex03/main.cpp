/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 09:20:36 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
  Intern myIntern;
  AForm* form;
  Bureaucrat Mark("Mark", 1);

  // Create a ShrubberyCreationForm
  form = myIntern.makeForm("Shrubbery Creation", "Home");
  if (form != NULL) {
    std::cout << "Intern created a ShrubberyCreationForm for My Home." << std::endl;
    // Try to sign and execute the ShrubberryCreationForm
    try {
      Mark.signForm(*form);
    } 
    catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      form->execute(Mark);
    }
    catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    delete form;
  }

  // Create a RobotomyRequestForm
  form = myIntern.makeForm("Robotomy Request", "The lab");
  if (form != NULL) {
    std::cout << "Intern created a RobotomyRequestForm for Fry." << std::endl;
    // Try to sign and execute the RobotomyRequestForm
    try {
      Mark.signForm(*form);
    } 
    catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      form->execute(Mark);
    }
    catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    delete form;
  }

  // Create a PresidentialPardonForm
  form = myIntern.makeForm("Presidential Pardon", "Mr Smith");
  if (form != NULL) {
    std::cout << "Intern created a PresidentialPardonForm." << std::endl;
    // Try to sign and execute the PresidentialPardonForm
    try {
      Mark.signForm(*form);
    } 
    catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      form->execute(Mark);
    }
    catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    delete form;
  }

  // Try to create a form with no target
  try {
    form = myIntern.makeForm("Robotomy Request", "");
  } catch (const Intern::NoTargetException& e) {
    std::cerr << e.what() << std::endl;
  }

  // Try to create a form with an invalid name
  try {
    form = myIntern.makeForm("Invalid form", "Home");
  } catch (const Intern::FormNotRecognizedException& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
} 