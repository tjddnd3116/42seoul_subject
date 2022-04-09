/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:00:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 22:21:52 by soum             ###   ########.fr       */
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

Fixed Point::getB(Point& point)
{
	// double  A = x1 - x0;
	return (point._x - _x);
}

Fixed Point::getA(Point& point)
{
	// double	B = -(y1 - y0);
	// 				y0 - y1
	return (_y - point._y);
}

Fixed Point::getC(Point& point)
{
	// double	C = -B * x0 - A * y0;
	//				(y1 - y0) * x0 -(x1 - x0) * y0
	return (((point._y - _y) * _x.toFloat()) - ((point._x - _x) * _y.toFloat()));
}

Fixed Point::get_x()
{
	return (_x);
}

Fixed Point::get_y()
{
	return (_y);
}
