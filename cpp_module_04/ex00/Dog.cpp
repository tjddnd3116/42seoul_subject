/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:04 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 00:16:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	setType("Dog");
	std::cout << getType() << " created" << std::endl;
}

Dog::Dog( const Dog& dog )
	:Animal()
{
	*this = dog;
}

Dog& Dog::operator=( const Dog &dog )
{
	this->setType(dog.getType());
	return (*this);
}

Dog::~Dog()
{
	std::cout << getType() << " deleted" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Arf! Arf!" << std::endl;
}
