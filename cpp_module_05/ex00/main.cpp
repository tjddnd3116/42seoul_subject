/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:30 by soum              #+#    #+#             */
/*   Updated: 2022/04/23 13:03:35 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>


int main(void)
{
	Bureaucrat test1("test1", 50);

	std::cout << test1 << std::endl;
	test1.decrement(1);
	std::cout << test1 << std::endl;
	test1.decrement(1);
	std::cout << test1 << std::endl;

	Bureaucrat test2("test2", 0); // exception call grade be 1
	std::cout << test2 << std::endl;
	test2.increment(1); // exception call grade be 1
	std::cout << test2 << std::endl;
	test2.decrement(150); // exception call grade be 150
	std::cout << test2 << std::endl;

	Bureaucrat test3("test3", 151); // exception call grade be 150
	std::cout << test3 << std::endl;
	test3.increment(150); // exception call grade be 1
	std::cout << test3 << std::endl;
	test3.decrement(150); // exception call grade be 150
	std::cout << test3 << std::endl;

	return (0);
}
