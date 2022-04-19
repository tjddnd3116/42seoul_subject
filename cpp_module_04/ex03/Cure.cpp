/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:13:55 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:47:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure")
{}

Cure::Cure( const Cure& cure )
	:AMateria("cure")
{
	*this = cure;
}

Cure& Cure::operator=(const Cure &cure)
{
	_type = cure.getType();
	return (*this);
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
	Cure* cur_clone = new Cure;

	return (cur_clone);
}

void Cure::use(ICharacter& target)
{
	std::string name;

	name = target.getName();
	std::cout << "* heals " << name << "'s wounds *" << std::endl;
}
