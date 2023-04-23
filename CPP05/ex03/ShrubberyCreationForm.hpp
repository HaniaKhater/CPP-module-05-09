/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:23 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 05:58:04 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    private:
        std::string     _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( const ShrubberyCreationForm &ref );
        ShrubberyCreationForm( std::string target );
        ~ShrubberyCreationForm();
        ShrubberyCreationForm&      operator=( const ShrubberyCreationForm &rhs );
        std::string     getTarget() const;
        virtual void    execute(Bureaucrat const & executor ) const;
};

std::ostream &   operator<<(std::ostream &out, const ShrubberyCreationForm &in );

#endif