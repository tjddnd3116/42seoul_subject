/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:43:57 by soum              #+#    #+#             */
/*   Updated: 2022/05/01 14:49:59 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define MAX_VAL 3
int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	// Span test = Span(MAX_VAL);
    //
	// std::srand(time(NULL));
	// test.addNumber(11111);
	// for (int i = 0; i < MAX_VAL; i++)
	//     test.addNumber(std::rand());
	// test.addNumber(1);
	// test.printArr();
	// std::cout << test.shortestSpan() << std::endl;
	// std::cout << test.longestSpan() << std::endl;
    //
	// Span *test2 = new Span(MAX_VAL);
    //
	// std::cout << test2->shortestSpan() << std::endl;
	// std::cout << test2->longestSpan() << std::endl;
	// *test2 = test;
	// test2->printArr();
	// std::cout << test2->shortestSpan() << std::endl;
	// std::cout << test2->longestSpan() << std::endl;
    //
	// delete test2;
    //
	// Span test3(3);
	// test3.addManyNumbers();
	// test3.printArr();
	// std::cout << test3.shortestSpan() << std::endl;
	// std::cout << test3.longestSpan() << std::endl;

	return (0);
}
