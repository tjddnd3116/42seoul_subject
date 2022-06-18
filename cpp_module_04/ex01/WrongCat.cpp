/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:56:12 by soum              #+#    #+#             */
/*   Updated: 2022/06/18 21:03:05 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal()
{
	_brain = new Brain;
	setType("WrongCat");
	std::cout << "\033[31m" << getType() << " created" << "\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
	:WrongAnimal()
{
	_brain = new Brain("god");
	*this = wrongcat;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongcat)
{
	_brain = wrongcat._brain;
	this->setType(wrongcat.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	delete _brain;
	std::cout << "\033[31m" << "wrongAnimal" << " deleted" << "\033[0m" << std::endl;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "\033[31m" << "W...W" << "\033[0m" << std::endl;
}

WrongCat::WrongCat( std::string idea )
	:WrongAnimal()
{
	_brain = new Brain(idea);
	setType("WrongCat");
	std::cout << "\033[31m" << getType() << " created" << "\033[0m" << std::endl;
}

void WrongCat::makeThink( void ) const
{
	_brain->brainSound();
}
