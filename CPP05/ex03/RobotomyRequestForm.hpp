/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:19 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 06:42:09 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
        std::string     _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( const RobotomyRequestForm &ref );
        RobotomyRequestForm( std::string target );
        ~RobotomyRequestForm();
        RobotomyRequestForm&      operator=( const RobotomyRequestForm &rhs );
        std::string     getTarget() const;
        virtual void    execute(Bureaucrat const & executor ) const;
};

std::ostream &   operator<<(std::ostream &out, const RobotomyRequestForm &in );

#endif