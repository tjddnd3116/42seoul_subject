/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:57:15 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:09:51 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
	: ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = getName();
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap "<< _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name )
	: ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap("_clap_name")
{
	this->_name = name;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap "<< _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& diamondTrap )
	:ClapTrap(diamondTrap._name + "_clap_name"), FragTrap(diamondTrap._name + "_clap_name"), ScavTrap(diamondTrap._name + "_clap_name")
{
	this->_name = diamondTrap._name;
	setAttackDamage(diamondTrap.getAttackDamage());
	setEnergyPoints(diamondTrap.getEnergyPoints());
	setHitPoints(diamondTrap.getHitPoints());
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap &diamondTrap )
{
	_name = diamondTrap._name;
	setName(diamondTrap.getName());
	setHitPoints(diamondTrap.getHitPoints());
	setEnergyPoints(diamondTrap.getEnergyPoints());
	setAttackDamage(diamondTrap.getAttackDamage());
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " deleted" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "WHO AM I ?!?!?!!" << std::endl;
	if (getEnergyPoints() && getHitPoints())
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "You're " << getName() << " AND " << _name << "!!!" << std::endl;
	}
	else {
		std::cout << "DiamondTrap " << _name \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
}
