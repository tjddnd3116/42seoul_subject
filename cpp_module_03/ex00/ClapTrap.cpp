#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "no name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap "<< _name << " created" << std::endl;
}

ClapTrap::ClapTrap( std::string name )
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap "<< _name << " created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& clapTrap )
{
	_name = clapTrap._name + "_copy";
	_attackDamage = clapTrap._attackDamage;
	_energyPoints = clapTrap._energyPoints;
	_hitPoints = clapTrap._hitPoints;
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

unsigned int ClapTrap::getAttackDamage( void ) const
{
	if (_energyPoints && _hitPoints)
		return (_attackDamage);
	else
		return (0);
}
