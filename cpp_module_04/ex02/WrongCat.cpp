/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:56:12 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:19:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal()
{
	_brain = new Brain("god");
	setType("WrongCat");
	std::cout << "\033[31m" << getType() << " created" << "\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
	:WrongAnimal()
{
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
	std::cout << "\033[31m" << getType() << " deleted" << "\033[0m" << std::endl;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "\033[31m" << "W...W" << "\033[0m" << std::endl;
}
