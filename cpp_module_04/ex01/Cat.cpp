/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:30:15 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:11:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	_brain = new Brain;
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat(std::string idea)
	:Animal()
{
	_brain = new Brain(idea);
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat( const Cat& cat )
	:Animal()
{
	_brain = new Brain("dog");
	*this = cat;
}


Cat& Cat::operator=( const Cat& cat )
{
	(*this->_brain) = (*cat._brain);
	this->setType(cat.getType());
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << getType() << " deleted" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

void Cat::makeThink( void ) const
{
	_brain->brainSound();
}
