/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:53:44 by soum              #+#    #+#             */
/*   Updated: 2022/03/13 18:00:59 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.hpp"
#include <iomanip>

void info::reSizeInfo()
{
	if (this->first_name.size() > 10)
	{
		this->first_name = this->first_name.substr(0, 9);
		this->first_name = this->first_name.append(".");
	}
	if (this->last_name.size() > 10)
	{
		this->last_name = this->last_name.substr(0, 9);
		this->last_name = this->last_name.append(".");
	}
	if (this->nickname.size() > 10)
	{
		this->nickname = this->nickname.substr(0, 9);
		this->nickname = this->nickname.append(".");
	}
	if (this->phone_number.size() > 10)
	{
		this->phone_number = this->phone_number.substr(0, 9);
		this->phone_number = this->phone_number.append(".");
	}
	if (this->darkest_secret.size() > 10)
	{
		this->darkest_secret = this->darkest_secret.substr(0, 9);
		this->darkest_secret = this->darkest_secret.append(".");
	}

}

void info::fillInfo()
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

void info::showInfo()
{
	info::reSizeInfo();
	std::cout << std::setw(10) << "first name" << "|" <<\
		std::setw(10) << "last name" << "|" << \
		std::setw(10) << "nickname" << "|" << \
		std::setw(10) << "tel." << "|" << \
		std::setw(10) << "secret" << "|" << std::endl;
	std::cout << std::setw(10) << this->first_name << "|" <<\
		std::setw(10) << this->last_name << "|" << \
		std::setw(10) << this->nickname << "|" << \
		std::setw(10) << this->phone_number << "|" << \
		std::setw(10) << this->darkest_secret << "|" << std::endl;
}
