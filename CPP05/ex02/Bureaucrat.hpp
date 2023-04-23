/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:49 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 04:15:47 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class AForm;

class Bureaucrat {
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat( void );
        Bureaucrat( const Bureaucrat &ref );
        Bureaucrat( std::string name, int grade );
        Bureaucrat& operator =( const Bureaucrat &rhs );
        ~Bureaucrat();
        std::string getName() const;
        int         getGrade() const;
        void        _tryGrade(void) const;
        void        promote();
        void        demote();
        void        signForm( AForm &form );
        
        class GradeTooHighException : public std::exception{
            public:
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char * what() const throw();
        };
};

std::ostream & operator<<( std::ostream & out, const Bureaucrat &in );

#endif