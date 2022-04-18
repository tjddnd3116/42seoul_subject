/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:13:55 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 22:20:54 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure")
{}

AMateria* Cure::clone() const
{
	Cure* cur_clone = new Cure;
	return (cur_clone);
}

void Cure::use(ICharacter& target)
{
	std::string name;


	name = ((Character*)(&target))->getName();
	std::cout << "* heals " << name << "'s wounds *" << std::endl;
}
