/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:55:13 by soum              #+#    #+#             */
/*   Updated: 2022/10/17 20:59:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "------------------------------" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "------------------------------" << std::endl;

	float e = 42.42f;
	float f = 24.24f;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << "------------------------------" << std::endl;

	double aa = 42.424242;
	double bb = 24.242424;
	::swap(aa, bb);
	std::cout << "aa = " << aa << ", bb = " << bb << std::endl;
	std::cout << "min( aa, bb ) = " << ::min( aa, bb ) << std::endl;
	std::cout << "max( aa, bb ) = " << ::max( aa, bb ) << std::endl;
	std::cout << "------------------------------" << std::endl;

	char cc = 'c';
	char dd = 'd';
	::swap(cc, dd);
	std::cout << "cc = " << cc << ", dd = " << dd << std::endl;
	std::cout << "min( cc, dd ) = " << ::min( cc, dd ) << std::endl;
	std::cout << "max( cc, dd ) = " << ::max( cc, dd ) << std::endl;
	std::cout << "------------------------------" << std::endl;

	return 0;
}
