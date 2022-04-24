/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:59:57 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 22:06:48 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// for (int i = 0; i < MAX_VAL; i++)
	//     std::cout << numbers[i] << std::endl;
	// std::cout << "---------------------" << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << tmp[i] << std::endl;
		// std::cout << "---------------------" << std::endl;
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << test[i] << std::endl;
		// std::cout << "---------------------" << std::endl;
	}
	//
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	// try
	// {
	//     numbers[-2] = 0;
	// }
	// catch(const std::exception& e)
	// {
	//     std::cerr << e.what() << '\n';
	// }
	// try
	// {
	//     numbers[MAX_VAL] = 0;
	// }
	// catch(const std::exception& e)
	// {
	//     std::cerr << e.what() << '\n';
	// }

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	// for (int i = 0; i < MAX_VAL; i++)
	//     std::cout << numbers[i] << std::endl;
	// std::cout << "---------------------" << std::endl;
	delete [] mirror;//
    return 0;
}
