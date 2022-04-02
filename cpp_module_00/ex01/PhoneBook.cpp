/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:31:47 by soum              #+#    #+#             */
/*   Updated: 2022/04/02 23:44:43 by soum             ###   ########.fr       */
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

void PhoneBook::search_index()
{
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
	if (idx <= 0 || idx > 8)
		std::cout << "wrong index!" << std::endl;
	else
	{
		if (fullFilled)
			user[idx - 1].showInfo();
		else if (idx - 1 > index)
			std::cout << "wrong index!" << std::endl;
		else
			user[idx - 1].showInfo();
	}
}

void PhoneBook::search_all()
{
	int idx;

	idx = 0;
	if (fullFilled)
	{
		while (idx < 8)
		{
			user[idx].showInfo();
			idx++;
		}
	}
	else
	{
		while (idx < index)
		{
			user[idx].showInfo();
			idx++;
		}
	}
}

void	PhoneBook::search()
{
	if (this->index == -1 && fullFilled == 0)
	{
		std::cout << "empty Phonebook!" << std::endl;
		return ;
	}
	search_all();
	search_index();
	}
