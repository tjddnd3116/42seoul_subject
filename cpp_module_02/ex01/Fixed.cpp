/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:02:11 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 22:21:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNum = num;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;

	_fixedPointNum = num;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	// _fixedPointNum = fixed.getRawBits();
}

const Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

float Fixed::toFloat() const
{
	float result;

	result = this->_fixedPointNum;
	return (result);
}

int Fixed::toInt() const
{
	int result;

	result = this->_fixedPointNum;
	return (result);
}

std::ostream& Fixed::operator<<(std::ostream &os)
{
	os << this->_fixedPointNum;
	return (os);
}
