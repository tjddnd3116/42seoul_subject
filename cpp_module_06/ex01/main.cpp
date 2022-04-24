/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:24:30 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 15:02:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data._data = 42;
	Data *data2;

	data2 = deserialize(serialize(&data));

	std::cout << &data << std::endl;
	std::cout << data2 << std::endl;

	std::cout << data._data << std::endl;
	std::cout << data2->_data << std::endl;

	return (0);
}
