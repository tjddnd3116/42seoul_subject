/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:31:47 by soum              #+#    #+#             */
/*   Updated: 2022/03/12 18:19:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = -1;
	this->fullFilled = 0;
}

void	PhoneBook::add()
{
	this->index++;
	this->user[this->index].fillInfo();
	if (this->index == 7)
	{
		this->fullFilled = 1;
		this->index = -1;
	}
}
void	PhoneBook::search()
{
	if (this->index == -1 && this->fullFilled == 0)
	{
		std::cout << "empty Phonebook!" << std::endl;
		return ;
	}
	int index;
	std::cout << "Enter index : ";
	std::cin >> index;
	if (index <= 0)
		std::cout << "wrong index!" << std::endl;
	else if (this->fullFilled)
			this->user[index - 1].showInfo();
	else
	{
		if (index - 1 > this->index)
			std::cout << "wrong index!" << std::endl;
		else
			this->user[index - 1].showInfo();
	}
}
