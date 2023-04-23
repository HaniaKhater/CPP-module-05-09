/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:15:08 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 03:28:21 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
        const int           _gradeExec;
    public:
        AForm();
        AForm( const AForm &ref );
        AForm(std::string, int toSign, int toExec);
        virtual ~AForm();
        AForm&       operator=( const AForm &rhs );
        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getStatus() const;
        std::string sendStatus() const;
        void        beSigned( const Bureaucrat &bu );
        void        beExecuted( const Bureaucrat &bu ) const;
        virtual void    execute( const Bureaucrat & executor ) const = 0;
        class	IsAlreadySignedException: public std::exception {
	        public:
	    	    virtual const char*	what(void) const throw();
	    };
	    class	IsNotSignedException: public std::exception {
	        public:
	    	    virtual const char*	what(void) const throw();
	    };
};

std::ostream & operator << (std::ostream & out, const AForm &in);

#endif
