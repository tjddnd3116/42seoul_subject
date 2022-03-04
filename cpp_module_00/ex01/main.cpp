/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:43 by soum              #+#    #+#             */
/*   Updated: 2022/02/21 22:47:51 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

int main(void) {
	PhoneBook phonebook[8];
	for (int i = 0; i < 8; i++)
		phonebook[i] = PhoneBook();
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
			phonebook[index].add();
			index++;
		}
		else if (!cmd.compare("SEARCH"))
			phonebook[index].search();
	}
	return (0);
}
