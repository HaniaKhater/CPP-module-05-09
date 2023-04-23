/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:12 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 06:59:16 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5)
    , _target("unknown") {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &ref)
    : AForm(ref)
    , _target(ref._target)
{
    *this = ref;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
    : AForm("PresidentialPardonForm", 25, 5)
    , _target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&  PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs.getTarget();
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const {
    return (this->_target);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor ) const {
    beExecuted(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream & operator << (std::ostream & out, const PresidentialPardonForm &in) {
  return out << "Form Name:                 " << in.getName() << std::endl
	    << "Grade Required To Sign:    " << in.getGradeSign() << std::endl
	    << "Grade Required to Execute: " << in.getGradeExec() << std::endl
	    << "Signature Status:          " << in.sendStatus() << std::endl
        << "Target:                    " << in.getTarget() << std::endl;
}