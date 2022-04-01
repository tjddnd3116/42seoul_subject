/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:43 by soum              #+#    #+#             */
/*   Updated: 2022/03/31 19:33:33 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phonebook;
	std::string cmd;

	std::cout << "PhoneBook is empty input Contact!" << std::endl;
	while (1) {
		std::cout << "1.ADD 2.SEARCH 3.EXIT" << std::endl;
		std::cout << ">";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
	}
	return (0);
}
