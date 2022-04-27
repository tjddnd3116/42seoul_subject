/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:59:57 by soum              #+#    #+#             */
/*   Updated: 2022/04/27 18:40:20 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7
#define TYPE int
int main(int, char**)
{
	Array<TYPE> numbers(MAX_VAL);
	TYPE* mirror = new TYPE[MAX_VAL];
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const TYPE value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// for (int i = 0; i < MAX_VAL; i++)
	//     std::cout << numbers[i] << std::endl;
	// std::cout << "---------------------" << std::endl;
	// for (int i = 0; i < MAX_VAL; i++)
	//     std::cout << mirror[i] << std::endl;
	// std::cout << "---------------------" << std::endl;
	//SCOPE
	{
		// Array<TYPE> aaa;
		Array<TYPE> tmp = numbers;
		Array<TYPE> test(tmp);

		// aaa = numbers;
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << tmp[i] << std::endl;
		// std::cout << "---------------------" << std::endl;
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << test[i] << std::endl;
		// std::cout << "---------------------" << std::endl;
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << aaa[i] << std::endl;
		// std::cout << "---------------------" << std::endl;
		// for (int i = 0; i < MAX_VAL; i++)
		//     aaa[i] = std::rand();
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << numbers[i] << std::endl;
		// std::cout << "---------------------" << std::endl;
		// for (int i = 0; i < MAX_VAL; i++)
		//     std::cout << aaa[i] << std::endl;
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
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

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
