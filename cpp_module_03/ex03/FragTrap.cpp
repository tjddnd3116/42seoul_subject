/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:37:02 by soum              #+#    #+#             */
/*   Updated: 2022/04/14 22:02:36 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << "FragTrap "<< getName() << " created" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap( std::string name )
	: ClapTrap(name)
{
	std::cout << "FragTrap "<< getName() << " created" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " deleted" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (getEnergyPoints() && getHitPoints())
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << getName() \
			<< " attacks " << target << ", causing " \
			<< getAttackDamage() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << getName() \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();
}

void FragTrap::highFivesGuys( void )
{
	if (getEnergyPoints() && getHitPoints())
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << getName() \
			<< " : Look out, everybody, things are about to get awesome!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << getName() \
			<< " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();

}

void FragTrap::showStatus( void )
{
	std::cout << "\033[36m" << "|" << std::setw(15) << "name" \
		<< "|" << std::setw(15) << "hit points" \
		<< "|" << std::setw(15) << "energy points" \
		<< "|" << std::setw(15) << "attack damage" << std::endl;
	std::cout << "|" << std::setw(15) << getName() \
		<< "|" << std::setw(15) << getHitPoints() \
		<< "|" << std::setw(15) << getEnergyPoints() \
		<< "|" << std::setw(15) << getAttackDamage() \
		<< "\033[0m" << std::endl;
}
