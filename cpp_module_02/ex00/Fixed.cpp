/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:02:11 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 21:22:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNum = 0;
}

Fixed::Fixed(Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointNum = fixed.getRawBits();
}

Fixed& Fixed::operator=(Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointNum = fixed.getRawBits();
	return (fixed);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNum);
}
