/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:12:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 19:54:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

int		main( void ) {

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 )) ;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
