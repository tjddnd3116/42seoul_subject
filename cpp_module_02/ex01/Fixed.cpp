/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:02:11 by soum              #+#    #+#             */
/*   Updated: 2022/04/09 12:37:45 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNum = 0 << _bits;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNum = num <<_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNum = (int)roundf(num * (1 << _bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointNum = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (_fixedPointNum);
}

void Fixed::setRawBits(const int raw)
{
	_fixedPointNum = raw << _bits;
}

float Fixed::toFloat() const
{
	float result;

	result = float(_fixedPointNum / (float)(1 << _bits));
	return (result);
}

int Fixed::toInt() const
{
	int result;

	result = _fixedPointNum >> _bits;
	return (result);
}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed)
{
	os << (float(fixed.getRawBits()) / (float)(1 << 8));
	return (os);
}
