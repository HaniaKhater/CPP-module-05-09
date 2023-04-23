/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:15 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 06:56:44 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP


#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:
        std::string     _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm( const PresidentialPardonForm &ref );
        PresidentialPardonForm( std::string target );
        ~PresidentialPardonForm();
        PresidentialPardonForm&      operator=( const PresidentialPardonForm &rhs );
        std::string     getTarget() const;
        virtual void    execute(Bureaucrat const & executor ) const;
};

std::ostream &   operator<<(std::ostream &out, const PresidentialPardonForm &in );

#endif