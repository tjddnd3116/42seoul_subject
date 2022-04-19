/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:01 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 00:14:40 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat( const Cat& cat )
	:Animal()
{
	*this = cat;
}


Cat& Cat::operator=( const Cat& cat )
{
	this->setType(cat.getType());
	return (*this);
}

Cat::~Cat()
{
	std::cout << getType() << " deleted" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}
