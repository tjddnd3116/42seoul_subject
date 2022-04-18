/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:20 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:03:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << _type << " created" << std::endl;
}

Animal::Animal(Animal& animal)
{
	*this = animal;
}

Animal& Animal::operator=(const Animal & animal)
{
	_type = animal.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout <<"animal deleted" << std::endl;
}

void Animal::makeSound( void ) const
{
	std::cout << "  " << std::endl;
}

std::string Animal::getType( void ) const
{
	return (_type);
}

void Animal::setType( std::string type )
{
	_type = type;
}

