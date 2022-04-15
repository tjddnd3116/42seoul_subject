/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:57:15 by soum              #+#    #+#             */
/*   Updated: 2022/04/15 12:47:55 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap( void )
	: FragTrap(), ScavTrap()
{
	FragTrap::setName("no name_clap_name");
	ScavTrap::setName("no name_clap_name");
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
}

DiamondTrap::DiamondTrap( std::string name )
	:ClapTrap(name + "_clap_name"),FragTrap(name + "_clap_name"), ScavTrap(name+ "_clap_name")
{
	this->setName(name);
	_name = name;
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << FragTrap::getName() << " deleted" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << ScavTrap::getName() << " " <<FragTrap::getName() << std::endl;
	std::cout << _name << std::endl;;
}

void DiamondTrap::showStatus( void )
{
	std::cout << "\033[36m" << "|" << std::setw(15) << "name" \
		<< "|" << std::setw(15) << "hit points" \
		<< "|" << std::setw(15) << "energy points" \
		<< "|" << std::setw(15) << "attack damage" << std::endl;
	std::cout << "|" << std::setw(15) << FragTrap::getName() \
		<< "|" << std::setw(15) << FragTrap::getHitPoints() \
		<< "|" << std::setw(15) << ScavTrap::getEnergyPoints() \
		<< "|" << std::setw(15) << FragTrap::getAttackDamage() \
		<< "\033[0m" << std::endl;
}
