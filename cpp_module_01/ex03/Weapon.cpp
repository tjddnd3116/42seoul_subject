/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:51:02 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 13:37:16 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	_type = type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType()
{
	return (_type);
}
