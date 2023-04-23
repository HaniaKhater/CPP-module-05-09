/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 02:29:32 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

int main() {
  // Create a valid Form
  Form form("ID Renewal", 1, 15);

  // Check if the form is signed.
  std::cout << "Is the form signed? " << form.sendStatus() << std::endl;

  // // Try to sign the form with a bureaucrat with a low grade.
  // Bureaucrat bureaucrat("John Doe", 15);
  // try {
  //   form.beSigned(bureaucrat);
  // } catch (Form::GradeTooLowException& e) {
  //   std::cout << e.what() << std::endl;
  // }

  // // Try to sign the form with a bureaucrat with a high grade.
  // bureaucrat.setGrade(1);
  // form.beSigned(bureaucrat);
  // std::cout << "Is the form signed? " << form.isSigned() << std::endl;

  return 0;
}