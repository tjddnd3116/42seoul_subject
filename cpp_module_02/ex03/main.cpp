/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:12:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 22:52:17 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include "Fixed.h"
#include <iostream>

int		main( void ) {
	Point a( Fixed(1), Fixed(2));
	Point b( Fixed(-3), Fixed(0.5f));
	Point c( Fixed(1.0f), Fixed(-1.5f));

	for (float y = 2.0f ; y > -2.0f; y-=0.1 )
	{
		for(float x = -3.0f;x < 2; x+=0.1)
		{
			Point p( (Fixed(x)), Fixed(y));
			if ((x >= 0.0 &&  x <= 0.1)|| (y >= 0.0 && y <= 0.1) )
				std::cout << "+ ";
			else
			{
				if (bsp(a, b, c, p))
				std::cout << "- ";
				else
				std::cout << "@ ";
			}
		}
		std::cout << std::endl;
	}
}
