/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:15:08 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 02:51:10 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
        const int           _gradeExec;
    public:
        Form();
        Form( const Form &ref );
        Form(std::string, int toSign, int toExec);
        ~Form();
        Form&       operator=( const Form &rhs );
        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getStatus() const;
        std::string sendStatus() const;
        void        beSigned( const Bureaucrat &bu );
};

std::ostream & operator << (std::ostream & out, const Form &in);

#endif
