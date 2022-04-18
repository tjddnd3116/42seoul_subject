/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:30:14 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:20:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	_brain = new Brain("cat");
	setType("Dog");
	std::cout << getType() << " created" << std::endl;
}

Dog::Dog(const Dog& dog)
	:Animal()
{
	*this = dog;
}

Dog& Dog::operator=(const Dog &dog)
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
