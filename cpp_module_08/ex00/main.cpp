/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:14:29 by soum              #+#    #+#             */
/*   Updated: 2022/04/27 20:31:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

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

	std::vector<int>::iterator it;

	try {
	it = easyfind(vec, 142);
	std::cout << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
