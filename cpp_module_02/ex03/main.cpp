/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:12:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/15 15:16:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include "Fixed.h"
#include <iostream>

int		main( void ) {

	std::string cmd;
	Point a( Fixed(1), Fixed(2));
	Point b( Fixed(-3), Fixed(0.5f));
	Point c( Fixed(1.0f), Fixed(-1.5f));
	Point point( Fixed(2), Fixed(3));

	if (bsp(a, b, c, point))
		std::cout << "point is inside the triangle" << std::endl;
	else
		std::cout << "point is a vertex or on edge or outside triangle" << std::endl;;

	std::cout << "show the plot? [Y][N]" << std::endl;
	std::cin >> cmd;
	if (cmd == "Y")
	{
		for (float y = 4.0f ; y > -4.0f; y -= 0.1 )
		{
			for(float x = -4.0f; x < 4.0f; x += 0.1)
			{
				Point p( (Fixed(x)), Fixed(y));
				if ((x >= point.get_x().toFloat() &&  x <= point.get_x().toFloat() + 0.1) && (y >= point.get_y().toFloat() && y <= point.get_y().toFloat() + 0.1) )
					std::cout << "\e[0;31m""00""\e[0m";
				else if ((x >= 0.0 && x <= 0.1) || (y >= 0.0 && y <= 0.1))
					std::cout << "@@";
				else
				{
					if (bsp(a, b, c, p))
						std::cout << "\033[35m""@@""\e[0m";
					else
						std::cout << "\033[30m""@@""\e[0m";
				}
			}
			std::cout << std::endl;
		}
	}
	else
		return (0);
	return (0);
}
