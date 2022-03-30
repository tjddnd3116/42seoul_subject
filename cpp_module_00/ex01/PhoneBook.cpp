/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:31:47 by soum              #+#    #+#             */
/*   Updated: 2022/03/30 13:28:27 by soum             ###   ########.fr       */
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
	int idx;
	std::cout << "Enter index : ";
	std::cin >> idx;
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
