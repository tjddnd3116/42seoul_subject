/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:21:19 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:47:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	:AMateria("ice")
{}

Ice::Ice( const Ice& ice )
	:AMateria("ice")
{
	*this = ice;
}

Ice& Ice::operator=(const Ice &ice)
{
	_type = ice.getType();
	return (*this);
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
	Ice* ice_clone = new Ice;

	return (ice_clone);
}

void Ice::use(ICharacter& target)
{
	std::string name;

	name = target.getName();
	std::cout << "* shoots an ice bolt at " << name << " *" << std::endl;
}
