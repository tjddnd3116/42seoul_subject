/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:53:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/23 22:13:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
		try {
			if (argc !=2)
				throw "check arg cnt! us ./convert [number to convert you want]";
			Cast test(argv[1]);
			std::cout << test << std::endl;
		} catch ( char const* err_msg) {
			std::cout << err_msg << std::endl;
			return (1);
		}catch (std::exception& e) {
			std::cout << e.what();
		}
		return (0);
}
