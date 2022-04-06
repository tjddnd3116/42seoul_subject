/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:57:44 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 13:47:42 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <cstddef>

HumanB::HumanB()
{}

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with his ";
	if (_weapon == nullptr)
		std::cout << "hand" << std::endl;
	else
		std::cout << _weapon->getType() << std::endl;
}
