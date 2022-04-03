/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:31:47 by soum              #+#    #+#             */
/*   Updated: 2022/04/03 21:45:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: index(-1), fullFilled(0)
{}

void	PhoneBook::add()
{
	index++;
	user[index].fillInfo();
	user[index].setIndex(index + 1);
	if (index == 7)
	{
		fullFilled = 1;
		index = -1;
	}
}

void PhoneBook::searchIndex()
{
	int idx = 0;
	std::cout << "index : ";
	std::cin >> idx;
	std::cin.ignore(1024, '\n');
	if (std::cin.fail())
	{
		std::cout << "wrong index!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return ;
	}
	if (idx <= 0 || idx > 8)
		std::cout << "wrong index!" << std::endl;
	else
	{
		if (fullFilled)
			user[idx - 1].showAllInfo();
		else if (idx - 1 > index)
			std::cout << "wrong index!" << std::endl;
		else
			user[idx - 1].showAllInfo();
	}
}

void PhoneBook::searchAll()
{
	int idx;

	idx = 0;
	std::cout << "|" << std::setw(10) << "index" << "|" <<
		std::setw(10) << "first name" << "|" <<
		std::setw(10) << "last name" << "|" <<
		std::setw(10) << "nickname" << "|" << std::endl;
	while (fullFilled || idx < index + 1)
	{
		if (idx == 8)
			break;
		user[idx].showInfo();
		idx++;
	}
}

void	PhoneBook::search()
{
	if (this->index == -1 && fullFilled == 0)
	{
		std::cout << "empty Phonebook!" << std::endl;
		return ;
	}
	searchAll();
	searchIndex();
}
