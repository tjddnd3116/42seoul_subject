/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:10 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 00:20:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "\033[31m" << _type << " created" << "\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& wronganimal )
{
	*this = wronganimal;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &wronganimal )
{
	_type = wronganimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[31m" << "wronganimal deleted" << "\033[0m" << std::endl;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "\033[31m" << "#$%#$^^#^" << "\033[0m" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (_type);
}

void WrongAnimal::setType( std::string type )
{
	_type = type;
}

