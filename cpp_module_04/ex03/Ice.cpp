/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:21:19 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 22:19:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	:AMateria("ice")
{}

AMateria* Ice::clone() const
{
	Ice* ice_clone = new Ice;
	return (ice_clone);
}

void Ice::use(ICharacter& target)
{
	std::string name;

	name = ((Character*)(&target))->getName();
	std::cout << "* shoots an ice bolt at " << name << " *" << std::endl;
}
