/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/10 22:41:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

ScavTrap::ScavTrap( std::string name )
	: ClapTrap(name)
{
	std::cout << "ScavTrap "<< name << " created" << std::endl;
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << ClapTrap::getName() << " deleted" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (ClapTrap::getEnergyPoints() && ClapTrap::getHitPoints())
	{
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << "ScavTrap " << ClapTrap::getName() \
			<< " attacks " << target << ", causing " \
			<< ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << ClapTrap::getName() \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << ClapTrap::getName() \
		<< "is now in Gate keeper mode" << std::endl;
}

void ScavTrap::showStatus( void )
{
	std::cout << "\033[32m" << "|" << std::setw(15) << "name" \
		<< "|" << std::setw(15) << "hit points" \
		<< "|" << std::setw(15) << "energy points" \
		<< "|" << std::setw(15) << "attack damage" << std::endl;
	std::cout << "|" << std::setw(15) << ClapTrap::getName() \
		<< "|" << std::setw(15) << ClapTrap::getHitPoints() \
		<< "|" << std::setw(15) << ClapTrap::getEnergyPoints() \
		<< "|" << std::setw(15) << ClapTrap::getAttackDamage() \
		<< "\033[0m" << std::endl;
}
