/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:18:12 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 08:41:38 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    private:
        
    public:
        Intern();
        Intern( const Intern &ref );
        ~Intern();
        Intern  &operator=( const Intern &rhs);
        int     getFormNbr( std::string form );
        AForm*  makeForm( std::string form, std::string target );
        class	NoTargetException: public std::exception
	    {
	        public:
	        	virtual const char*	what(void) const throw();
	    };
	    class	FormNotRecognizedException: public std::exception
	    {
	        public:
	        	virtual const char*	what(void) const throw();
	    };
};

#endif