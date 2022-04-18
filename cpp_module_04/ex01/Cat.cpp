/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:30:15 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:20:26 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	_brain = new Brain("dog");
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat(const Cat& cat)
	:Animal()
{
	*this = cat;
}


Cat& Cat::operator=(const Cat& cat)
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
