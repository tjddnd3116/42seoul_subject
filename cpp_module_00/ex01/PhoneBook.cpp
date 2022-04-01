/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:31:47 by soum              #+#    #+#             */
/*   Updated: 2022/03/31 20:19:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = -1;
	fullFilled = 0;
}

void	PhoneBook::add()
{
	index++;
	user[index].set_index(index + 1);
	user[index].fillInfo();
	if (index == 7)
	{
		fullFilled = 1;
		index = -1;
	}
}
void	PhoneBook::search()
{
	if (this->index == -1 && fullFilled == 0)
	{
		std::cout << "empty Phonebook!" << std::endl;
		return ;
	}
	int idx = 0;
	std::cout << "index : ";
	std::cin >> idx;
	std::cin.ignore(INT_MAX, '\n');
	if (std::cin.fail())
	{
		std::cout << "wrong index!" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return ;
	}
	if (idx <= 0)
		std::cout << "wrong index!" << std::endl;
	else if (fullFilled)
			user[idx - 1].showInfo();
	else
	{
		if (idx - 1 > index)
			std::cout << "wrong index!" << std::endl;
		else
			user[idx - 1].showInfo();
	}
}
