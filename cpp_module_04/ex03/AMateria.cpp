/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:37:52 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 00:28:47 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( std::string const& type )
{
	_type = type;
}

AMateria::AMateria( const AMateria& amateria )
{
	*this = amateria;
}

AMateria& AMateria::operator=(const AMateria &amateria)
{
	this->_type = amateria.getType();
	return (*this);
}

AMateria::~AMateria()
{}

std::string const & AMateria::getType() const
{
	return (_type);
}

// void AMateria::use(ICharacter& target)
// {
//
// }
