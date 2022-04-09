/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:00:47 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 21:32:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {

	private:
		Fixed _x;
		Fixed _y;

	public:
		Point();
		Point( const Fixed& x, const Fixed& y );
		Point( const Point& point);
		Point& operator=( const Point& point);
		~Point();
		Fixed getA(Point& point);
		Fixed getB(Point& point);
		Fixed getC(Point& point);
		Fixed get_x( void );
		Fixed get_y( void );
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
