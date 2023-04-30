/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 02:47:01 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 09:07:55 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <math.h>

Base::~Base() {
}

Base*	generate( void ) {
	Base	*res;

	srand( time( NULL ) );
	int typeNb = rand() % 3;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "------------  " << "\033[1;33mGenerate a Random Instance\033[0m" << "  ------------" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

	switch( typeNb )
	{
		case 0:
			res = new A();
			std::cout << "\033[1;31mA\033[0m" << " is instanciated" << std::endl;
			break ;
		case 1:
			res = new B();
			std::cout << "\033[1;31mB\033[0m" << " is instanciated" << std::endl;
			break ;
		case 2:
			res = new C();
			std::cout << "\033[1;31mC\033[0m" << " is instanciated" << std::endl;
	}
	return res;
}

void	identify( Base *p ) {
    std::cout << "-------------- " << "\033[1;33mIndetify Through Pointer\033[0m" << " --------------" << std::endl;

	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p is " << "\033[1;31mA\033[0m" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p is " << "\033[1;31mB\033[0m" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p is " << "\033[1;31mC\033[0m" << std::endl;
}

void	identify( Base &p ) {
	Base	base;
    std::cout << "---------------- " << "\033[1;33mIndetify Through Base\033[0m" << " ---------------" << std::endl;
	
    try {
		base = dynamic_cast<A&>(p);
		std::cout << "The actual type of the object pointed to by p is " << "\033[1;31mA\033[0m" << std::endl;
	}
	catch ( std::exception& e ) {
		std::cerr << "A is a " << e.what() << std::endl;
	}
	try {
		base = dynamic_cast<B&>(p);
		std::cout << "The actual type of the object pointed to by p is " << "\033[1;31mB\033[0m" << std::endl;
    }
    catch ( std::exception& e ) {
		std::cerr << "B is a " << e.what() << std::endl;
	}
	try {
		base = dynamic_cast<C&>(p);
		std::cout << "The actual type of the object pointed to by p is " << "\033[1;31mC\033[0m" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "C is a " << e.what() << std::endl;
	}
}
