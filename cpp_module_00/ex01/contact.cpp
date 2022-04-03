/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:53:44 by soum              #+#    #+#             */
/*   Updated: 2022/04/03 21:31:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string contact::reSizeInfo(std::string field)
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
	contact tmp_usr;
	std::string tmp_field;
	std::string *field;


	while (1)
	{
		if (tmp_usr.first_name == "")
		{
			std::cout << "first_name :";
			field = &tmp_usr.first_name;
		}
		else if (tmp_usr.last_name == "")
		{
			std::cout << "last_name :";
			field = &tmp_usr.last_name;
		}
		else if (tmp_usr.nickname == "")
		{
			std::cout << "nickname :";
			field = &tmp_usr.nickname;
		}
		else if (tmp_usr.phone_number == "")
		{
			std::cout << "phone number :";
			field = &tmp_usr.phone_number;
		}
		else if (tmp_usr.darkest_secret == "")
		{
			std::cout << "darkest secret :";
			field = &tmp_usr.darkest_secret;
		}
		std::getline(std::cin, tmp_field);
		if (std::cin.eof())
			return ;
		if (tmp_field == "")
		{
			std::cout << "do not fill empty field" << std::endl;
			continue;
		}
		else
		{
			*field = tmp_field;
			if (field == &tmp_usr.darkest_secret)
			{
				*this = tmp_usr;
				break;
			}
		}
	}
}
void contact::showAllInfo()
{
	std::cout << "first name :" << first_name << std::endl;
	std::cout << "last name :" << last_name << std::endl;
	std::cout << "nickname :" << nickname << std::endl;
	std::cout << "phone number :" << phone_number << std::endl;
	std::cout << "darkest secret :" << darkest_secret << std::endl;
}

void contact::showInfo()
{
	std::cout << "|" << std::setw(10) << index << "|" <<
		std::setw(10) << reSizeInfo("first_name") << "|" <<
		std::setw(10) << reSizeInfo("last_name") << "|" <<
		std::setw(10) << reSizeInfo("nickname")  << "|" << std::endl;
}

void contact::setIndex(int index)
{
	this->index = index;
}
