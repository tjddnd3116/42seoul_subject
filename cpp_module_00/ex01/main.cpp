/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:43 by soum              #+#    #+#             */
/*   Updated: 2022/02/14 13:30:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

int main(void) {
	PhoneBook list[8];
	for (int i = 0; i < 8; i++)
		list[i] = PhoneBook();
	std::string cmd;

	while (1) {
		int index;

		index = 0;
		std::cout << "1.ADD 2.SEARCH 3.EXIT" << std::endl;
		std::cout << ">";
		std::getline(std::cin, cmd);
		if (!cmd.compare("EXIT"))
			return (0);
		else if (!cmd.compare("ADD"))
		{
			list[index].add();
			index++;
		}
		else if (!cmd.compare("SEARCH"))
			list[index].search();
	}
	return (0);
}
