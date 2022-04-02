/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:53:44 by soum              #+#    #+#             */
/*   Updated: 2022/04/02 23:41:15 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string contact::resize_info(std::string field)
{
	std::string temp_field;

	if (field == "first_name")
		temp_field = first_name;
	if (field == "last_name")
		temp_field = last_name;
	if (field == "nickname")
		temp_field = nickname;
	if (temp_field.size() > 10)
	{
		temp_field = temp_field.substr(0, 9);
		temp_field = temp_field.append(".");
		return (temp_field);
	}
	else
		return (temp_field);
}

void contact::fillInfo()
{
	std::cout << "first name : ";
	std::cin >> first_name;
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::cout << "last name : ";
	std::cin >> last_name;
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::cout << "nick name : ";
	std::cin >> nickname;
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::cout << "phone number : ";
	std::cin >> phone_number;
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;
	std::cin.clear();
	std::cin.ignore(1024, '\n');
}

void contact::showAllInfo()
{

}

void contact::showInfo()
{
	std::cout << "|" << std::setw(10) << "index" << "|" <<
		std::setw(10) << "first name" << "|" <<
		std::setw(10) << "last name" << "|" <<
		std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "|" << std::setw(10) << index << "|" <<
		std::setw(10) << resize_info("first_name") << "|" <<
		std::setw(10) << resize_info("last_name") << "|" <<
		std::setw(10) << resize_info("nickname")  << "|" << std::endl;
}

void contact::set_index(int index)
{
	this->index = index;
}
