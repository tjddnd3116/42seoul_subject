/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:53:44 by soum              #+#    #+#             */
/*   Updated: 2022/03/30 16:30:47 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iomanip>

int contact::index = 0;

void contact::reSizeInfo()
{
	if (first_name.size() > 10)
	{
		first_name = first_name.substr(0, 9);
		first_name = first_name.append(".");
	}
	if (last_name.size() > 10)
	{
		last_name = last_name.substr(0, 9);
		last_name = last_name.append(".");
	}
	if (nickname.size() > 10)
	{
		nickname = nickname.substr(0, 9);
		nickname = nickname.append(".");
	}
	if (phone_number.size() > 10)
	{
		phone_number = phone_number.substr(0, 9);
		phone_number = phone_number.append(".");
	}
	if (darkest_secret.size() > 10)
	{
		darkest_secret = darkest_secret.substr(0, 9);
		darkest_secret = darkest_secret.append(".");
	}

}

void contact::fillInfo()
{
	std::cout << "first name : ";
	std::cin >> this->first_name;
	std::cout << "last name : ";
	std::cin >> this->last_name;
	std::cout << "nick name : ";
	std::cin >> this->nickname;
	std::cout << "phone number : ";
	std::cin >> this->phone_number;
	std::cout << "darkest secret : ";
	std::cin >> this->darkest_secret;
}

void contact::showInfo()
{
	reSizeInfo();
	std::cout << std::setw(10) << "first name" << "|" <<\
		std::setw(10) << "last name" << "|" << \
		std::setw(10) << "nickname" << "|" << \
		std::setw(10) << "tel." << "|" << \
		std::setw(10) << "secret" << "|" << std::endl;
	std::cout << std::setw(10) << first_name << "|" <<\
		std::setw(10) << last_name << "|" << \
		std::setw(10) << nickname << "|" << \
		std::setw(10) << phone_number << "|" << \
		std::setw(10) << darkest_secret << "|" << std::endl;
}
