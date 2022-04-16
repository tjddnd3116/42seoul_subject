/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:14:04 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << "ScavTrap "<< getName() << " created" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap( std::string name )
	: ClapTrap(name)
{
	std::cout << "ScavTrap "<< getName() << " created" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap( const ScavTrap& scavTrap )
	:ClapTrap(scavTrap.getName())
{
	this->setName(scavTrap.getName() + "_copy");
	this->setAttackDamage(scavTrap.getAttackDamage());
	this->setEnergyPoints(scavTrap.getEnergyPoints());
	this->setHitPoints(scavTrap.getHitPoints());
}

ScavTrap& ScavTrap::operator=( ScavTrap &scavTrap )
{
	setName(scavTrap.getName());
	setHitPoints(scavTrap.getHitPoints());
	setEnergyPoints(scavTrap.getEnergyPoints());
	setAttackDamage(scavTrap.getAttackDamage());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " deleted" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() && getHitPoints())
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() \
			<< " attacks " << target << ", causing " \
			<< getAttackDamage() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << getName() \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();
}

void ScavTrap::guardGate( void )
{
	if (getEnergyPoints() && getHitPoints())
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() \
			<< "is now in Gate keeper mode" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << getName() \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();
}

void ScavTrap::showStatus( void )
{
	std::cout << "\033[32m" << "|" << std::setw(15) << "name" \
		<< "|" << std::setw(15) << "hit points" \
		<< "|" << std::setw(15) << "energy points" \
		<< "|" << std::setw(15) << "attack damage" << std::endl;
	std::cout << "|" << std::setw(15) << getName() \
		<< "|" << std::setw(15) << getHitPoints() \
		<< "|" << std::setw(15) << getEnergyPoints() \
		<< "|" << std::setw(15) << getAttackDamage() \
		<< "\033[0m" << std::endl;
}
