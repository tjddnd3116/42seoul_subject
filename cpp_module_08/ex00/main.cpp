/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:14:29 by soum              #+#    #+#             */
/*   Updated: 2022/05/01 13:37:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(42);


	// std::list<int> lst;
	// lst.push_back(1);
	// lst.push_back(3);
	// lst.push_back(12);
	// lst.push_back(42);
	// lst.push_back(111);

	std::vector<int>::iterator it;

	try {
	it = easyfind(vec, 42);
	std::cout << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// std::list<int>::iterator itr;
	// try {
	// itr = easyfind(lst, 42);
	// std::cout << *itr << std::endl;
	// } catch (std::exception& e) {
	//     std::cout << e.what() << std::endl;
	// }
	return (0);
}
