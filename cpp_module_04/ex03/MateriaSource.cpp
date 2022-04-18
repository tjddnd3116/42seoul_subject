/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:41:30 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 03:16:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materia_slot[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource& materiasource )
{
	*this = materiasource;
}

MateriaSource& MateriaSource::operator=( MateriaSource &materiasource)
{
	AMateria* tmp_amateria;
	int this_idx = 0;

	for (int i = 0; i < 4; i++)
	{
		if (materiasource.getMateriaSlot(i) != NULL)
		{
			tmp_amateria = materiasource.getMateriaSlot(i)->clone();
			delete materiasource.getMateriaSlot(i);
			materiasource.setNullMateriaSlot(i);
			_materia_slot[this_idx] = tmp_amateria;
			this_idx++;
		}
	}
	for (; this_idx < 4; this_idx++)
		_materia_slot[this_idx] = NULL;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia_slot[i] != NULL)
			delete _materia_slot[i];
	}
}

AMateria* MateriaSource::getMateriaSlot(int idx) const
{
	return ((AMateria*)_materia_slot[idx]);
}

void MateriaSource::setNullMateriaSlot(int idx)
{
	_materia_slot[idx] = NULL;
}



void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if(_materia_slot[i] == NULL)
		{
			_materia_slot[i] = materia;
			// _materia_slot[i] = materia->clone();
			// delete materia;
			std::cout << "Materia Source learn "
				<< _materia_slot[i]->getType() << " materia" << std::endl;
			return ;
		}
	}
	std::cout << "Materia Source is full so " << materia->getType() \
		<< " is delete" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (_materia_slot[i] && _materia_slot[i]->getType() == type)
		{
			return (_materia_slot[i]->clone());
		}
	}
	std::cout << "Materia Source did't learn " << type << " materia" << std::endl;
	return (0);
}
