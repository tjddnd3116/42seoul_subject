/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:00:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/09 15:26:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point()
{
	_x = 0.0f;
	_y = 0.0f;
}

Point::Point( const Fixed& x, const Fixed& y )
{
	_x = x;
	_y = y;
}

Point::Point( const Point& point )
{
	*this = point;
}

Point& Point::operator=(const Point &point)
{
	_x = point._x;
	_y = point._y;
	return (*this);
}

Point::~Point()
{}

Fixed Point::getA(Point& point) const
{
	return (_y - point._y);
}

Fixed Point::getB(Point& point) const
{
	return (point._x - _x);
}

Fixed Point::getC(Point& point) const
{
	return (((point._y - _y) * _x.toFloat()) - ((point._x - _x) * _y.toFloat()));
}

Fixed Point::get_x() const
{
	return (_x);
}

Fixed Point::get_y() const
{
	return (_y);
}
