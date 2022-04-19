/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:30:14 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:12:20 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
	:Animal()
{
	_brain = new Brain;
	setType("Dog");
	std::cout << getType() << " created" << std::endl;
}

Dog::Dog(std::string idea)
	:Animal()
{
	_brain = new Brain(idea);
	setType("Dog");
	std::cout << getType() << " created" << std::endl;
}

Dog::Dog( const Dog& dog )
	:Animal()
{
	_brain = new Brain("Cat");
	*this = dog;
}

Dog& Dog::operator=( const Dog &dog )
{
	(*this->_brain) = (*dog._brain);
	this->setType(dog.getType());
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << getType() << " deleted" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Arf! Arf!" << std::endl;
}

void Dog::makeThink( void ) const
{
	_brain->brainSound();
}
