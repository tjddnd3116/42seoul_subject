/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:27:57 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 01:44:28 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string name )
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_materia_slot[i] = NULL;
}

Character::Character( Character& character )
{
	*this = character;
}

Character& Character::operator=( Character & character )
{
	AMateria* tmp_amateria;

	_name = character.getName();
	int this_idx = 0;

	for (int i = 0; i < 4; i++)
	{
		if (character.getMateriaSlot(i) != NULL)
		{
			tmp_amateria = character.getMateriaSlot(i)->clone();
			delete character.getMateriaSlot(i);
			character.setNullMateriaSlot(i);
			_materia_slot[this_idx] = tmp_amateria;
			this_idx++;
		}
	}
	for (; this_idx < 4; this_idx++)
		_materia_slot[this_idx] = NULL;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia_slot[i] != NULL)
			delete _materia_slot[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

AMateria* Character::getMateriaSlot( int idx ) const
{
	return ((AMateria*)_materia_slot[idx]);
}

void Character::setNullMateriaSlot( int idx )
{
	_materia_slot[idx] = NULL;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "there are no materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_materia_slot[i] == NULL)
		{
			_materia_slot[i] = m;
			std::cout << getName() << " get " << m->getType() \
				<< " materia!" << std::endl;
			// m = NULL;
			return ;
		}
	}
	std::cout << getName() << " can't equip this materia!" \
		<< "your slot is full" << std::endl;
}

// fix this!!!
// ------------------------------------------------------------------
void Character::unequip(int idx)
{
	if (_materia_slot[idx] == NULL)
	{
		std::cout << getName() << " have no materia your [" << idx << "]slot" << std::endl;
		return ;
	}
	std::cout << getName() << " left on the floor " << _materia_slot[idx]->getType() \
		<< " materia";
	_materia_slot[idx] = NULL;
}
// ------------------------------------------------------------------

void Character::use(int idx, ICharacter &target)
{
	if (_materia_slot[idx] == NULL)
	{
		std::cout << getName() << " have no materia your [" << idx << "]slot" << std::endl;
		return ;
	}
	_materia_slot[idx]->use(target);
}
