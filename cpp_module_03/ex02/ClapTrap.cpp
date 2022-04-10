/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:45:02 by soum              #+#    #+#             */
/*   Updated: 2022/04/11 00:04:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

ClapTrap::ClapTrap( std::string name )
{
	std::cout << "ClapTrap "<< name << " created" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( ClapTrap& clapTrap )
{
	*this = clapTrap;
}

ClapTrap& ClapTrap::operator=( ClapTrap &clapTrap )
{
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_energyPoints = clapTrap._energyPoints;
	_attackDamage = clapTrap._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " deleted" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if(_energyPoints && _hitPoints)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
			<< _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " has no _energyPoints or dead" \
			<< std::endl;
	}
	showStatus();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints)
	{
		if (long(_hitPoints) - long(amount) < 0)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount  \
			<< " damage";
		if (!_hitPoints)
			std::cout << ", ClapTrap " << _name << " is dead";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " already dead" << std::endl;
	}
	showStatus();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energyPoints && _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " Reparied " << amount << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " has no energy points or dead" \
			<< std::endl;
	}
	showStatus();
}

unsigned int ClapTrap::getAttackDamage( void )
{
	if (_energyPoints && _hitPoints)
		return (_attackDamage);
	else
		return (0);
}



void ClapTrap::showStatus( void )
{
	std::cout << "\033[31m" << "|" << std::setw(15) << "name" \
		<< "|" << std::setw(15) << "hit points" \
		<< "|" << std::setw(15) << "energy points" \
		<< "|" << std::setw(15) << "attack damage" << std::endl;
	std::cout << "|" << std::setw(15) << _name \
		<< "|" << std::setw(15) << _hitPoints \
		<< "|" << std::setw(15) << _energyPoints \
		<< "|" << std::setw(15) << _attackDamage << "\033[0m" << std::endl;
}

void ClapTrap::setHitPoints(unsigned int amount)
{
	_hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
	_energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
}

std::string ClapTrap::getName( void )
{
	return (_name);
}

void ClapTrap::setName( std::string name )
{
	_name = name;
}

unsigned int ClapTrap::getHitPoints( void )
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints( void )
{
	return (_energyPoints);
}
