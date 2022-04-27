/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:43 by soum              #+#    #+#             */
/*   Updated: 2022/04/27 17:07:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

int main(void) {
	PhoneBook phonebook;
	std::string cmd;

	while (1) {
		std::cout << "1.ADD 2.SEARCH 3.EXIT" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (0);
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		if (std::cin.eof())
			return (0);
	}
	return (0);
}
