/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:37:02 by soum              #+#    #+#             */
/*   Updated: 2022/04/10 22:48:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name )
	: ClapTrap(name)
{
	std::cout << "FragTrap "<< name << " created" << std::endl;
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << ClapTrap::getName() << " deleted" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (ClapTrap::getEnergyPoints() && ClapTrap::getHitPoints())
	{
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << "FragTrap " << ClapTrap::getName() \
			<< " attacks " << target << ", causing " \
			<< ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << ClapTrap::getName() \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();
}

void FragTrap::highFivesGuys( void )
{
	std::cout << ClapTrap::getName() \
		<< " : Look out, everybody, things are about to get awesome!" << std::endl;
}

void FragTrap::showStatus( void )
{
	std::cout << "\033[36m" << "|" << std::setw(15) << "name" \
		<< "|" << std::setw(15) << "hit points" \
		<< "|" << std::setw(15) << "energy points" \
		<< "|" << std::setw(15) << "attack damage" << std::endl;
	std::cout << "|" << std::setw(15) << ClapTrap::getName() \
		<< "|" << std::setw(15) << ClapTrap::getHitPoints() \
		<< "|" << std::setw(15) << ClapTrap::getEnergyPoints() \
		<< "|" << std::setw(15) << ClapTrap::getAttackDamage() \
		<< "\033[0m" << std::endl;
}
