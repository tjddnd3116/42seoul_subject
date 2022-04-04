/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:57:44 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 01:02:15 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <cstddef>

HumanB::HumanB()
{}

HumanB::HumanB(std::string name)
{
	this->name = name;
	weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with his ";
	if (weapon == nullptr)
		std::cout << "hand" << std::endl;
	else
		std::cout << weapon->getType() << std::endl;
}
