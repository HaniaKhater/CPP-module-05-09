/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:17 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 06:54:26 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45)
    , _target("unknown") {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &ref)
    : AForm(ref)
    , _target(ref._target)
{
    *this = ref;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
    : AForm("RobotomyRequestForm", 72, 45)
    , _target(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&  RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs.getTarget();
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const {
    return (this->_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor ) const {\
    beExecuted(executor);
    std::cout << "**Vrrrr Vrrrrrrrrrrrrr... and more accurate drilling noises **" << std::endl;
    srand(time(NULL));
    int success = rand() % 2;
    if (success)
        std::cout << this->_target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomization has failed\n";
}

std::ostream & operator << (std::ostream & out, const RobotomyRequestForm &in) {
  return out << "Form Name:                 " << in.getName() << std::endl
	    << "Grade Required To Sign:    " << in.getGradeSign() << std::endl
	    << "Grade Required to Execute: " << in.getGradeExec() << std::endl
	    << "Signature Status:          " << in.sendStatus() << std::endl
        << "Target:                    " << in.getTarget() << std::endl;
}