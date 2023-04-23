/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:18:10 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 08:49:01 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern &ref) {
    *this = ref;
}

Intern::~Intern() {}

Intern&     Intern::operator=( const Intern &rhs ) {
    (void)rhs;
    return *this;
}

const char*	Intern::NoTargetException::what(void) const throw()
{
	return "The intern doesn't know what form to make, try specifying it.";
}

const char*	Intern::FormNotRecognizedException::what(void) const throw()
{
	return "The intern can't recognize the form name. Try capitalizing it correctly like Shrubbery Creation";
}

int	Intern::getFormNbr( std::string form )
{
	std::string	form_name[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	for ( int i = 0; i < 3; i++ )
	{
		if ( form == form_name[i] )
			return (i);
	}
	return (-1);
}

AForm*  Intern::makeForm( std::string form, std::string target ) {
    AForm   *formPtr = NULL;
    int     formNbr = getFormNbr(form);

    try {
        if ( target == "" )
            throw ( NoTargetException() );
        switch( formNbr )
        {
            case 0:
                formPtr = new ShrubberyCreationForm(target);
                break ;
            case 1:
                formPtr = new RobotomyRequestForm(target);
                break;
            case 2:
                formPtr = new PresidentialPardonForm(target);
                break;
            default:
                formPtr = NULL;
                throw ( FormNotRecognizedException() );
        }
    }
    catch( const std::exception& e)
    {
        std::cerr << "Intern couldn't create the form because " << e.what() << std::endl;
    }
    return (formPtr);
}