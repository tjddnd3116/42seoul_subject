/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:14:43 by soum              #+#    #+#             */
/*   Updated: 2022/04/26 14:03:48 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base* generate( void )
{
	int *rnd_addr;
	std::string rnd_addr_str;

	rnd_addr_str = std::to_string((unsigned int)(long)(&rnd_addr) *\
			(unsigned int)(long)(&rnd_addr));
	if (rnd_addr_str.at(4) % 3 == 0)
		return (dynamic_cast<Base*>(new A));
	else if (rnd_addr_str.at(4) % 3 == 1)
		return (dynamic_cast<Base*>(new B));
	else
		return (dynamic_cast<Base*>(new C));
}

void identify( Base* p )
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A" << std::endl;
	if (b)
		std::cout << "B" << std::endl;
	if (c)
		std::cout << "C" << std::endl;
}

void identify( Base& p )
{
	try {
	A a = dynamic_cast<A&>(p);
	std::cout << "A" << std::endl;
	} catch (std::exception& e) {}
	try {
	B b = dynamic_cast<B&>(p);
	std::cout << "B" << std::endl;
	} catch (std::exception& e) {}
	try {
	C c = dynamic_cast<C&>(p);
	std::cout << "C" << std::endl;
	} catch (std::exception& e) {}
}
