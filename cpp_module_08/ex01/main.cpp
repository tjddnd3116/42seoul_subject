/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:43:57 by soum              #+#    #+#             */
/*   Updated: 2022/04/25 15:47:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define MAX_VAL 10000
int main(void)
{
	Span test(MAX_VAL);
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
		test.addNumber(std::rand());
	// test.addNumber(-2147483648);
	// test.addNumber(2147483647);
	// test.addNumber(0);

	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.LongSpan() << std::endl;


	// Span test1 = test;
	// std::cout << test1.shortestSpan() << std::endl;
	// std::cout << test1.LongSpan() << std::endl;
    //
    //
	// Span test3(MAX_VAL);
	// test3 = test;
	// std::cout << test3.shortestSpan() << std::endl;
	// std::cout << test3.LongSpan() << std::endl;
	// //
	// Span test4(10);
	// test4.addManyNumbers();
	// std::cout << test4.shortestSpan() << std::endl;
	// std::cout << test4.LongSpan() << std::endl;

	return (0);
}
