/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:02:11 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 19:56:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	_fixedPointNum = 0 << _bits;
}

Fixed::Fixed(const int num)
{
	_fixedPointNum = num <<_bits;
}

Fixed::Fixed(const float num)
{
	_fixedPointNum = (int)roundf(num * (1 << _bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	_fixedPointNum = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{}

int Fixed::getRawBits() const
{
	return (_fixedPointNum);
}

float Fixed::toFloat() const
{
	float result;

	result = float(_fixedPointNum / (float)(1 << 8));
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

bool Fixed::operator>(const Fixed& fixed)
{
	if (this->getRawBits() > fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed& fixed)
{
	if (this->getRawBits() < fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& fixed)
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& fixed)
{
	if (this->getRawBits() <= fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& fixed)
{
	if (this->getRawBits() == fixed.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& fixed)
{
	if (this->getRawBits() != fixed.getRawBits())
		return (true);
	else
		return (false);
}

float Fixed::operator+(const Fixed& fixed)
{
	float tmp;

	tmp = this->toFloat() + fixed.toFloat();
	// return (this->_fixedPointNum + fixed.getRawBits());
	return (tmp);
}

float Fixed::operator-(const Fixed& fixed)
{
	float tmp;

	tmp = this->toFloat() - fixed.toFloat();
	// return (this->_fixedPointNum + fixed.getRawBits());
	return (tmp);
}

float Fixed::operator*(const Fixed& fixed)
{
	float tmp;

	tmp = this->toFloat() * fixed.toFloat();
	// return (this->_fixedPointNum + fixed.getRawBits());
	return (tmp);
}

float Fixed::operator/(const Fixed& fixed)
{
	float tmp;

	tmp = this->toFloat() / fixed.toFloat();
	// return (this->_fixedPointNum + fixed.getRawBits());
	return (tmp);
}

Fixed& Fixed::operator++()
{
	this->_fixedPointNum++;
	return (*this);
}

Fixed& Fixed::operator++(int)
{
	Fixed *tmp;

	tmp = new Fixed(*this);
	++(*this);
	return (*tmp);
}

Fixed& Fixed::operator--()
{
	this->_fixedPointNum--;
	return (*this);
}

Fixed& Fixed::operator--(int)
{
	Fixed *tmp;

	tmp = new Fixed(*this);
	--(*this);
	return (*tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return *(new Fixed(a));
	else
		return *(new Fixed(b));
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return *(new Fixed(a));
	else
		return *(new Fixed(b));
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return *(new Fixed(a));
	else
		return *(new Fixed(b));
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return *(new Fixed(a));
	else
		return *(new Fixed(b));
}
