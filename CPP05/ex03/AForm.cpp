/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:15:06 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 06:33:01 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string name, int toSign, int toExec) 
    : _name(name)
    , _isSigned(false)
    , _gradeSign(toSign)
    , _gradeExec(toExec)
{
    if (toSign > 150 || toExec > 150)
        throw(Bureaucrat::GradeTooLowException());
    else if (toSign < 1 || toExec < 1)
        throw(Bureaucrat::GradeTooHighException());
}

AForm::AForm() 
    : _name("28C")
    , _isSigned(false)
    , _gradeSign(70)
    , _gradeExec(25) {
}

AForm::AForm( const AForm &ref ) 
    : _name(ref._name)
    , _isSigned(ref._isSigned)
    , _gradeSign(ref._gradeSign)
    , _gradeExec(ref._gradeExec) {
}

AForm::~AForm() {
}

AForm&   AForm::operator=(const AForm &rhs ) {
    _isSigned = rhs._isSigned;
    return *this;
}

std::string AForm::getName() const {
    return _name;
}

int     AForm::getGradeSign() const {
    return _gradeSign;
}

int     AForm::getGradeExec() const {
    return _gradeExec;
}

bool    AForm::getStatus() const {
    return _isSigned;
}

std::string    AForm::sendStatus() const {
    if (_isSigned)
        return "Signed";
    return "Not Signed";
}

void    AForm::beSigned( const Bureaucrat &bu ) {
    if (getStatus())
		throw (AForm::IsAlreadySignedException());
    if ( bu.getGrade() <= _gradeSign )
        _isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

void    AForm::beExecuted( const Bureaucrat &bu ) const {
    if (getStatus() == false)
		throw (AForm::IsNotSignedException());
    if ( bu.getGrade() > _gradeExec )
        throw (Bureaucrat::GradeTooLowException());
}

const char*	AForm::IsAlreadySignedException::what(void) const throw() {
	return ("The form is already signed");
}

const char*	AForm::IsNotSignedException::what(void) const throw() {
	return ("The form is not signed yet");
}

std::ostream & operator << (std::ostream & out, const AForm &in) {
  return out << "Form Name:                 " << in.getName() << std::endl
	    << "Grade Required To Sign:    " << in.getGradeSign() << std::endl
	    << "Grade Required to Execute: " << in.getGradeExec() << std::endl
	    << "Signature Status:          " << in.sendStatus() << std::endl;
}