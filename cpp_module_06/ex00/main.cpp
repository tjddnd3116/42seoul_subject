/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:53:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/21 16:02:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
		if (argc != 2)
		{
			std::cout << "check arg cnt! use ./convert [number to convert you want]" \
				<< std::endl;
			return (1);
		}
		try {
		Cast convert(argv[1]);
		std::cout << convert << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what();
		}
		return (0);
}
