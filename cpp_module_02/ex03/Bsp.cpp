/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:09:33 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 22:35:54 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

bool checkPoint( Point& a, Point& b, Point& c, Point &p)
{
	Fixed A = a.getA(b);
	Fixed B = a.getB(b);
	Fixed C = a.getC(b);

	if (((A * p.get_x()) + (B * p.get_y()) + C.toFloat()) * ((A * c.get_x()) + (B * c.get_y()) + C.toFloat()) > 0)
		return (true);
	return (false);

}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point _a = a;
	Point _b = b;
	Point _c = c;
	Point _p = point;

	if (checkPoint(_a, _b, _c, _p) && checkPoint(_a, _c, _b, _p) && checkPoint(_b, _c, _a, _p))
		return (true);
	return (false);
}







