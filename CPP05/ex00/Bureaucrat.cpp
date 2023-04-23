/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:47 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 02:54:38 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Dan"), _grade(8) {
    std::cout << "Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &ref ) : _name(ref._name), _grade(ref._grade) {
    std::cout << "Copy constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name){
    std::cout << "Constructor has been called" << std::endl;
    if ( grade < 1 )
        throw GradeTooHighException();
    else if ( grade > 150 )
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::~Bureaucrat( void ) {
    std::cout << "Destructor has been called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &rhs ) {
    std::cout << "Assign operator has been called" << std::endl;
    _grade = rhs._grade;
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too low");
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::_tryGrade() const {
	if (this->_grade < 1) 
        throw GradeTooHighException();
	else if (this->_grade > 150)	
        throw GradeTooLowException();
	return;
}

void    Bureaucrat::promote(){
    if ( this->_grade > 1 && this->_grade < 151 ) {
        this->_grade--;
        std::cout << this->_name << " has been promoted" << std::endl;
    }
    this->_tryGrade();
    }

void    Bureaucrat::demote(){
    if ( this->_grade > 0 && this->_grade < 150 ) {
        this->_grade++;
        std::cout << this->_name << " has been demoted" << std::endl;
    }
    this->_tryGrade();
}

std::ostream & operator << (std::ostream & out, const Bureaucrat &in){
	out << in.getName() << ", with grade of " << in.getGrade() << std::endl;
	return out;
}