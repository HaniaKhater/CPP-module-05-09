/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:21 by hania             #+#    #+#             */
/*   Updated: 2023/04/23 07:13:37 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137)
    , _target("unknown") {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &ref)
    : AForm(ref)
    , _target(ref._target)
{
    *this = ref;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
    : AForm("ShrubberyCreationForm", 145, 137)
    , _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs.getTarget();
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const {
    return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	beExecuted(executor);
    std::string     file;
    std::ofstream   fd;

    file = getTarget() + "_shrubbery";
    fd.open(file.c_str(), std::ios::out);
    if (fd.fail())
	{
		std::cout << "Error: file did not open" << std::endl
			<< "Something went wrong while creating " << file << std::endl;
		return ;
	}
    std::cout << "Drawing an ASCII tree in " << file << std::endl;
    fd << std::endl << std::endl << "                      ,/{_{/'//}/}/}" << std::endl;
    fd << "                   {/{//}{/{//}(/}{//} " << std::endl;
    fd << "                 ,{/{//}{/{//}(_)/}{/{//}  " << std::endl;
    fd << "               {/{/(/}/}{/{//}/}{/){//}/}/}" << std::endl;
    fd << "             ,{/{/(_)/}{/{/)/}{/(_){/}/}/}/}" << std::endl;
    fd << "             _{/{/{/{/{/{/(_)/}/}/}{/,/}/}/}" << std::endl;
    fd << "            {/{/{/{H{/,/}{/{//}/}{/}(_){//}/}" << std::endl;
    fd << "            _{/{/{/{/(_)/}/}{/{/{//}/},/}{//}" << std::endl;
    fd << "           {/{/{/{/(/}{/{/{/{//})/}{/(_)/}/}/}" << std::endl;
    fd << "            {/{//}(_){/{/{//}/}(_){//}{//}/})/}" << std::endl;
    fd << "            '{/{/{//}{/{/{/{//}/}{/{//}/}/}(_)," << std::endl;
    fd << "            {/{/{//}{/){/{/{//}/}{K{/(/}/}/}/}" << std::endl;
    fd << "             {/{/{//}(_){/{/{/(/}/}{/(_)/}/}/}" << std::endl;
    fd << "               {/({/{/{/{/{//}(_){//}/}/}/}(/}" << std::endl;
    fd << "                (_){/{//}{/{//}/}{/{/)/}/}()" << std::endl;
    fd << "                  {/{/{/{//}{/{/{/{/(_)/}/'" << std::endl;
    fd << "                   {/{/{/{//}/}{'/{//}/}" << std::endl;
    fd << "                    '){/'{//}{/ /}{/}/}" << std::endl;
    fd << "                         |.-'.-/" << std::endl;
    fd << "                __...--- |'-.-'| --...__" << std::endl;
    fd << "         _...--    .-    |'-.-'|  ' -.  ""--..__" << std::endl;
    fd << "       -''    ' .  .     |.'-._|    . :        ." << std::endl;
    fd << "       .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
    fd << "                ' ..     |'-_.-|" << std::endl;
    fd << "        .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
    fd << "                    .'   |'- .-|   '." << std::endl;
    fd << "        ..-'   ' .  '.   `-._.-'   .'  '  - ." << std::endl;
    fd << "         .-' '        '-._______.-'     '  ." << std::endl;
    fd << "              .      ~,/|             ,  '  . " << std::endl;
    fd << "          .       .   / | .    ' '-." << std::endl;
    fd << "         ____________/  |_____________" << std::endl;
    fd << "        |                             |" << std::endl;
    fd << "        |         Here you go!        |" << std::endl;
    fd << "        |     A Shrubberry Tree!      |" << std::endl;
    fd << "        |_____________________________|" << std::endl << std::endl << std::endl;
    std::cout << file << " has successfully been created!" <<std::endl;
    fd.close();
}

std::ostream & operator << (std::ostream & out, const ShrubberyCreationForm &in) {
  return out << "Form Name:                 " << in.getName() << std::endl
	    << "Grade Required To Sign:    " << in.getGradeSign() << std::endl
	    << "Grade Required to Execute: " << in.getGradeExec() << std::endl
	    << "Signature Status:          " << in.sendStatus() << std::endl
        << "Target:                    " << in.getTarget() << std::endl;
}